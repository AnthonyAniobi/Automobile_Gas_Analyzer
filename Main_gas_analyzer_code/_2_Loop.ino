void loop() {
  if(digitalRead(7)>0){
    
    //change the file name
    
    
    if(fileReading == false){
      newDataSetUpdate();
//      currentFileName = fileName + fileNumber + ".csv" ;
      openSdCard(currentFileName);
      lcd.setCursor(19, 3);
      lcd.print("R");
    }
    if(fileReading == true){
      lcd.setCursor(19,3);
      lcd.print("N");
      closeSdCard(currentFileName);
    }
    if(fileReading == true){
      fileReading = false;
    }else{
      fileReading = true;
    }
  }

  //updating the creen for the data
  if((millis()%2000) == 0){
    lcd.clear();
    updateScreen();
    LCDPrint();
    if(fileReading == true){
      writeToSdCard();
    }
  }
}
