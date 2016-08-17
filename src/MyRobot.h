#ifndef MyRobot_h
#define MyRobot_h

#include <string.h>
#include "Arduino.h"
#include <Servo.h>

#define MAX_ANALOG_PINS (6);
#define MAX_DIGITAL_PINS (14);

using namespace std;

class MyRobot {
  
public:
  MyRobot(void);
/*  SETUPS: */
// Servos:
  void setupServo(unsigned int esqPin, unsigned int dirPin);
// ANALOG:
  void setupAnalogSensors(string State, int Pins[]);
//void setupAnalogSensors(unsigned int esqPin, unsigned int dirPin);
/* DIGITAL: */
  void setupDigitalSensors(string State, int Pins[]);
//void setupDigitalSensors(unsigned int esqPin, unsigned int dirPin);

// Ultra:
  void setupUltra(unsigned int TrigPin, unsigned int EchoPin);

/* ACTIONS: */
  void stop();
  void goAhead();
  void goBack();
  int getAnalogRead(unsigned int esqPin, unsigned int dirPin);
  int getDigitalRead(unsigned int esqPin, unsigned int dirPin);
  unsigned int getDistancia();

private:
  Servo _esquerdo;
  Servo _direito;
  unsigned int _distancia;
  unsigned int _esqValue;
  unsigned int _dirValue;
  unsigned int _TrigPin;
  unsigned int _EchoPin;

};

#endif