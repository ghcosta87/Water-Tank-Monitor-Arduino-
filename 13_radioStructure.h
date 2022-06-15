// → Radio setup
#include <SPI.h>
#include "RF24.h"

const byte addresses[][6] = {"pipe0", "pipe1", "pipe2", "pipe3", "pipe4", "pipe5"};
RF24 radio(9, 10);

struct structureToSend // estrutura de envio de dados
{
  byte pipeBegin = 153; 
  int analogPressure = 0;
  int pumpState = 0;
  bool flowFeedback=false;
  int fault = 0;
  unsigned int blank = 0;
  byte pipeEnd = 253; 
};

typedef struct structureToSend dataTypeOut;
dataTypeOut sendData;

struct structureToReceive
{
  byte pipeBegin = 0;
  bool circulationControl = false;
  bool pumpControl = false;
  byte pipeEnd = 0; 
};

typedef struct structureToReceive dataTypeIn;
dataTypeIn receivedData;

void radioSetup() {
  radio.begin(); 
  radio.openWritingPipe(addresses[2]);
  radio.openReadingPipe(1, addresses[1]);
}
