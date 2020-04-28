#ifndef RTC_H
#define RTC_H

#include <Arduino.h>
#include "time.h"
#include <esp_system.h>
#include <time.h>
#include <sys/time.h>


class RTC {
  const char* ntpServer = "a.st1.ntp.br";
  const long  gmtOffset_sec = -10800; //Para Brasil UTC -3.00: -3 * 60 * 60: -10800
  const int   daylightOffset_sec = 0; // 3600 para horario de verao acionado
  int second;
  int minute;
  int hour;
  int day;
  int month;
  int year;
  int weekday;
  struct tm timeinfo;
  struct tm data;//Cria a estrutura que contem as informacoes da data.
  char buf[14];
  int32_t UnixTime;
  bool FlagConectionNTP = false;
  public:
  RTC();
  void InitRTC();
  String GetTimeNTP();
  String GetTimeRTC(); 
  String GetUnixTimeRTC();
  bool UpdateRTC();
  void UpdateRTCOffLine(String);
};

#endif
