#include <VirtualWire.h>

int button1 = 2;    
int button2 = 3;    
int button3 = 4;   

int buttonState1=0;
int buttonState2=0;
int buttonState3=0;

//int score=0;

char *controller;
void setup() {

  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  
   Serial.begin(9600);

  pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(4000);// speed of data transfer Kbps
}

void loop(){


int  buttonState1 = digitalRead(button1);
int    buttonState2 = digitalRead(button2);
 int     buttonState3 = digitalRead(button3);
      
      

  if (buttonState1 == HIGH) {

  controller="1"  ;
	vw_send((uint8_t *)controller, strlen(controller));
	vw_wait_tx(); // Wait until the whole message is gone
	
  } 
  else if (buttonState2 == HIGH){
  
    controller="2"  ;
	vw_send((uint8_t *)controller, strlen(controller));
	vw_wait_tx(); // Wait until the whole message is gone

  }
   else if (buttonState3 == HIGH){
     controller="3"  ;
	vw_send((uint8_t *)controller, strlen(controller));
	vw_wait_tx(); // Wait until the whole message is gone
	
  }
  else
  {   
  
  }
  
 


}
