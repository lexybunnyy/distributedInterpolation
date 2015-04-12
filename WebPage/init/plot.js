//plot.js

$(function() {
	var plotActionView = {
		hoverdata : $("#span_hoverdata"),
		clickdata : $("#span_clickdata")
	};

	var plotDefaultSettings = {
		placeholder : $("#resultplot"),
		tooltip : $("#tooltip")
	};

	var plotGenerateSettings = {
		xaxis_min : Base.get('minx'),
		xaxis_max : Base.get('maxx'),
		yaxis_min : Base.get('miny'),
		yaxis_max : Base.get('maxy'),
        //TODO: pontosság!
		derivNum_max : Base.get('maxderivnum'),
		defaultType :  gTypePrepare
	};

	setInput = {
		x :  Base.get('input_coord_x'),
		y :  Base.get('input_coord_y')
	};

	interpPlot = interpolationPlot({
		plotGenerateSettings : plotGenerateSettings,
		plotDefaultSettings : plotDefaultSettings,
		plotActionView : plotActionView,
		setInput : setInput,
		hoverdata : $("#span_hoverdata"),
		clickdata : $("#span_clickdata")
	});
})