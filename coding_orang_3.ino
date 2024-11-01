// Kirim SMS 
void sendSMS(String number, String msg){
GSM.print("AT+CMGS=\"");GSM.print(number);GSM.println("\"\r\n");
delay(500);
GSM.println(msg);
delay(500);
GSM.write(byte(26));
delay(5000);  
}

// perintah SMS
void GetSMS() {
  // nomor SMS
  GSM_Nr  = RxString;
  int t1 = GSM_Nr.indexOf('"');
  GSM_Nr.remove(0,t1 + 1);
  t1 = GSM_Nr.indexOf('"');
  GSM_Nr.remove(t1);
   
  // menerima SMS
  GSM_Msg = RxString;
  t1 = GSM_Msg.indexOf('"');
  GSM_Msg.remove(0,t1 + 1);
  t1 = GSM_Msg.indexOf('"');
  GSM_Msg.remove(0,t1 + 1);
  t1 = GSM_Msg.indexOf('"');
  GSM_Msg.remove(0,t1 + 1);
  t1 = GSM_Msg.indexOf('"');
  GSM_Msg.remove(0,t1 + 1);
  t1 = GSM_Msg.indexOf('"');
  GSM_Msg.remove(0,t1 + 1);
  t1 = GSM_Msg.indexOf('"');
  GSM_Msg.remove(0,t1 + 1);
  GSM_Msg.remove(0,1);
  GSM_Msg.trim();

Serial.print("Number:"); Serial.println(GSM_Nr);
Serial.print("SMS:"); Serial.println(GSM_Msg);
}

boolean Received(String S) {
  if (RxString.indexOf(S) >= 0) return true; else return false;
}


void initModule(String cmd, char *res, int t){
while(1){
    Serial.println(cmd);
    GSM.println(cmd);
    delay(100);
    while(GSM.available()>0){
       if(GSM.find(res)){
        Serial.println(res);
        delay(t);
        return;
       }else{Serial.println("Error");}}
    delay(t);
  }
}
