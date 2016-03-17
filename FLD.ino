
/*
  FLD datalogger code


  created: Feb 23 2016
  last mod: Mar 15 2016
  powellcm@gmail.com
  Rachel.Pleuthner@gmail.com

*/

//**********Globals, libs and includes************

#include <SPI.h>
#include <SD.h> //write to the uSD




const int chipSelect = 8; //pin 8 for the Sparkfun SD board
const int ardsn = 1;  //unique serial# for each logger (this needs improvement)
const int ledPin = 2; //pin to swtich the exciter lamp on
const int stablization = 5000;  //lamp stablization delay
const int warnPin = 6; //SD warning pin
boolean light;

const int reps = 50;
int dark[reps];
int fluoro[reps];
float statss[5];



//**************void setup*****************

void setup() {

  Serial.begin(9600);  // serial port for debug turn off in production maybe
  Serial.flush(); //dump anything stuck in the buffer
  pinMode(ledPin, OUTPUT); //setup ledpin for output
  pinMode(warnPin, OUTPUT); //setup warning pin for output

//____________SD Card__________________________________

  //oh shit the SD card is fucked
  if (!SD.begin(chipSelect)) {
    sd_warn();
  }

}


//**************void loop*******************

void loop() {

read_channel(dark,reps,1); 

//MUST write data before it is resorted via stats function!!!!!!!!!

stats(dark,reps,statss);
float dark_avg=statss[0];
float dark_stdd=statss[1];
float dark_min=statss[2];
float dark_max=statss[3];
float dark_median=statss[4];

//print it
Serial.print(dark_avg);
Serial.print(" ");
Serial.print(dark_stdd);
Serial.print(" ");
Serial.print(dark_min);
Serial.print(" ");
Serial.print(dark_max);
Serial.print(" ");
Serial.println(dark_median);


//delay(500);



}














