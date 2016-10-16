#include "MyRobot.h"


MyRobot::MyRobot(){
}

/* SERVOS */
void MyRobot::servo(unsigned int esqPin, unsigned int dirPin){
  _esquerdo.attach(esqPin);
  _direito.attach(dirPin);
}
void MyRobot::stopServo(){
  _esquerdo.write(90);
  _direito.write(90);
}
void MyRobot::goAhead(){
  _esquerdo.write(0);
  _direito.write(180);
  _stateLeft = true;
  _stateRight = true;
}
void MyRobot::goBack(){
  _esquerdo.write(180);
  _direito.write(0);
  _stateLeft = false;
  _stateRight = false;
}
void MyRobot::goBackLeft(){
  _esquerdo.write(180);
  _stateLeft = false;
}
void MyRobot::goBackRight(){
  _direito.write(0);
  _stateRight = false;
}
void MyRobot::toggleLeft(){
  if(_stateLeft == true){
    _stateLeft == false;
    _esquerdo.write(180);
  } else {
    _stateLeft == true;
    _esquerdo.write(0);
  }
}
void MyRobot::toggleRight(){
  if(_stateRight == true){
    _stateRight == false;
    _direito.write(0);
  } else {
    _stateRight == true;
    _direito.write(180);
  }
}

/* SENSOR ANALOG */
void MyRobot::analogSensors(int pins[], uint8_t STATE){
  if (isValidAnalog(pins))
  {
    for (int i = 0; i < sizeof(pins); i++)
    {
      _AnalogPins[i] = pins[i];
      pinMode(pins[i], STATE);
    }
  }
}
int MyRobot::getAnalogRead(int pin){
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
void MyRobot::digitalSensors(int pins[], uint8_t STATE){
  if (isValidDigital(pins))
  {
    for (int i = 0; i < sizeof(pins); i++)
    {
      _DigitalPins[i] = pins[i];
      pinMode(pins[i], STATE);
    }
  }
}
int MyRobot::getDigitalRead(int pin){
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
void MyRobot::ultra(unsigned int TrigPin, unsigned int EchoPin){
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



bool MyRobot::isValidDigital(int pins[]){
  return (sizeof(pins) < MAX_DIGITAL_PINS) ? true : false;
}
bool MyRobot::isValidDigital(int pin){
  return (pin < MAX_DIGITAL_PINS) ? true : false;
}


bool MyRobot::isValidAnalog(int pins[]){
  return (sizeof(pins) < MAX_ANALOG_PINS) ? true : false;
}
bool MyRobot::isValidAnalog(int pin){
  return (pin < MAX_ANALOG_PINS) ? true : false;
}
