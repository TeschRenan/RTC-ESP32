# RTC-ESP32
Código fonte básico para utilizar o RTC do ESP32 no Arduino IDE, código fonte extraído do SDK da Espressif ESP-IDF.
Metodos:

  rtc_esp->UpdateRTCOffLine("20200428200000"); // Atualiza o struct do RTC para a data e hora desejada "Modo Offline"
  rtc_esp->GetTimeNTP();//Retorna String formatada do NTP;
  rtc_esp->GetTimeRTC(); //Retorna String formatada do RTC
  rtc_esp->GetUnixTimeRTC(); // Retorna String Unix time
