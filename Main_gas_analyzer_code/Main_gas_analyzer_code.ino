//using the adafruit library which is a dependency for using the DHT sensor
#include <Adafruit_Sensor.h>

//sd card
#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;

//include the eeprom
#include <EEPROM.h>

int value_in_eeprom;

//include the liquid crystal library for the use of the liquid crystal display
#include <LiquidCrystal.h>

//include the DHT library for the use of the DHT display
#include "DHT.h"

// defining the pins at which the lcd is connected to the arduino
const int rs = 8, en = 9, d4 = 10, d5 = 2, d6 = 3, d7 = 5;

//setting the pins to the LCD for communication
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//define dht constants
#define DHTTYPE DHT11
#define DHTPIN A3

#define DC_GAIN 8.5

//intialize the dht sensor
DHT dht(DHTPIN, DHTTYPE);

//pins for the connection from the Mics 618 sensor
#define COPIN A0
#define NH3PIN A1
#define NO2PIN A2

//pins for the MG811 sensor
#define MG811PIN A4

//pins for the MQ138 sensor
#define MQ138PIN A5

//graphs for the MCISsensor (x, y, slope)
float CO2Curve[3] = {6000, 280, -0.006};
float NO2Curve[3] = {1, 0.2, 6.744};
float COCurve[3] = {0.1, 75, -0.013};
float NH3Curve[3] = {0.1, 70, -0.009};
float BenzeneCurve[3] = {6000, 0.6, -0.0004};


//required values for results
int temperature, humidity;
long co2=0;
float nh3 = 0;
float co = 0;
long benzene = 0;
float no2 = 0;

//initaial values of the resisstances
float init_co = 561.65;
float init_nh3 = 61.00;
float init_no2 = 217.40;
float init_mq381 = 82.70;
float init_mg811 = 248.00;


long timeCounter = 0;

bool fileReading = false;

int fileNumber = 0;
String fileName = "data_";
String currentFileName = "dataFile.csv";

//global file variable
File dataFile;

