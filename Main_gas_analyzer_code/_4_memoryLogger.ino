void newDataSetUpdate(){
  ++fileNumber;
//  EEPROM.update(0,fileNumber);
}

void openSdCard(String fileName){
  dataFile = SD.open(fileName, FILE_WRITE);
  String name = "Dataset";
  name + fileNumber + ", , , , , , ";
  dataFile.println("D, , , , , , ");
  dataFile.println("Temperature, Humidity, Co, Co2, Nh3, No2, HC");
  lcd.clear();
  lcd.setCursor(0,0);
    lcd.print("Writing to:");
    lcd.setCursor(0,1);
    lcd.print(currentFileName);
    delay(1000);
    lcd.clear();
}

void writeToSdCard(){
  dataFile.print(temperature);
  dataFile.print(',');
  dataFile.print(humidity);
  dataFile.print(',');
  dataFile.print(co);
  dataFile.print(',');
  dataFile.print(co2);
  dataFile.print(',');
  dataFile.print(nh3);
  dataFile.print(',');
  dataFile.print(no2);
  dataFile.print(',');
  dataFile.println(benzene);
}

void closeSdCard(String fileName){
  dataFile.close();
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Closing");
    lcd.setCursor(0,1);
    lcd.print(currentFileName);
    delay(1000);
    lcd.clear();
}

