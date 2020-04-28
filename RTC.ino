#include "RTC.h"
#include <WiFi.h>

const char* ssid     = "ssid";
const char* password = "password";
//-----OBJETOS -----------------
RTC* rtc_esp;

String ValueNTP, ValueRTC, ValueUnix;

void setup()
{
  Serial.begin(115200);
  rtc_esp = new RTC();

  Serial.print("Conectando no Wifi  ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Conectado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  rtc_esp->InitRTC(); //Inicia o RTC
  
  String DataHora = "20200428200000"; // formato "%Y%m%d%H%M%S
  rtc_esp->UpdateRTCOffLine(DataHora); // Atualiza o struct do RTC para a data e hora desejada

  
  //rtc_esp->GetTimeNTP();//Retorna String formatada do NTP;
  //rtc_esp->GetTimeRTC(); //Retorna String formatada do RTC
  //rtc_esp->GetUnixTimeRTC(); // Retorna Unix time
  
}


void loop()
{
  
  yield();
  Serial.println();
  Serial.println("Valor do NTP");
  Serial.print(rtc_esp->GetTimeNTP());
  Serial.println();
  Serial.println("Valor do RTC");
  Serial.print(rtc_esp->GetTimeRTC());  
  Serial.println();
  Serial.println("Valor UnixTime");
  Serial.print(rtc_esp->GetUnixTimeRTC());  
  Serial.println();
  delay(10000);
}
