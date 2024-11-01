#include <EEPROM.h>
#include <SoftwareSerial.h>
SoftwareSerial GSM(8, 9);

String phone_no1 = "ISI NOMOR YANG DI GSM";
String phone_no2 = "Enter Number2";

String        RxString  = "";
char          RxChar    = ' ';
int           Counter   = 0;
String        GSM_Nr    = "";
String        GSM_Msg   = "";

#define Relay1 2
#define Relay2 3
#define Relay3 4
#define Relay4 5

int load1, load2, load3, load4;

void setup(){

pinMode(Relay1, OUTPUT); digitalWrite(Relay1, 1); 
pinMode(Relay2, OUTPUT); digitalWrite(Relay2, 1); 
pinMode(Relay3, OUTPUT); digitalWrite(Relay3, 1); 
pinMode(Relay4, OUTPUT); digitalWrite(Relay4, 1); 

Serial.begin(9600); 
GSM.begin(9600);

Serial.println("Initializing....");
initModule("AT","OK",1000);
initModule("AT+CPIN?","READY",1000);
initModule("AT+CMGF=1","OK",1000);
initModule("AT+CNMI=2,2,0,0,0","OK",1000);
Serial.println("Initialized Successfully"); 
  
load1 = EEPROM.read(1);
load2 = EEPROM.read(2);
load3 = EEPROM.read(3);
load4 = EEPROM.read(4);

relays();

delay(100);
}

void loop(){
  
  RxString = "";
  Counter = 0;
  while(GSM.available()){
    delay(1);
    
    RxChar = char(GSM.read());
    
    if (Counter < 200) {
      RxString.concat(RxChar);
      Counter = Counter + 1;
    }
  }
 
  // Ada SMS baru?
  
  if (Received(F("CMT:")) ) GetSMS();

if(GSM_Nr==phone_no1 || GSM_Nr==phone_no2){
  
if(GSM_Msg=="nyalakan lampu 1") {load1=0; sendSMS(GSM_Nr,"Ok Lampu 1 Menyala");}
if(GSM_Msg=="matikan lampu 1"){load1=1; sendSMS(GSM_Nr,"Ok Lampu 1 Mati");}

if(GSM_Msg=="nyalakan kipas") {load2=0; sendSMS(GSM_Nr,"Ok Kipas Menyala");}
if(GSM_Msg=="matikan kipas"){load2=1; sendSMS(GSM_Nr,"Ok Kipas Mati");}

if(GSM_Msg=="nyalakan lampu 2") {load3=0; sendSMS(GSM_Nr,"Ok Lampu 2 Menyala");}
if(GSM_Msg=="matikan lampu 2"){load3=1; sendSMS(GSM_Nr,"Ok Lampu 2 Mati");}

if(GSM_Msg=="nyalakan lampu 3") {load4=0; sendSMS(GSM_Nr,"Ok Lampu 3 Menyala");}
if(GSM_Msg=="matikan lampu 3"){load4=1; sendSMS(GSM_Nr,"Ok Lampu 3 Mati");}

if(GSM_Msg=="nyalakan semua alat") {load1=0, load2=0, load3=0, load4=0; sendSMS(GSM_Nr,"Ok Semua Alat Menyala");}
if(GSM_Msg=="matikan semua alat"){load1=1, load2=1, load3=1, load4=1; sendSMS(GSM_Nr,"Ok Semua Alat Mati");}

if(GSM_Msg=="status alat"){
String loadst = "";
