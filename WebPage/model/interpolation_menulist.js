/** Ebbe ker�l bele az oldalt l�v� men� kostans 2 oszloppal:
* az egyik oszlop rejtett tulajdons�got kap nem debug m�dban TODO
* 
*/
function interpolationMenulist (aConfig) {
    var that = this;
	var gTable = aConfig.table;
    var gCellButtonForm = {
        "type" :  "button",
    };
	var gFirstRowForm = {
        "type" :  "text",
        "disabled": "true"
    };
	gTable.addNewTableOneCell('hello', gFirstRowForm);
	gTable.addNewColumnToTable();

    return that;
}