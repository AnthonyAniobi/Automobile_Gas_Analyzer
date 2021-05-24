void setup() {
  fileNumber = 0;
   lcd.begin(20,4);

   lcd.setCursor(0,0);
   lcd.print("initializing sd card");
   
   while(!SD.begin(chipSelect)){
    lcd.setCursor(0,0);
    lcd.print("failed initializing");
    delay(10000);
    return;
   }

   lcd.setCursor(0,0);
   lcd.print("Sd card sucessful");
   delay(1000);


   if(SD.remove(currentFileName)){
//    SD.remove(currentFileName)
   }


   
  //begin DHT sensor
  dht.begin();
//
//  lcd.setCursor(0,0);
//  lcd.print("  Welcome  ");
//  
//  lcd.setCursor(0, 2);
//  lcd.print("This device measures:");
//  lcd.setCursor(0, 3);
//  lcd.print(" 5 gases");
//  
//  delay(2000);
//
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print("Allow the senosrs");
//  lcd.setCursor(0,1);
//  lcd.print("Some time to ");
//  lcd.setCursor(0,2);
//  lcd.print("heat up");
//  delay(2000);
//
  lcd.clear(); 

  pinMode(7, INPUT);
}
