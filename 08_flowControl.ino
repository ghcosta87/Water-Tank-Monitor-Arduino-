int getFlow()
{
    int outputValue = 0;
    String output = "";
    if (softSerial.available())
    {
        while (softSerial.available())
        {
            byte readByte = softSerial.read();
            char readChar = (char)readByte;
            output.concat(readChar);
        }
        int size = output.length();
        String numberFilter = "";
        for (int i = 0; i < size; i++)
        {
            if (output[i] == 'f')
                break;
            if (output[i] != 'i')
                numberFilter.concat(output[i]);
        }
        outputValue = numberFilter.toInt();
    }
    else
        outputValue = 0;
    return outputValue;
}

bool checkFlowStatus(){
    return false;
}