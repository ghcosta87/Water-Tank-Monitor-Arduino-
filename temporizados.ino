bool cronometro_vazao(long valor_inicial) {
  long tempo_corrido = millis() - valor_inicial;
  if (tempo_corrido > min_p_mili(alarmar_vazao))return true;
  return false;
}

void zerar_altura() {
  intervalo_d_medicao = millis();
  altura_ant = altura;
  hab_comparar_altura = true;
  hab_valor_inicial = false;
}

bool cronometro_comparar_altura() {
  //define o tempo inicial do cronometro
  long tempo_corrido = diferenca_d_tempo_comparar_altura();
  //se o tempo corrido for maior que o intervalo de medição retorna <true>
  if (tempo_corrido > min_p_mili(intervalo_medicao_d_altura)) {
    return true;
  }
  //se não retorna <false>
  return false;
}

bool cronometro_d_filtragem(bool start) {
  //se dado start marca o inicio do cronometro
  if (start)tempo_inicial_d_filtragem = millis();
  //marca o tempo corrido desde o início da fitlragem
  long tempo_corrido = diferenca_d_tempo_filtragem();
  /*
  se o tempo corrido for maior que o tempo do preset irá desligar a
  filtragem autmática, reiniciar a altura, e retornar <true>
  */
  if (tempo_corrido > hora_p_mili(tempo_d_filtragem)) {
    filtragem_auto = false;
    zerar_altura();
    return true;
  }
  //se não retorna <false>
  return false;
}

/*
retorna o valor da diferença do tempo de funcionamento
e o tempo em que altura foi comparada/zerada pela última vez
*/
long diferenca_d_tempo_comparar_altura() {
  long tempo_corrido = millis() - intervalo_d_medicao;
  return tempo_corrido;
}

/*
retorna o valor da diferença do tempo de funcionamento
e o tempo em que a filtragem começou pela última vez
*/
long diferenca_d_tempo_filtragem() {  
  long tempo_corrido = millis() - tempo_inicial_d_filtragem;
  return tempo_corrido;
}
