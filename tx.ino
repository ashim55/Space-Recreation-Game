#include <VirtualWire.h>
char *controller;

int ledPin = 13;

int knockSensor = 0;               

byte val = 0;

int statePin = LOW;

int THRESHOLD = 120;
int i=0;



void setup() {

 pinMode(ledPin, OUTPUT); 

 Serial.begin(9600);
 
 
     vw_set_tx_pin(12);          // Sets pin D12 as the TX pin
    vw_set_ptt_inverted(true);  // Required for DR3100
    vw_setup(4000);	        // Bits per sec

}



void loop() {


  val = analogRead(knockSensor);   


  if (val >= THRESHOLD) {

    //statePin = !statePin;

  //  digitalWrite(ledPin, statePin);
   // Serial.println(val);
    
    digitalWrite(ledPin, HIGH);

  delay(500);
  if(val>=120 && val <140){
        controller="1"  ;
        vw_send((uint8_t *)controller, strlen(controller));
        vw_wait_tx(); // Wait until the whole message is gone
        digitalWrite(ledPin, LOW);
    }
    
    if(val>=140 && val <160){
        controller="2"  ;
        vw_send((uint8_t *)controller, strlen(controller));
        vw_wait_tx(); // Wait until the whole message is gone
         digitalWrite(ledPin, LOW);
    }
    
     if(val>=160 && val <180){
        controller="3"  ;
        vw_send((uint8_t *)controller, strlen(controller));
        vw_wait_tx(); // Wait until the whole message is gone
         digitalWrite(ledPin, LOW);
    }
     if(val>=180 && val <200){
        controller="4"  ;
        vw_send((uint8_t *)controller, strlen(controller));
        vw_wait_tx(); // Wait until the whole message is gone
         digitalWrite(ledPin, LOW);
    }
     if(val>=200 && val <220){
        controller="5"  ;
        vw_send((uint8_t *)controller, strlen(controller));
        vw_wait_tx(); // Wait until the whole message is gone
         digitalWrite(ledPin, LOW);
    }
     if(val>=220){
        controller="5"  ;
        vw_send((uint8_t *)controller, strlen(controller));
        vw_wait_tx(); // Wait until the whole message is gone
         digitalWrite(ledPin, LOW);
    }
    
  }
  
    // we have to make a delay to avoid overloading the serial port

}
