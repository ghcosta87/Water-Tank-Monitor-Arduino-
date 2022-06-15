void plotData(String title,String stringData[], float floatData[],String format[])
{
  int size = sizeof(floatData) / sizeof(float);
  Serial.println(title);
  for (int i; i < size; i++)
  {
    Serial.print(stringData[i] + ": ");
    Serial.print(floatData[i]);
    Serial.println(" "+format[i]);
  }  
  Serial.println("");
}

void serialInput(bool turnOn)
{
  if (turnOn)
    if (Serial.available())
    {
    }
}

/*
void filtrar_via_serial(bool serial_ligado)
{
  if (serial_ligado)
  {
    if (Serial.available())
    {
      char c = toupper(Serial.read());
      if (c == 'F' && filtragem_serial == false)
      {
        Serial.println(F("Filtragem Serial ON"));
        filtragem_serial = true;
      }
      else if (c == 'C' && filtragem_serial == true)
      {
        Serial.println(F("Filtragem Serial OFF"));
        filtragem_serial = false;
      }
    }
  }
}

void monitor_serial(bool serial_ligado, bool debug_ligado)
{
  if (serial_ligado)
  {
    contador++;
    //    if (contador > 10 || (in.inicio == 155 && in.fim == 255)) {
    if (in.inicio == 155 && in.fim == 255)
    {
      float tempo_total_d_filtragem = mili_p_hora(diferenca_d_tempo_filtragem());
      Serial.println("________________________________________________");
      Serial.println("| ");
      Serial.println("| Digite F para ligar a filtragem manualmente, ");
      Serial.println("| ou C para desligar a filtragem manual.");
      Serial.println("|===========VARIÁVEIS RECEBIDAS===========");
      Serial.print("| ");
      Serial.println("| Estrutura - sinc, filtr, bomba, ornam");
      Serial.print("| ");
      Serial.print(in.inicio);
      Serial.print("|");
      Serial.print(in.fim);
      Serial.print(" - ");
      Serial.print(in.filtragem);
      Serial.print(" - ");
      Serial.print(in.bomba);
      Serial.print("| Bomba modo automático: ");
      if (comando_bomba == false)
      {
        Serial.println("desligado");
      }
      else if (comando_bomba == true)
      {
        Serial.println("ligado");
      }
      Serial.print("| Comando de filtragem: ");
      if (filtragem == false)
      {
        Serial.println("desligado");
      }
      else if (filtragem == true)
      {
        Serial.println("ligado");
      }
      Serial.print("| Sinal de radio: ");
      if (in.inicio != 155 && in.fim != 255)
      {
        Serial.println("Sem sinal...");
      }
      else
      {
        Serial.println("Transmissão recebida !");
      }
      Serial.println("|===========VARIÁVEIS ENVIADAS============");
      Serial.println("| Estrutura:");
      Serial.print("| ");
      Serial.print(out.inicio);
      Serial.print("| ");
      Serial.print(out.ai0);
      Serial.print("| ");
      Serial.print(out.status_bomba);
      Serial.print("| ");
      Serial.print(out.feedback_vazao);
      Serial.print("| ");
      // Serial.print(out.status_filtragem);
      // Serial.print("| ");
      Serial.print(out.falha);
      Serial.print("| ");
      //      Serial.print(out.auto_fil);
      //     Serial.print("| ");
      Serial.print(out.porcentagem);
      Serial.print("| ");
      Serial.println(out.fim);
      Serial.print("| Valor da entrada analógica: ");
      Serial.println(out.ai0);
      Serial.print("| Estado da bomba: ");
      if (out.status_bomba == 1)
      {
        Serial.println("ligado");
      }
      else
      {
        Serial.println("desligado");
      }
      Serial.print("| Estado da filtragem: ");
      if (out.status_bomba == 2 || out.status_bomba == 3)
      {
        Serial.println("filtrando");
      }
      else
      {
        Serial.println("desligado");
      }
      Serial.print("| Estado da filtragem automática: ");
      if (filtragem_auto)
      {
        Serial.println("filtrando");
      }
      else
      {
        Serial.println("desligado");
      }
      Serial.println("|============VARIÁVEIS LOCAIS=============");
      /*Serial.println("| Qualidade de comunicação: ");
        Serial.print("| Sucesso: ");
        Serial.print(sucesso);
        Serial.print("| Falha: ");
        Serial.print(falha);
        Serial.print("| Porcentagem: ");
        Serial.print((float)out.porcentagem / 100);
        Serial.println(" %");*/
