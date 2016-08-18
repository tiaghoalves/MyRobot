
# MyRobot
My First Library for Arduino Plataform. It is mean to be a whole Robot controller that uses the Arduino Plataform Hardware in general, for a while. This looks to improve the code writing, making it more faster, better and a little syntax simple by the way.
## Installation
As with all libraries, unzip the file into the 'libraries' folder in your Arduino directory, which will be in something like 'My Documents\Arduino' on Windows, 'Documents/Arduino' on Mac etc. If this is the first library you have installed, you will need to create a directory there called 'libraries'.
## Usage
  An previous exemple:
  <snippet>
	
	#include <MyRobot.h>
	MyRobot bot;
	
	int AnalogPins[4] = { 0, 1, 2, 3 };
	
	void setup() {
	  Serial.begin(9600);
	  
	  // Initializing basic some stuff:
	  bot.setupServo(10, 11);
	  bot.setupUltra(12, 13);
	  bot.setupAnalogSensors(AnalogPins, INPUT);
	}
	  
	void loop() {
	  // Using servos:
	  bot.goAhead();
	  delay(300);
	  bot.stopServo();
	
	  // Using Ultrassonic:
	  Serial.println( bot.getDistancia() );
	
	  // Using Analog Sensor:
	  Serial.println( bot.getAnalogRead(AnalogPins[0]) );
	}
  </snippet>
## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D

</snippet>
