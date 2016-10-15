
# MyRobot

MyRobot é uma biblioteca para a Plataforma Arduino. A intenção é de ser um controlador completo de robô que usa a Plataforma Arduino Hardware em geral. Isto olha para melhorar a escrita de código, tornando-o mais rápido, fácil de usar e faz uso de uma sintaxe simples e legível, pois qualquer tipo de lógica que envolva o desenvolvimento do código estára sendo feita pela lib, desde calculos matemáticos necessário até movimentos de motores. O usúario precisará apenas se preocupar em realizar as ligações elétricas necessárias e corretamente feitas.

## Usage
  Um exemplo prévio:
  ```c++	
	#include <MyRobot.h>
	MyRobot bot;
	
	int AnalogPins[4] = { 0, 1, 2, 3 };
	
	void setup() {
	  Serial.begin(9600);
	  
	  // Inicia os sensores:
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
  ```

## Contribua
1. Dê Fork!
2. Crie um branch com a sua feature: `git checkout -b my-new-feature`
3. Versione suas alterações: `git commit -am 'Add some feature'`
4. Envie para o seu branch: `git push origin my-new-feature`
5. Faça um pull request =D
