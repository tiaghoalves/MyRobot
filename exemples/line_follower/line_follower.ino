#include <MyRobot.h>
#define BLACK_VALUE 600

MyRobot bot;
int AnalogPins[4] = { 0, 1, 2, 3 };
int value1;
int value2;
int value3;
int value4;

void setup() {
  Serial.begin(9600);  
  // Initializing basic some stuff:
  bot.setupServo(10, 11);
  bot.setupUltra(12, 13);
  bot.setupAnalogSensors(AnalogPins, INPUT);
}

void loop() {
  // Serial Prints call:
  prints();
  // Get Analog Reads:
  value1 = bot.getAnalogRead(AnalogPins[0]);
  value2 = bot.getAnalogRead(AnalogPins[1]);
  value3 = bot.getAnalogRead(AnalogPins[2]);
  value4 = bot.getAnalogRead(AnalogPins[3]);
  
  // Using Analog Sensor:
  if(value1 || value4 > BLACK_VALUE) bot.goBack(); else bot.goAhead();

  if(value2 || value3 > BLACK_VALUE) bot.goBack(); else bot.goAhead();

  if(bot.getDistancia() <= 15) bot.stopServo();
  
}

void prints(){
  Serial.print("Sensor 0: ");
  Serial.println( bot.getAnalogRead(AnalogPins[0]) );
  Serial.print("Sensor 1: ");
  Serial.println( bot.getAnalogRead(AnalogPins[1]) );
  Serial.print("Sensor 2: ");
  Serial.println( bot.getAnalogRead(AnalogPins[2]) );
  Serial.print("Sensor 3: ");
  Serial.println( bot.getAnalogRead(AnalogPins[3]) );
  Serial.print("Ultrassom: ");
  Serial.println( bot.getDistancia() );
  delay(300);
}

