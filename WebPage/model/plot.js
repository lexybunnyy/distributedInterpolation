/**
 * Created by lexy on 2014.04.28..
 */
function plot(aConfig) {
    var examples = example_datas();
    var addCord = aConfig.add_coords;
    var placeHolder = aConfig.placeholder;
    var tooltip = aConfig.tooltip;
    addCord.x.value = 0;
    addCord.y.value = 0;


    var showerArray = [];
    var plotFor = {
        begin: -3.5,//-1000,
        end: 3.5,//1000,
        step: 0.01//0.01
    };

    var result = generateForExamplePolinomes(examples.polinomesObject1, plotFor, aConfig.debugstring);
    //var result2 = make_plot_data(showerArray, examples.proj_res_data[1], 0, plotFor);

    result.push({
        label: 'points',
        data: [[0,0], [1,1], [-1,1],[-3,9],[3,9]],
        points: { show: true }
    });

    aConfig.debugstring.text(JSON.stringify(result));
    //var plot =
        $.plot(placeHolder, result, aConfig.typeofPH);

    placeHolder.bind("plothover", function (event, pos, item) {
        var str = "* (" + pos.x.toFixed(2) + ", " + pos.y.toFixed(2) + ") *";
        aConfig.hoverdata.text(str);

        if (item) {
            var x = item.datapoint[0].toFixed(2),
                y = item.datapoint[1].toFixed(2);

            tooltip.html(item.series.label + " of " + x + " = " + y)
                .css({top: item.pageY+5, left: item.pageX+5})
                .fadeIn(200);
        } else {
            tooltip.hide();
        }
    });

    placeHolder.bind("plotclick", function (event, pos, item) {
        //var str = "(" + pos.x.toFixed(2) + ", " + pos.y.toFixed(2) + ")";
        //clickdata.text(str);
        addCord.x.value = pos.x.toFixed(2);
        addCord.y.value = pos.y.toFixed(2);
    });

    addCord.button.onclick=function(){
        var str2 = "("+ addCord.x.value + ", " +  addCord.y.value + ")";
        aConfig.clickdata.text(str2);
        aConfig.debugstring.text(JSON.stringify(result));
    }
};