/*      Serial.print("| Altura da coluna d'água inicial/final: ");
      Serial.print(altura_ant);
      Serial.print("/");
      Serial.println(altura);
      Serial.println("| solenoide  bomba-manual  bomba-automático auto-filtragem");
      Serial.print("|  ");
      if (digitalRead(solenoide) == 0)
      {
        Serial.print("ligado");
      }
      else
      {
        Serial.print("desligado");
      }
      Serial.print("    ");
      if (digitalRead(bypass) == 0)
      {
        Serial.print("ligado");
      }
      else
      {
        Serial.print("desligado");
      }
      Serial.print("      ");
      if (digitalRead(bomba) == 0)
      {
        Serial.print("ligado");
      }
      else
      {
        Serial.print("desligado");
      }
      Serial.print("     ");
      if (filtragem_auto == true)
      {
        Serial.println("ligado");
      }
      else
      {
        Serial.println("desligado");
      }

      Serial.print("| Vazão : ");
      if (digitalRead(vazao) == false)
      {
        Serial.println("vazão detectada");
      }
      else
      {
        Serial.println("sem vazão");
      }
      Serial.print("| Estado de falha: ");
      if (out.falha)
        Serial.println("Falha no sistema");
      if (!out.falha)
        Serial.println("Sistema normal");
      Serial.print("| Tempo até o fim da filtragem: ");
      if (filtragem_auto == true)
      {
        Serial.print(tempo_d_filtragem - tempo_total_d_filtragem);
        Serial.println(" horas");
      }
      else
      {
        Serial.println("Aguardando filtragem automática");
      }
      Serial.println("|===========MOSTRADORES DE TEMPO==========");
      Serial.print("| Tempo atual de espera pra medir o nivel subindo: ");
      if (hab_comparar_altura)
      {
        Serial.print(mili_p_min(diferenca_d_tempo_comparar_altura()));
      }
      else
      {
        Serial.print("0");
      }

      Serial.println(" minuto (s)");
      Serial.print("| Tempo atual de filtragem automática: ");
      if (filtragem_auto)
      {
        Serial.print(tempo_total_d_filtragem);
      }
      else
      {
        Serial.print("0");
      }
      Serial.println(" horas");
      if (debug_ligado)
      {
        Serial.println("|=========== TROUBLESHOOTING ==========");
        Serial.print("|➲ verificar_nivel(): ");
        Serial.print(hab_valor_inicial);
        Serial.print("|");
        Serial.print(hab_comparar_altura);
        Serial.print("|");
        Serial.println(min_p_mili(tempo_p_iniciar));
        Serial.print("|➲ atuar_saidas(): ");
        Serial.println(out.falha);
        Serial.print("|➲ verificar_modo_pressurizador(): ");
        Serial.print(filtragem_ativa);
        Serial.print("|");
        Serial.println(comando_bomba);
        Serial.print("|➲ verificar_erros(): ");
        Serial.print(erro[0]);
        Serial.print("|");
        Serial.println(erro[1]);
        Serial.print("|➲ cronometro_comparar_altura(): ");
        Serial.print(cronometro_comparar_altura());
        Serial.print("|");
        Serial.print(diferenca_d_tempo_comparar_altura());
        Serial.print("|");
        Serial.print(min_p_mili(intervalo_medicao_d_altura));
        Serial.print("|");
        Serial.println(intervalo_d_medicao);
      }
      Serial.print("| ");
      Serial.println(versao);
      Serial.println("|__________________________________________");
      Serial.println("");
      contador = 0;
    }
    else if (contador > 15)
    {
      Serial.println("timeout...");
    }
    delay(10);
  }
}*/
