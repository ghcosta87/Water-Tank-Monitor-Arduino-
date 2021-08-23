// → BIBLIOTECAS
#include <SPI.h>
#include "RF24.h"

// → CONFIGURAÇÕES DO RÁDIO
byte addresses[][6] = {"pipe0", "pipe1", "pipe2", "pipe3", "pipe4", "pipe5"};
RF24 radio(9, 10);

struct estrutura_envioDadosRF // estrutura de envio de dados
{
  byte inicio = 153; //sinaliza inicio da estrutura (novo)
  int ai0 = 0;
  int status_bomba = 0; //0-OFF | 1-BOMBA MANUAL | 2-FILTRAGEM MANUAL | 3-FILTRAGEM AUTO
  bool feedback_vazao=false;
  int falha = 0;
  unsigned int porcentagem = 0;
  byte fim = 253; //sinaliza fim da estrutura (novo)
};

typedef struct estrutura_envioDadosRF tipoDadosout;
tipoDadosout out;

struct estrutura_recebidoDadosRF // estrutura de recebimento de dados
{
  byte inicio = 0; //sinaliza inicio da estrutura (novo)
  bool filtragem = false;
  bool bomba = false;
  byte fim = 0; //sinaliza fim da estrutura (novo)
};

typedef struct estrutura_recebidoDadosRF tipoDadosin;
tipoDadosin in;

void iniciar_radio() {
  radio.begin(); // inicia o radio NRF24L01
  radio.openWritingPipe(addresses[2]);
  radio.openReadingPipe(1, addresses[1]);
}
