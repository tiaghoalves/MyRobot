#include "Arduino.h"
#include "MyRobot.h"
#include <Servo.h>

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

MyRobot::MyRobot(void){
}

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

void MyRobot::setupAnalogSensors(string State, int pins[]){
  if (pins.length() < MAX_ANALOG_PINS)
  {
    for (int i = 0; i < MAX_ANALOG_PINS; ++i)
    {
      string State = std::transform(State.begin(), State.end(), State.begin(), toupper);
      pinMode(pins[i], STATE);
    }
  }
}

void MyRobot::getAnalogRead(unsigned int esqPin, unsigned int dirPin){
  _esqValue = analogRead(esqPin);
  _dirValue = analogRead(dirPin);
}

void MyRobot::setupDigitalSensors(string State, int pins[]){
  if (pins.length() < MAX_DIGITAL_PINS){
    for (int i = 0; i < pins.length(); ++i)
    {
      string STATE = std::transform(State.begin(), State.end(), State.begin(), toupper);
      pinMode(pins[i], STATE);
    }
  }
}

void MyRobot::getDigitalRead(unsigned int esqPin, unsigned int dirPin){
  _esqValue = digitalRead(esqPin);
  _dirValue = digitalRead(dirPin);
}

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
  
  long _leitura_echo = pulseIn(_EchoPin, HIGH);
  return _distancia = _leitura_echo / 58;
}




