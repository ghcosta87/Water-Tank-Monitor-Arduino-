void receber_dados()
{
  //atribui o valor inicial do cronometro para receber dados
  long valor_inicial = millis();
  /*
  atribui valor inicia a variavel para controlar a atribuição ou
  não dos dados recebidos
  */
  bool teste = true;
  //zera as variaveis de controle de recebimento
  in.inicio = 0;
  in.fim = 0;
  //começa a ouvir a rádio
  radio.startListening();
  /*
  recebe os dados por um determinado tempo e atribui false a variavel de controle
  dos dados recebidos se não receber nada
  */
  while (!radio.available())
  {
    if (checar_cronometro(valor_inicial, random(400, 500), true)) //funcoes_aux
    {
      teste = false;
      break;
    }
  }

  //se tiver dados recebidos, eles são atribuidos a estrutura de entrada
  if (teste)
  {
    radio.read(&in, sizeof(in));
    //sucesso++;
  }
  //se não tiveram dados recebidos, é somada o número de falha
  //NÃO UTILIZADO
  //if (!teste)
  //falha++;
}

void enviar_dados()
{
  //para de ouvir o que está sendo transmitido para transmitir
  radio.stopListening();
  //atribui um valor ao tempo inicial
  long valor_inicial = millis();
  /*
  por um tempo determinado pelo cronometo escreve na saída do rádio
  a estrutura de enviar_dados
  */
  while (checar_cronometro(valor_inicial, random(400, 1200), false))
  {
    !radio.write(&out, sizeof(out));
  }
}

void atribuir_dados()
{
  //se a estrutura recebida for correta, atribui as variaveis recebidas
  if (checar_estrutura()) //funcoes_aux
  {
    comando_bomba = in.bomba;
    filtragem = in.filtragem;
  }
}
