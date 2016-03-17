//____________function to write datastring_______________

String dString (float data[], boolean led_status){
  
  String dataString = String(millis()); //add millis (change to datetime later)
  dataString += ", "; //make it comma seperated
  dataString += (ardsn); //add the SN
  dataString += ", "; //make it comma seperated

  
  //pop out individual array elements and write to the datastring
  for (int i = 0; i < 6; i++) {
    dataString += (data[i]);
    dataString += (", ");
    }
    dataString += (light); //write lamp status
    return dataString;
}
