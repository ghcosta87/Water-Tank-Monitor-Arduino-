void plotData(String title, String stringData[], unsigned long int inputData[], String format[], int size)
{
  Serial.println("\n" + title + " size: " + (String)size);
  for (int i = 0; i < size; i++)
  {
    Serial.print(" " + stringData[i] + ": ");
    Serial.print(__intToFloat(inputData[i]));
    Serial.println(" " + format[i]);
    delay(500);
  }
  Serial.print("end of plot\n");
}