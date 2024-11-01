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
