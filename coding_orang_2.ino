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
 
  // ada SMS baru?
  //-----------------------------------------------
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

if(load1==0){loadst="Load1 On\r\n";}
        else{loadst="Load1 Off\r\n";}
        
if(load2==0){loadst=loadst + "Load2 On\r\n";}
        else{loadst=loadst + "Load2 Off\r\n";}
        
if(load3==0){loadst=loadst + "Load3 On\r\n";}
        else{loadst=loadst + "Load3 Off\r\n";}
        
if(load4==0){loadst=loadst + "Load4 On";}
        else{loadst=loadst + "Load4 Off";}
        
sendSMS(GSM_Nr,loadst);
}

eeprom_write();
relays();
}


GSM_Nr="";
GSM_Msg="";
}

void eeprom_write(){
EEPROM.write(1,load1);
EEPROM.write(2,load2);
EEPROM.write(3,load3);
EEPROM.write(4,load4);  
}

void relays(){  
digitalWrite(Relay1, load1); 
digitalWrite(Relay2, load2); 
digitalWrite(Relay3, load3); 
digitalWrite(Relay4, load4); 
}
