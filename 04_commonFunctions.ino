long int __MinToMiliSec(int inputValue)
{
  long int outputValue = inputValue * 60000;
  return outputValue;
}

long int __HourToMiliSec(int inputValue)
{
  long int outputValue = inputValue * 360000;
  return outputValue;
}

bool checkStructure()
{
  return (receivedData.pipeBegin == PIPE_BEGIN && receivedData.pipeEnd == PIPE_END) ? true : false;
}

float mili_p_min(long int entrada)
{
  float saida = entrada / 60000.00;
  return saida;
}

// função converte a entrada de horas para milisegundos

float mili_p_hora(long entrada)
{
  float saida = entrada / (float)360000;
  return saida;
}
