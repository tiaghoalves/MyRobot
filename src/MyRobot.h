#ifndef MyRobot_h
#define MyRobot_h

#include "Arduino.h"
#include <Servo.h>
#include <inttypes.h>

#define MAX_ANALOG_PINS (6)
#define MAX_DIGITAL_PINS (14)

using namespace std;

class MyRobot {

public:
  MyRobot(void);

/*  SETUPS
  Servos: */
  void setupServo(unsigned int esqPin, unsigned int dirPin);
/* ANALOG: */
  void setupAnalogSensors(int pins[], uint8_t STATE);
/* DIGITAL: */
  void setupDigitalSensors(int pins[], uint8_t STATE);
/* ULTRASSOM: */
  void setupUltra(unsigned int TrigPin, unsigned int EchoPin);

/* ACTIONS */
  void stopServo();
  void goAhead();
  void goBack();
  unsigned int getDistancia();
  int getAnalogRead(unsigned int pin);
  int getDigitalRead(unsigned int pin);

private:
  Servo _esquerdo;
  Servo _direito;
  unsigned int _distancia;
  unsigned int _TrigPin;
  unsigned int _EchoPin;
  unsigned int _AnalogPins[MAX_ANALOG_PINS];
  unsigned int _DigitalPins[MAX_DIGITAL_PINS];

protected:
  bool isValidDigital(int pins[]);
  bool isValidDigital(int pin);
  bool isValidAnalog(int pins[]);
  bool isValidAnalog(int pin);

};

#endif