//********************************************************************************

//Bibliotecas 
#include <DHT.h>

// Configurando o Sensor no Pino 4
#define DHTPIN 4

// Configurando o tipo do sensor - DHTTYPE DHT22 ou DHTTYPE DHT11
#define DHTTYPE DHT22   // Sensor DHT 22  (AM2302)

// Comando - DHT nome_da_variavel(pino, tipo);
DHT dht(DHTPIN, DHTTYPE);

//********************************************************************************

// Funções que serão executadas quando o Arduino dor ligado
void setup() 
{
  // Inicia a comunicação Serial 
  Serial.begin(9600); 
  
  // Inicia a bibliotece DHT 
  dht.begin(); 
}

//********************************************************************************

// Funções que serão executadas quando continuamente
void loop() 
{

  // Leitura da umidade
  float h = dht.readHumidity();
  // Leitura da temperatura em graus Celsius
  float t = dht.readTemperature();

  // Mostra a umidade relativa do ar na serial
  Serial.print("Umidade: "); 
  Serial.print(h);
  Serial.println(" %");

  // Mostra a temperatura em graus Celsius na serial
  Serial.print("Temperatura: "); 
  Serial.print(t);
  Serial.println(" C  ");

  // conversão para fahrenheit
  // float f = (t*1.8)+32;
  //Serial.print("Temperatura: "); 
  //Serial.print(f);
  //Serial.println(" F  ");
  

  // conversão para kelvin
  // float k = (t+273);
  //Serial.print("Temperatura: "); 
  //Serial.print(k);
  //Serial.println(" K  ");
  
  // Aguarda 1 segundo
  delay(1000);
 }
