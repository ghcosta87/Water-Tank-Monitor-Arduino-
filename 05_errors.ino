void verifyErrors()
{
  bool error[] = {false, false};
  error[0] = checkWaterHeightError();
  error[1] = checkFlowError();

  if (error[0])
    sendData.fault = WATER_HEIGHT_ERROR;
  if (error[1])
    sendData.fault = FLOW_ERROR;
  if (error[0] && error[1])
    sendData.fault = FLOW_AND_HEIGHT_ERROR;
  if (sendData.fault > 0)
    emergencyStop = true;
}

bool checkWaterHeightError()
{
  if (waterHeight <= minWaterHeight)
    return true;
  if (waterHeight > normalWaterHeight)
    return false;
}

bool checkFlowError()
{
  /*
  se o iniciliaziador da vazão tiver ligado (iniciar_cron_vazao),
  a filtragem estiver ativa e a vazão estiver fora, inicializa o tempo
  inicial de baixa vaza e desliga o iniciliaziador da vazão
  */
  if (lowFlowCounterEnable && circulationActive && !flowStatus)
  {
    lowFlowInitialTime = millis();
    lowFlowCounterEnable = false;
  }
  /*
  se o cronometro de vazao for <true> e o inicializador da vazão estiver desligado
  verifica se a filtragem está ativa e o vazão foi identificada e retorna <true>
  se não retorna <false>
  */
  if (complexStopWatch(lowFlowInitialTime,__MinToMiliSec(lowFlowTimeLimit),HEIGHER_THAN) && !lowFlowCounterEnable)
  {
    if (circulationActive && flowStatus)
      return true;
  }
  return false;
}
