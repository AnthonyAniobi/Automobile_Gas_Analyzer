This is a arduino based automobile gas analyzer
The system measures gases such as:
Co
Co2
Benzene
No2
Nh3

The temperature and humidity of the sytem is also measured

The sensors used for the system are:
DHT11
mq138
mg811
mics681

The data gotten from each of the sensors are stored in a memory card

The functioning process of the gas analyzer is as follows:

When the system is turned on, the code checks if the sdcard is properly initialized once this is sucessful, the sensors are given a 10minutes time to heatup so as to enable the sensors to operate accurately. This delay process can be skipped by pressing the control button and this immediately moves the user to the sensor display screen. This is a screen on the LCD where the values for all the sensors are displayed. 
During this process, data is not stored in the sd card. The storage can be started by pressing the button on the button. This starts up the data logging on the sd card and the user is shown a message (on the lcd) alerting him/her that the data is now storing in the card. After this the user is returned to the sensor display screen.
Now the letter 'R' is written on the buttom right corner of the LCD this is to inform the user that the data is currently logging in the sd card.
Pressing the button again turns of the data logging and tells the user that the data logging has been stopped. The user is again led back to the sensor display screen and the 'R' at the buttom right of the screen disappears.


NOTE: The 'get_initial_sensor_values' code is used to get default values of the sensor. This reading should be taken at conditions of 'CLEAN AIR' this can be taken just outside and this would serve as the standard environmental contion for calibrating the 'Main_gas_analyzer_code'. This values are put in the 'Main_gas_analyzer_code' under the intializing section