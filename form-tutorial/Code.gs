function doPost(data) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  var params = data.parameter;
  sheet.appendRow([params.field1, params.field2]);
  return ContentService.createTextOutput("201 Success");
}
