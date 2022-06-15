void receiveDataFromRF()
{
    long initialValue = millis();
    receivedData.pipeBegin = 0;
    receivedData.pipeEnd = 0;

    radio.startListening();
    while (!radio.available())
    {
        if (!complexStopWatch(initialValue, random(MIN_COMM_DURATION, MAX_COMM_DURATION), HEIGHER_THAN))
        {
            radio.read(&receivedData, sizeof(receivedData));
            break;
        }
    }
}

void recordDataFromRF()
{
    if (checkStructure())
    {
        pumpModeRemote = PUMP_OFF;
        if (receivedData.pumpControl)
            pumpModeRemote = MANUAL_ON;
        if (receivedData.circulationControl)
            pumpModeRemote = CIRCULATION_ON_MANUAL;
    }
}

void sendDataToRF()
{
    radio.stopListening();
    // atribui um valor ao tempo inicial
    long initialValue = millis();
    /*
    por um tempo determinado pelo cronometo escreve na saída do rádio
    a estrutura de enviar_dados
    */
    while (complexStopWatch(initialValue, random(MIN_COMM_DURATION, MAX_COMM_DURATION), LOWER_THAN))
    {
        !radio.write(&sendData, sizeof(sendData));
    }
}