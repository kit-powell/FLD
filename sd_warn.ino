//____________sd_warn_____________________


void sd_warn () {

while(!SD.begin(chipSelect)){
  
   digitalWrite(warnPin, HIGH);
   delay(100);
   digitalWrite(warnPin, LOW);
   delay(100);     
   }
  
}
