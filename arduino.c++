#include <LiquidCrystal.h>

#define pGas A5
#define pPir 7
#define pTemp A4

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // número de colunas e linhas do LCD
  lcd.begin(16, 2);
  // Imprimir mensagem no LCD
  lcd.print("Monitoramento: ");
  pinMode(pPir,INPUT); //entrada de dados
}

void loop() {
  //leitura sensor gas
  int sinalGas=analogRead(pGas); //recebe a leitura analógica
  sinalGas=map(sinalGas,300,750,0,100); //reescrever, redirecionar o valor
  limpa_tela();
  lcd.print("GAS: ");
  lcd.print(sinalGas);
  
  //Leitura de presenca
  limpa_tela();
  lcd.print("Estado: ");  //imprimir
  presenca();
  
  //Leitura temperatura
  limpa_tela();
  lcd.print("Temp: ");    //imprimir
  temperatura();
  
  //led rbg e vermelho
  
  delay(100);
  
}

void limpa_tela(){
 delay(1500);
 lcd.setCursor(0,1);              //limpar a tela e alternar entre os monitoramentos
 lcd.print("                ");
 lcd.setCursor(0,1); 
}
 
void presenca(){
  int sinalPir=digitalRead(pPir);  //vai receber os dados
  if(sinalPir==1)
    lcd.print("Em uso");
  else
    lcd.print("Vazio");
}

void temperatura(){
  float sinalTemp=analogRead(pTemp)*5; //conversor milivolts para celcius
  float TempC=((sinalTemp/1023)-0.5)*100;
  lcd.print(TempC);
}