//  ➤ Atribuição de entrada e saída
const int bomba = 2;
const int bypass = 5;
const int solenoide = 4;
const int vazao = 7;
const int pressao = A0;

void iniciar_io()
{
  pinMode(A0, INPUT);         // sensor de pressão
  pinMode(bomba, OUTPUT);     // controle sinal da bomba
  pinMode(bypass, OUTPUT);    // controle sinal da
  pinMode(solenoide, OUTPUT); // controle sinal da solenoide
  pinMode(vazao, INPUT);      //sinal recebido do arduino que monitora a vazão
}

void config_inicial(bool atraso)
{
  if (atraso)
    delay(2000);
  digitalWrite(bypass, HIGH);
  if (atraso)
    delay(2000);
  digitalWrite(solenoide, HIGH);
  if (atraso)
    delay(2000);
  digitalWrite(bomba, HIGH);
}
