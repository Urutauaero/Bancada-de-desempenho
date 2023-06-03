#include <Wire.h>
// #include "SDP6x.h"
#include "HX711.h"                       
#include <DHT.h>; 

#define DOUT  A1                      // HX711 DATA OUT = pino A0 do Arduino 
#define CLK   A0                      // HX711 SCK IN = pino A1 do Arduino e dht no A2

#define DHTPIN A2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

HX711 balanca;                        // define instancia balança HX711

float difPressure;
float vcas;
float densidade = 1.213;                  // Mudar em função do local
float massa;
float calibration_factor = 211020.00;     // Mudar em função do sensor
double temperatura;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  dht.begin(); 
  difPressure = 0.0;
  balanca.begin(DOUT, CLK);                          // inicializa a balança
  balanca.set_scale(calibration_factor);             // ajusta fator de calibração
  balanca.tare();                                    // zera a Balança
}

void loop(){
  Serial.println("Valores em fileira de: Balança, Temperatura, Pressão e Velocidade");
  temperatura = dht.readTemperature();  
  //Serial.print("VCAS (m/s): ");
  // difPressure = SDP6x.GetPressureDiff();
  vcas = 0;
    if (difPressure > 0){
      vcas = sqrt ((2.0 * difPressure) / densidade);
    }
 // Serial.print(vcas); 
   //Serial.print(";");
  //Serial.print("\n");
  //Serial.print("Massa (kg): ");
  Serial.print(balanca.get_units(), 3); Serial.print(";"); Serial.print(temperatura); //Serial.print(difPressure); Serial.print(vcas); 
  Serial.print("\n");    
  delay(500);
}