//____________function to write uSD_______________

void writesd (String fname, String dstring){

File dataFile = SD.open(fname, FILE_WRITE);
  if (dataFile) {
    dataFile.println(dstring);
    dataFile.close();
    // print to the serial port too:
  }
  else {
    Serial.println("error opening file");
  } 
}

