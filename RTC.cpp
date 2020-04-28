#include "RTC.h"

RTC::RTC() {

}

void RTC::InitRTC(){
   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 if(!getLocalTime(&timeinfo)){
    Serial.println("Falha ao obter o horario");
    FlagConectionNTP = false;
    //return;
  }
    timeval tv;//Cria a estrutura temporaria para funcao abaixo.
    time_t now;
    now = now - 10800;
    time(&now);
    FlagConectionNTP = true;
}

String RTC::GetTimeNTP(){
  if (this->FlagConectionNTP == false){
    this->InitRTC();
  }
  if (this->FlagConectionNTP == false){
    return "Erro ao iniciar parametros ao NTP";
  }
  if(!getLocalTime(&timeinfo)){
    return "Error Obtain NTP";
  }
  
  else{
  
  second = timeinfo.tm_sec;
  minute = timeinfo.tm_min;
  hour = timeinfo.tm_hour;
  day = timeinfo.tm_mday;
  month = timeinfo.tm_mon + 1;
  year = timeinfo.tm_year + 1900;
  weekday = timeinfo.tm_wday +1; 

  sprintf(buf, "%.4d%.2d%.2d%.2d%.2d%.2d", year, month, day, hour, minute, second);
  return buf; 
   
  }
}

String RTC::GetTimeRTC(){

    time_t tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
    tt = tt - 10800;
    data = *gmtime(&tt);//Converte o tempo atual e atribui na estrutura
 
    
    char DataFormatada[64];
    strftime(DataFormatada, 64, "%Y%m%d%H%M%S", &data);//Cria uma String formatada da estrutura "data"
    
    return DataFormatada;
}

String RTC::GetUnixTimeRTC(){

    time_t tt = time(NULL);//Obtem o tempo atual em segundos. Utilize isso sempre que precisar obter o tempo atual
    tt = tt - 10800;
    return String(tt);
    
}

bool RTC::UpdateRTC(){
  
  if(!getLocalTime(&timeinfo)){
    return false;
  }
  else{
//Atribui a variavel UnixTime o valor da hora atual. 
  time_t now;
  now = (now - 10800);
  time(&now);


  return true; 
  }
}
void RTC::UpdateRTCOffLine(String Value){
    Serial.println("Valor Recebido");
    Serial.println(Value);

   String Ano = Value.substring(0, 4);
   String Mes = Value.substring(4, 6);
   String Dia = Value.substring(6, 8);
   String Hora = Value.substring(8, 10);
   String Minuto = Value.substring(10, 12);
   String Segundo = Value.substring(12, 14);
//    Serial.println(Ano);
//    Serial.println(Mes);
//    Serial.println(Dia);
//    Serial.println(Hora);
//    Serial.println(Minuto);
//    Serial.println(Segundo);
   struct tm tm;

    tm.tm_year = Ano.toInt() - 1900;

    tm.tm_mon = Mes.toInt() - 1;

    tm.tm_mday = Dia.toInt();

    tm.tm_hour = Hora.toInt() + 3;

    tm.tm_min = Minuto.toInt();

    tm.tm_sec = Segundo.toInt();

    time_t t = mktime(&tm);

    struct timeval now = { .tv_sec = t };

    settimeofday(&now, NULL);
}
