/*
compara o valor iniciado com o setpoint e para configuração <true> 
será > que o setpoing e <false> será < que o setpoint
*/
bool checar_cronometro(long valor_inicial, int setpoint, bool configuracao) {
  switch (configuracao) {
    case true:
      if ((millis() - valor_inicial) > setpoint) {
        return true;
      } else {
        return false;
      }
      break;
    case false:
      if ((millis() - valor_inicial) < setpoint) {
        return true;
      } else {
        return false;
      }
      break;
  }
}

//checa a estrutura recebida pelo rádio
bool checar_estrutura() {
  if (in.inicio == 155 && in.fim == 255)return true;
  if (in.inicio != 155 || in.fim != 255)return false;
}

//função converte a entrada de minutos para milisegundos
long int min_p_mili(int entrada) {
  long int saida = entrada * 60000;
  return saida;
}

float mili_p_min(long int entrada) {
  float saida = entrada / 60000.00;  
  return saida;
}

//função converte a entrada de horas para milisegundos
long int hora_p_mili(int entrada) {
  long int saida = entrada * 360000;
  return saida;
}

float mili_p_hora(long entrada) {
  float saida = entrada / (float)360000;
  return saida;
}
