unsigned long int __MinToMiliSec(int inputValue)
{
  unsigned long int outputValue = inputValue * 60000;
  return outputValue;
}

String __MiliSecToTime(unsigned long int inputValue)
{
  unsigned long int totalOfSeconds = inputValue / 1000;

  int seconds = totalOfSeconds;
  int minutes = seconds / 60;
  int hours = minutes / 60;

  String secondsString;
  String minutesString;
  String hourString;

  if (seconds >= 60)
    seconds = (seconds - (60 * minutes));
  if (seconds < 10)
    secondsString = "0" + String(seconds);
  else
    secondsString = String(seconds);

  if (minutes >= 60)
    seconds = (minutes - (60 * hours));
  if (minutes < 10)
    minutesString = "0" + String(minutes);
  else
    minutesString = String(minutes);

  if (hours >= 60)
    hours = 100 * (hours - 60) / 60;
  if (hours < 10)
    hourString = "0" + String(hours);
  else
    hourString = String(hours);

  return hourString + ":" + minutesString + ":" + secondsString + " (" + totalOfSeconds + ")";
}

unsigned long int __HourToMiliSec(int inputValue)
{
  unsigned long int outputValue = inputValue * 3600000;
  return outputValue;
}

bool checkStructure()
{
  return (receivedData.pipeBegin == PIPE_BEGIN && receivedData.pipeEnd == PIPE_END) ? true : false;
}

unsigned long int __floatToInt(float inputValue)
{
  unsigned long int outputValue = inputValue * 100;
  return outputValue;
}

float __intToFloat(unsigned long int inputValue)
{
  float outputValue = inputValue / 100;
  return outputValue;
}