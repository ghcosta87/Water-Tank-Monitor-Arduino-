//  ➤ Bibliotecas
#include "constantes.h"
#include "estrutura_radio.h"
#include "estrutura_io.h"
#include "estrutura_local.h"

void setup() {
  iniciar_io(); //estrutura_io.h
  config_inicial(false); //estrutura_io.h
  iniciar_serial(); //monitor_serial.ino
  iniciar_radio(); //estrutura_radio.h
}

void loop() {
  ler_entradas(); //controle_local.ino
  verificar_nivel(); //controle_local.ino
  receber_dados(); //radio_io.ino
  atribuir_dados(); //radio_io.ino
  verificar_erros(); //erros.ino
  atuar_saidas(); //controle_local.ino
  enviar_dados(); //radio_io.ino
  filtrar_via_serial(false); //[ lig|desl comando por serial]
  monitor_serial(true, false); //[ lig|desl monitor , lig|desl debug]
  delay(10);
}
