// global constants
var EMAIL_SENT = "EMAIL_SENT";
var TEST_NAME = "Exam 1"; // Update this variable to the exam name
var SUBJECT = "SUBJ 101 " + TEST_NAME + " Grade Report";
var TOTAL_POINTS = 100;

function sendGradeReport() {
  var sheet = SpreadsheetApp.getActiveSheet();
  var startRow = 2; // First row of data to process
  var numRows = 6; // Number of rows to process
  var dataRange = sheet.getRange(startRow, 1, numRows, 5);
  
  // Fetch values for each row in the Range.
  var data = dataRange.getValues();
  for (var i = 0; i < data.length; ++i) {
    var row = data[i];
    var emailSent = row[0];
    var emailAddress = row[1]; 
    var firstName = row[2];
    var lastName = row[3];
    var testScore = row[4]; 

    var message = ("Hi " + firstName + ",\n\n");
    message +=    ("Your " + TEST_NAME + " score is " + testScore + "/" + TOTAL_POINTS + ".\n\n");
    message +=    (TEST_NAME + " Mean: " + getMean(data) + "\n");
    message +=    (TEST_NAME + " Median: " + getMedian(data) + "\n");
    message +=    (TEST_NAME + " Standard Deviation: " + getStandardDeviation(data) + "\n\n");
    message +=    ("Best,\nProfessor Xavier\n");
    message +=    ("Email: hi@davidamante.com\n");
    message +=    ("Work Phone: 1-(555)-555-5555\n");
    if (emailSent != EMAIL_SENT) { // Prevents sending duplicates
      MailApp.sendEmail(emailAddress, SUBJECT, message);
      sheet.getRange(startRow + i, 1).setValue(EMAIL_SENT);
      
      // Make sure the cell is updated right away in case the script is interrupted
      SpreadsheetApp.flush();
    }
  }
}

function getMean(data) {
  var sumScores = 0;
  
  for (var i = 0; i < data.length; ++i) {
    sumScores += Number(data[i][4]);
  }
  
  return (sumScores / (data.length - 1)).toFixed(2);
}

function getMedian(data) {
  var median = 0;
  var middle = data.length / 2;

  data.sort()
  
  if (data.length % 2 == 0) {
    median = Number((data[middle][4] + data[middle - 1][4]) / 2);
  } else {
    median = Number(data[middle][4]);
  }

  return median.toFixed(2);
}

function getStandardDeviation(data) {
  var mu = getMean(data);
  var sumXiSOS = 0;  // sum of (x_i - mu)^2

  for (var i = 0; i < data.length; ++i) {
    sumXiSOS += Math.pow(Number(data[i][4]) - Number(mu), 2);
  }
  
  return Math.sqrt(sumXiSOS / data.length - 1).toFixed(2);
}
