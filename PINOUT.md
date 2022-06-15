/*
Projeto : Controlador sem fio
Autor : Gabriel H CMosta
Arduino: #1
Funcionamento:
Data primeira revisao: < 2020
Data da versão: 
Versão: 7 
*/

/*
--------------------------------------------------------------
  LIGAÇÃO NRF24L01
  LADO 1                            | LADO 2
                                    |
  GND  -> GND (LADO 2) & GND NRF    | GND -> GND (LADO 1)
  D7   -> CE                        | 5V  -> VCC NRF
  D8   -> CSN                       | D13 -> SCK
  D11  -> MO                        |
  D12  -> MI                        |
  --------------------------------------------------------------
  LIGAÇÃO ARDUINO
  A0 - FIO VERDE - SINAL DE PRESSÃO
  A2 -           - ARDUINO #3, LEITOR DE VAZÃO
  D9 - FIO LARANJA  - CE
  D10 - FIO ROXO - CSN
  D11 - FIO AZUL - MO
  D12 - FIO PRETO - MI
  D13 - FIO BRANCO  SCK
  --------------------------------------------------------------
*/
