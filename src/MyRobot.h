#ifndef MyRobot_h
#define MyRobot_h

#include "Arduino.h"
#include <Servo.h>
#include <inttypes.h>

#define MAX_ANALOG_PINS 6
#define MAX_DIGITAL_PINS 14

using namespace std;

class MyRobot {

public:
  MyRobot();

/*  SETUPS
  Servos: */
  void servos(unsigned int esqPin, unsigned int dirPin);
/* ANALOG: */
  void analogSensors(int pins[], uint8_t STATE);
/* DIGITAL: */
  void digitalSensors(int pins[], uint8_t STATE);
/* ULTRASSOM: */
  void ultra(unsigned int TrigPin, unsigned int EchoPin);

/* Metodos */
  void stopServo();
  void goAhead();
  void goBack();
  void goBackLeft();
  void goBackRight();
  void toggleRight();
  void toggleLeft();

  unsigned int getDistancia();
  
  int getAnalogRead(int pin);
  int getDigitalRead(int pin);
  

private:
// Servo
  Servo _esquerdo;
  Servo _direito;
  bool _stateLeft;
  bool _stateRight;

// Ultra
  unsigned int _distancia;
  unsigned int _TrigPin;
  unsigned int _EchoPin;

// Sensor
  unsigned int _AnalogPins[MAX_ANALOG_PINS];
  unsigned int _DigitalPins[MAX_DIGITAL_PINS];
  bool isValidDigital(int pins[]);
  bool isValidDigital(int pin);
  bool isValidAnalog(int pins[]);
  bool isValidAnalog(int pin);
  
};

#endif