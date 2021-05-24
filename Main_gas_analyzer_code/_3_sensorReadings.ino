int getTemperature(){
  return dht.readTemperature();
}

int getHumidity(){
  return dht.readHumidity();
}


double getCO2Percentage(float volts, float *curve){
    double x = ((volts) -curve[1]);
    double y = x/curve[2];
    double z = y+curve[0];
    return (z/90);
}

double getBenzenePercentage(float rs_ro_ratio, float *pcurve){
  double u = pow(10, rs_ro_ratio);
  double x = (u -pcurve[1]);
  double y = x/pcurve[2];
  double z = y+pcurve[0];
  return z;
}

double getMiCsPercentage(float ratio, float *pcurve){
  double u = log(ratio);
  double x = (u -pcurve[0]);
  double y = x*pcurve[2];
  double z = y+pcurve[1];
  return z;
}

double getMicsPercentage(float ratio, float *pcurve){
  double u = pow(10, ratio);
  double x = (u -pcurve[1]);
  double y = x/pcurve[2];
  double z = y+pcurve[0];
  return z;
}

void updateScreen(){
  temperature = getTemperature();
  humidity = getHumidity();

  float co2Voltage = getCO2Voltage();
  co2 = getCO2Percentage(co2Voltage, CO2Curve);
  benzene = getBenzenePercentage(((analogRead(A5)/10)/init_mq381), BenzeneCurve);
  no2 = getMiCsPercentage((analogRead(A2)/init_no2), NO2Curve);
  nh3 = getMiCsPercentage((analogRead(A1)/init_nh3), NH3Curve);
  co = log(getMicsPercentage((analogRead(A0)/init_co), COCurve));
}

void LCDPrint(){
   lcd.setCursor(0,0);
   lcd.print("T:");
   lcd.print(temperature); 
   lcd.setCursor(10,0);
   lcd.print("H:");
   lcd.print(humidity);
  
   lcd.setCursor(0,1);
   lcd.print("CO:");
   lcd.print(co); 
   lcd.setCursor(10,1);
   lcd.print("NH3:");
   lcd.print(nh3);
   
   lcd.setCursor(0,2);
   lcd.print("No2:");
   lcd.print(no2); 
   lcd.setCursor(10,2);
   lcd.print("Co2:");
   lcd.print(co2);

   lcd.setCursor(0,3);
   lcd.print("HC:");
   lcd.print(benzene); 

}

//convet this to file print
void SerialPrint(String id, float value){
  Serial.print(id);
  Serial.print(" : ");
  Serial.println(value);
}

//function to get the voltage from the analog pin
double getCO2Voltage(){
  double x = (analogRead(A4) * 5);
  double y = (x / 1.024);
  return (y/8.5);
}
