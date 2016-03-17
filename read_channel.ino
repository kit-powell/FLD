//function to populate a channel with reading from a given analog channel

void read_channel(int arr[], int reps, int channel)
{
 for (int i = 0; i < reps; i++) {
   arr[i] = analogRead(channel);
 }
}





///////////////////////////////////////////
/////commented standalone ino///////////////
//http://forum.arduino.cc/index.php?topic=40644.0
//by mellis Jun 25 2007, 10:00PM


//const int reps = 50;
//int dark[reps];
//
//////////////////////////////////
//
//void setup()
//{
//Serial.begin(9600);
//}
//
/////////////////////////////////////
//
//void loop()
//{
//incrementArray(dark, reps);
//Serial.println(dark[2]); //just show the third value
//}
//
////////////////////////////////////////
//
//void incrementArray(int arr[], int length)
//{
// for (int i = 0; i < length; i++) {
//   arr[i] = analogRead(A0);
// }
//}
