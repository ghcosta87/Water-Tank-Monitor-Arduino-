void ioBegin()
{
  pinMode(pressure, INPUT); // sensor de pressão
  pinMode(pump, OUTPUT);    // controle sinal da bomba
  pinMode(bypass, OUTPUT);  // controle sinal da
  pinMode(valve, OUTPUT);   // controle sinal da solenoide
  pinMode(flow, INPUT);     // sinal recebido do arduino que monitora a vazão
}

void ioSetup()
{
  digitalWrite(bypass, HIGH);
  digitalWrite(valve, HIGH);
  digitalWrite(pump, HIGH);
}

void serialSetup()
{
  Serial.begin(9600);
  Serial.println(version);
  softSerial.begin(4800);
}
