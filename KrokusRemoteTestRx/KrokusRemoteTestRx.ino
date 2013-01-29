#include <VirtualWire.h>

void setup() {                
 Serial.begin(9600);
 
 vw_set_rx_pin(2);
 vw_setup(2000);

 vw_rx_start();
}

void loop() {
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen))
  {
      digitalWrite(13, HIGH); 
      String message  = "";
      for (int i = 0; i < buflen; i++)
      {
        char curr = buf[i];
        message = message+String(curr);
      }
      digitalWrite(13, LOW);
      Serial.println(message);
  }
  
}
