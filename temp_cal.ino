//___________function_SF_10kThermistor____________

float temp_cal(float bits_t){
  
  float a =3.354016E-3; //Steinhart-Hart Coefficients
  float b =2.569850E-4;
  float bc =0;
  float c =2.620131E-6;
  float cc =0;
  float d =6.383091E-8;
  float dc =0;
  float r2_t =10000; //10k fixed resis
  float rref=10000;

float v2_t = (bits_t*5.00)/1024.00; //voltage after thermisor
float i_t = v2_t/r2_t; //current through thermistor loop
float v1_t= 5.00-v2_t; //voltage dropped across thermistor
float r1_t = v1_t/i_t; //resistance of thermistor
float x = r1_t/rref;
bc=log(x);
cc=log(x)*log(x);
dc=log(x)*log(x)*log(x);
float tempk= 1/(a+b*bc+c*cc+d*dc); //Steinhart-Hart Eqn Need Coeff A, B, C
float tempc=tempk-273.15;
return tempc;
}
