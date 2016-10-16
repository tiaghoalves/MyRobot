
# MyRobot

MyRobot é uma biblioteca para a Plataforma Arduino. A intenção é de ser um controlador completo de robô que usa a Plataforma Arduino Hardware em geral. Isto olha para melhorar a escrita de código, tornando-o mais rápido, fácil de usar e faz uso de uma sintaxe simples e legível, pois qualquer tipo de lógica que envolva o desenvolvimento do código estára sendo feita pela lib, desde calculos matemáticos necessário até movimentos de motores. O usúario precisará apenas se preocupar em realizar as ligações elétricas necessárias e corretamente feitas.

## API
Aqui está listada todas as funções e funcionalidades que está lib disponibiliza ao usúario. Lembrando que todo o processo de desenvolvimento ainda está em andamento, portanto leve em conscideração qualquer outra atualização ou modificação que possa ocorrer na API.


### Servos
Para configurar os servos motores:
  
  ´´´c++  
void servos(unsigned int esqPin, unsigned int dirPin);
  ´´´

Passados dois pinos conectados aos servos.


### Sensores Analogicos
Para configurar os sensores analógicos:

  ´´´c++  
void analogSensors(int pins[], uint8_t STATE);
  ´´´

Passados um array de pinos e o estado de I/O(Entrada ou Saída) do sensor.


### Sensores Digital
Para configurar os sensores digitais:

  ´´´c++  
void digitalSensors(int pins[], uint8_t STATE);
  ´´´

### Ultrassom
Para configurar os sensores Ultrassonicos:

  ´´´c++  
void ultra(unsigned int TrigPin, unsigned int EchoPin);
  ´´´

Passados dois pinos conectados ao sensor ultrassonico.

## Metodos
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

## Usage
  Um exemplo prévio:
  ```c++	
#include <MyRobot.h>

MyRobot bot;

int AnalogPins[4] = { 0, 1, 2, 3 };

void setup() {
  Serial.begin(9600);
  
  // Initializing basic some stuff:
  bot.servo(10, 11);
  bot.ultra(12, 13);
  bot.analogSensors(AnalogPins, INPUT);
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
