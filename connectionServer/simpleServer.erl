%%http://stackoverflow.com/questions/2206933/how-to-write-a-simple-webserver-in-erlang
%%erl
%%c(simpleServer)
%%simpleServer:start(8082).
%%http://192.168.1.103:8086/prepare_page.html
%%http://192.168.1.103:8086/API
%%http://localhost:8086/prepare_page.html
%%http://localhost:8086/API

-module(simpleServer).
-export([start/1]).

start(Port) ->
    spawn(fun () -> {ok, Sock} = gen_tcp:listen(Port, [{active, false}]), 
                    loop(Sock) end).

loop(Sock) ->
    {ok, Conn} = gen_tcp:accept(Sock),
    Handler = spawn(fun () -> handle(Conn) end),
    gen_tcp:controlling_process(Conn, Handler),
    loop(Sock).

handle(Conn) ->
    {ok, Result} = do_recv(Conn, []),
    gen_tcp:send(Conn, response(Result)),
    gen_tcp:close(Conn).

response(Str) ->
    Test = erlang:decode_packet(http_bin, Str, []),
    Resp = getDecodeData(Test),
    RespJson = getResponseJSON(Resp),
    ResultJson = callMain(RespJson),
    io:format("response: ~p \n", [RespJson]),
    io:format("result: ~p \n", [ResultJson]),
    B = iolist_to_binary(RespJson),
    %%B = Str,
    iolist_to_binary(
      io_lib:fwrite(
         "HTTP/1.0 200 OK\nContent-Type: application/json\nContent-Length: ~p\n\n~s",
         [size(B), B])).

callMain(RespJson) -> 
    apply(main, callDistributedCaluclate, [RespJson]).

getResponseJSON(InitStr) ->
  case string:span(InitStr,"/?") > 1 of
    true -> string:substr(http_uri:decode(InitStr), 3);
    _ -> "{\"success\": \"false\", \"error:\": \"Invalid Things\"}"
  end.

getDecodeData({ok, {http_request,'GET', {abs_path, Result }, _Length} , _Rest}) -> binary_to_list(Result);
getDecodeData(_) -> error.

%%http://erlang.org/doc/man/gen_tcp.html
client() ->
    SomeHostInNet = "localhost", % to make it runnable on one machine
    {ok, Sock} = gen_tcp:connect(SomeHostInNet, 5678, 
                                 [binary, {packet, 0}]),
    ok = gen_tcp:send(Sock, "Some Data"),
    ok = gen_tcp:close(Sock).

server() ->
    {ok, LSock} = gen_tcp:listen(5678, [binary, {packet, 0}, 
                                        {active, false}]),
    {ok, Sock} = gen_tcp:accept(LSock),
    {ok, Bin} = do_recv(Sock, []),
    ok = gen_tcp:close(Sock),
    Bin.

do_recv(Sock, Bs) ->
    case gen_tcp:recv(Sock, 0) of
        {ok, B} ->
            {ok, list_to_binary(B)};
        {error, closed} ->
            {ok, list_to_binary(Bs)}
    end.