#include "Arduino.h"
#include "MyRobot.h"
#include <Servo.h>

using namespace std;

MyRobot::MyRobot(void){
}

/* SERVOS */
void MyRobot::setupServo(unsigned int esqPin, unsigned int dirPin){
  _esquerdo.attach(esqPin);
  _direito.attach(dirPin);
}
void MyRobot::stop(void){
  _esquerdo.write(90);
  _direito.write(90);
}
void MyRobot::goAhead(){
  _esquerdo.write(0);
  _direito.write(180);
}
void MyRobot::goBack(){
  _esquerdo.write(180);
  _direito.write(0);
}

/* SENSOR ANALOG */
void MyRobot::setupAnalogSensors(uint8_t STATE, int pins[]){
  if (isValidAnalog(pins))
  {
    for (int i = 0; i < sizeof(pins); i++)
    {
      _AnalogPins[i] = pins[i];
      pinMode(pins[i], STATE);
    }
  }
}
int MyRobot::getAnalogRead(unsigned int pin){
  if (isValidAnalog(pin))
  {
    for (int i = 0; i < sizeof(_AnalogPins); i++)
    {
      if (i == pin)
      {
        return analogRead(pin);
      }
    }
  }
}

/* SENSOR DIGITAL */
void MyRobot::setupDigitalSensors(uint8_t STATE, int pins[]){
  if (isValidDigital(pins))
  {
    for (int i = 0; i < sizeof(pins); i++)
    {
      _DigitalPins[i] = pins[i];
      pinMode(pins[i], STATE);
    }
  }
}
int MyRobot::getDigitalRead(unsigned int pin){
  if (isValidDigital(pin))
  {
    for (int i = 0; i < sizeof(_DigitalPins); i++)
    {
      if (i == pin)
      {
        return digitalRead(pin);
      }
    }
  }
}

/* ULTRASSOM */
void MyRobot::setupUltra(unsigned int TrigPin, unsigned int EchoPin){
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  _TrigPin = TrigPin;
  _EchoPin = EchoPin;
}
unsigned int MyRobot::getDistancia(){
  delayMicroseconds(2);
  digitalWrite(_TrigPin, HIGH);
  delayMicroseconds(13);
  digitalWrite(_TrigPin, LOW);
  delayMicroseconds(2);
  
  long leitura_echo = pulseIn(_EchoPin, HIGH);
  _distancia = leitura_echo / 58;
  return _distancia;
}

bool isValidDigital(int pins[]){
  return (sizeof(pins) < MAX_DIGITAL_PINS) ? true : false;
}
bool isValidDigital(int pin){
  return (pin < MAX_DIGITAL_PINS) ? true : false;
}

bool isValidAnalog(int pins[]){
  return (sizeof(pins) < MAX_ANALOG_PINS) ? true : false;
}
bool isValidAnalog(int pin){
  return (pin < MAX_ANALOG_PINS) ? true : false;
}

