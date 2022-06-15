/*
   erro[0] ➞ nivel baixo
   erro[1] ➞ vazao baixa
*/

/*
 //  ➤ Variáveis locais de recebimento de dados
1 - bool comando_bomba = false;
2 - bool filtragem = false; // comando interno INICIAL lig|desl filtragem_ativa

//  ➤ Variáveis para armazenar estado de erros
3,4 - bool erro[] = {false, false};
5 - bool nivel_baixo = false;
6 - bool baixa_vazao = false;

//  ➤ Variáveis de entradas locais
7 - int altura = 0;
8 - int altura_ant = 0; //variavel para gravar anltura do loop anterior
9 - int contador = 0; // número de loops até imprimir algo via serial
A - bool status_vazao = false;

//  ➤ Variáveis de temporizadores
//_______________________________________________________________________________
B - bool iniciar_cron_vazao = false; // liga e desliga contagem para alarmar vazao baixa
C - long tempo_baixa_vazao = 0; //armazena o tempo de inicio da falha

//  ➤ Variáveis de controle local da filtragem
D - bool filtragem_ativa = false; // comando interno FINAL de liga|desl filtragem
E - bool filtragem_auto = false; // comando interno INICIAL lig|desl automatico da filtragem_ativa
F - bool filtragem_serial = false; // comando interno INICIAL lig|desl automatico da filtragem_ativa
G - bool hab_comparar_altura = false; // habilita contar tempo para checar a diferença de altura da coluna d'água
H - bool hab_valor_inicial = true; // habilitar igualar altura/altura_ant somente no inicio
I - long intervalo_d_medicao = 0; // armazena intervalo de tempo para checar a diferença de altura da coluna d'água
J - long tempo_inicial_d_filtragem = 0; // armazena intervalo de tempo inicial para manter a filtragem em funcionamento
*/
