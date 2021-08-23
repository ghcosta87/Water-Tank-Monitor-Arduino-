void ler_entradas()
{
  //atribui a altura da coluna d'água
  altura = map(analogRead(pressao), 40, 87, 0, 49);
  //atribui o estado da vazão
  status_vazao = !digitalRead(vazao);
  //atribui o valor da pressão da coluna d'água
  out.ai0 = analogRead(pressao);
  //filtragem não ativa e sem comando da bomba envia 0
  if (!filtragem_ativa && !comando_bomba)
    out.status_bomba = 0;
  //filtragem não ativa e com comando da bomba envia 1
  if (!filtragem_ativa && comando_bomba)
    out.status_bomba = 1;
  //auto filtragem não ativa e filtragem ativa envia 2
  if (!filtragem_auto && filtragem_ativa)
    out.status_bomba = 2;
  //auto filtragem ativa envia 3
  if (filtragem_auto)
    out.status_bomba = 3;
  //envia o estado da vazão
  out.feedback_vazao = status_vazao;
}

void verificar_nivel()
{ /*
se o cronometro estiver habilitado (hab_valor_inicial) e 
o tempo decorrido for maior que o preset de inicialização
(tempo_p_iniciar) e a altura for diferente de 0, a altura será zerada
*/
  if (hab_valor_inicial && (millis() > min_p_mili(tempo_p_iniciar)) && altura != 0)
    zerar_altura();
  /*
    se a comparação de altura estiver habilitada (hab_comparar_altura) 
    e chegar a hora de medir a altura (cronometro_comparar_altura()), é 
    chamada a função pra comprar a altura atual com a anterior    
    OBS.: hab_comparar_altura valor inicial é <true>
    */
  if (hab_comparar_altura && cronometro_comparar_altura())
    comparar_altura();
}

//se não houver falhas habilita as saídas
void atuar_saidas()
{
  if (!out.falha)
  {
    verificar_modo_filtragem();
    verificar_modo_pressurizador();
  }
}

void verificar_modo_filtragem()
{
  /*
  se os comandos de filtragem e a filtragem automática e a filtragem serial não
  estiverem ativas, desliga a filtragem
  */
  if (!filtragem && !filtragem_auto && !filtragem_serial)
    filtragem_ativa = false;
  /*
    se os comandos de filtragem e a filtragem automática e a filtragem serial 
    estiverem ativas, liga a filtragem a filtragem
  */
  if (filtragem || filtragem_auto || filtragem_serial)
    filtragem_ativa = true;
  /*
  se a filtragem estiver ligada, atua as saídas da solenoide e da bomba
  até que o cronometro de filtragem retorne <false>, que irá desativar a filtragem ativa,
  caso a filtragem estiver desligada, desliga as saídas da bomba e da solenoide
  */
  if (filtragem_ativa)
  {
    digitalWrite(solenoide, LOW); //on
    digitalWrite(bypass, LOW);    //on
    if (cronometro_d_filtragem(false))
      filtragem_ativa = false;
  }
  else
  {
    digitalWrite(solenoide, HIGH); //off
    digitalWrite(bypass, HIGH);    //off
  }
}

void verificar_modo_pressurizador()
{
  /*
  se a filtragem estiver desligada e receber o comando para ligar a pressurizador,
  atua a saída da pressurizador, caso contrário, desliga a saída do pressurizador
  */
  if (!filtragem_ativa && comando_bomba)
    digitalWrite(bomba, LOW); //on
  if (filtragem_ativa || !comando_bomba)
    digitalWrite(bomba, HIGH);//off
}

void comparar_altura()
{
  /*
  se a altura atual for maior que a anterior + o setpoint
  irá ligar a filtragem automatica, desabilitar a comparação de altura
  e iniciar o cronometro de filtragem
  */
  if (altura > altura_ant + acrescimo_d_altura)
  {
    filtragem_auto = true;
    hab_comparar_altura = false;
    cronometro_d_filtragem(true);
  }
  //caso contrario reinicia cronometro para comparar novamente
  else
  {
    hab_valor_inicial = true;
  }
}
