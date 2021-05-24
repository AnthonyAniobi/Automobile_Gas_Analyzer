#include <LiquidCrystal.h>

//code to initialize the Ro for all sensors

#define CO2_PIN = 0;
#define C0_PIN = 1; 
#define HCARBON_PIN = 2;
#define NH4_PIN = 3;
#define N02_PIN = 4;

#define CO2_RESISTOR = 10000;
#define C0_RESISTOR = 10000; 
#define HCARBON_RESISTOR = 10000;
#define NH4_RESISTOR = 10000;
#define N02_RESISTOR = 10000;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int C02_AMBIENT, C0_AMBIENT, HYDROCARBON_AMBIENT, AMONIA_AMBIENT, N02_AMBIENT;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

  lcd.setCursor(0,0);
  lcd.print("initialize");

  delay (1000);

  lcd.print("Please Wait");
  lcd.setCursor(0,1);
  lcd.print("Heating");

  timer = HEAT_TIME * 20 * 60;
  lcd.clear();

  startHeating(20) //set the heating time in minutes

  setInitialValues() //print the initial values
}

void loop() {
}


void startHeating(int heat_time){
  int mins = heat_time;
  int secs = 0;
  
  lcd.setCursor(0,0);
  lcd.print("heater count down");
  while(true){
    String countdown = mins+" : "+secs;
    lcd.setCursor(0,1);
    lcd.print(countdown)
    delay(1000);

    secs --;

    if(secs < 0){
      secs = 59;
      mins--;
    }
    if(mins < 0){
      mins = 0;
      secs = 0;
      break;
    }
  }
  lcd.clear();
  lcd.print("heating complete!!");
}

void setInitialValues(){
  delay(500);
  lcd.clear();
  lcd.print("Getting data....");
  lcd.setCursor(0,2);
  lcd.blink();

  int co=0, co2=0, hcarbon=0, nh4=0, no2=0;
  for(int i =0; i < 20; i++){
     co+=analogRead(C0_PIN);
     co2+=analogRead(CO2_PIN);
     hcarbon+=analogRead(HCARBON_PIN);
     nh4+=analogRead(NH4_PIN);
     no2+=analogRead(NO2_PIN);

     delay(100);
  }

  co/20;
  co2/20;
  hcarbon/20;
  nh4/20;
  no2/20;

  //USE VOLTAGE DIVIDER HERE TO GET THE VALUE OF THE RESISTOR
  //the function to get the value is written below,
  //just imput their value, together with their input reistance values
}

float getResitance(float analogueValue, float fixedResistor){
  return (fixedResistor *((1023-analogueValue)/analogueValue));
}

