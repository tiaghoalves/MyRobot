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
  MyRobot(void);

/*  SETUPS
  Servos: */
  void setupServo(unsigned int esqPin, unsigned int dirPin);
/* ANALOG: */
  void setupAnalogSensors(const int pins[], uint8_t STATE);
/* DIGITAL: */
  void setupDigitalSensors(const int pins[], uint8_t STATE);
/* ULTRASSOM: */
  void setupUltra(unsigned int TrigPin, unsigned int EchoPin);

/* ACTIONS */
  void stopServo();
  void goAhead();
  void goBack();
  void goBackLeft();
  void goBackRight();
  void toggleRight();
  void toggleLeft();
  unsigned int getDistancia();
  int getAnalogRead(unsigned int pin);
  int getDigitalRead(unsigned int pin);
  
  bool isValidDigital(const int pins[]);
  bool isValidDigital(const int pin);
  bool isValidAnalog(const int pins[]);
  bool isValidAnalog(const int pin);

private:
  Servo _esquerdo;
  Servo _direito;
  bool _stateServoLeft;
  bool _stateServoRight;
  unsigned int _distancia;
  unsigned int _TrigPin;
  unsigned int _EchoPin;
  unsigned int _AnalogPins[MAX_ANALOG_PINS];
  unsigned int _DigitalPins[MAX_DIGITAL_PINS];
  
};

#endif