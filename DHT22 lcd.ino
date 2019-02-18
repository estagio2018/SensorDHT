//---------- Bloco de define e inclusão de bibliotecas ----------------//
#include "DHT.h" //Biblioteca do DHT
#include <Wire.h> //Biblioteca do módulo I2C
#include <LiquidCrystal_I2C.h> //Biblioteca do LCD
 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // configurações do LCD
 
#define PINODHT 2     //Pino para comunicação com DHT
#define TIPODHT DHT22 //DHT22(AM2302/ AM2321)
 
DHT dht(PINODHT, TIPODHT);    //Configuraçãoes do DHT
 
// ------------- Inicialização de DHT e LCD ---------------------------//
void setup() {
  lcd.begin(16, 2); // inicializa o LCD
  lcd.setCursor(0, 0);
  lcd.print("Testando o sen-");
  lcd.setCursor(0, 1);
  lcd.print("sor de tempera-");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("tura e umidade");
  lcd.setCursor(0,1);
  lcd.print("DHT22!");
  delay(2500);
  lcd.clear();
  dht.begin(); //Inicializa o DHT
}
 
// ------------------- Lê e mostra informações -------------------- //
void loop() {
  delay(1000); //Espera um segundo para as informações aparecerem.
  //Ler a temperatura ou humidade leva cerca de 250 milisegundos!
  float h = dht.readHumidity();
  //Lê a temperatura em Celsius (padrão)
  float t = dht.readTemperature();
  // Checando se qualquer leitura falhou.
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 1);
    lcd.print("Falha ao ler");
    return;
  }
  lcd.setCursor(0, 0);
  lcd.print("Umid: ");
  lcd.setCursor(6, 0);
  lcd.print(h);
  lcd.setCursor(12, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.setCursor(6, 1);
  lcd.print(t);
  lcd.setCursor(12, 1);
  lcd.print("*C ");
}
