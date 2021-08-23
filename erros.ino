void verificar_erros()
{
  //atribui valor a variavel pela função que verifica o nivel
  erro[0] = verificar_erro_d_nivel();
  //atribui valor a variavel pela função que verifica a vazão
  erro[1] = verificar_erro_d_vazao();

  //grava o tamanho do vetor erro
  int tamanho = sizeof(erro) / sizeof(int);
  //inicia o contador <i>
  int i = 0;

  /*
enquanto o contador for <= que o tamanho, verifica se o valor do
do vetor erro de indice "i" é verdadeiro, se for envia o erro para
estrutura <out.falha>
*/
  while (i <= tamanho)
  {
    if (erro[i])
    {
      if (erro[0])
        out.falha = 1; //baixo nivel
      if (erro[1])
        out.falha = 2; //filtro entupido - baixa vazao
      break;
    }
    i++;
  }

  /*
  se um dos erros for verdadeiros atua a parada de emergência, se não
  limpa a falha enviada em <out.falha>
  */
  if (erro[0] || erro[1])
  {
    parada_d_emergencia();
  }
  else
  {
    out.falha = 0;
  }
}

//se a altura for < que 2 liga o alarme, se for > que 10 desliga o alarme
bool verificar_erro_d_nivel()
{
  if (altura <= altura_min)
    return true;
  if (altura > altura_max)
    return false;
}

bool verificar_erro_d_vazao()
{
  /*
  se o iniciliaziador da vazão tiver ligado (iniciar_cron_vazao), 
  a filtragem estiver ativa e a vazão estiver fora, inicializa o tempo 
  inicial de baixa vaza e desliga o iniciliaziador da vazão
  */
  if (iniciar_cron_vazao && filtragem_ativa && !status_vazao)
  {
    tempo_baixa_vazao = millis();
    iniciar_cron_vazao = false;
  }
  /*
  se o cronometro de vazao for <true> e o inicializador da vazão estiver desligado
  verifica se a filtragem está ativa e o vazão foi identificada e retorna <true>
  se não retorna <false>
  */
  if (cronometro_vazao(tempo_baixa_vazao) && !iniciar_cron_vazao) //temporizados.ino
  {
    if (filtragem_ativa && status_vazao)
      return true;
  }
  return false;
}

//parada de emergencia: reinicia as saídas para estado inicial
void parada_d_emergencia()
{
  config_inicial(true);
}
