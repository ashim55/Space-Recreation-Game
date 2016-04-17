
#include <VirtualWire.h>
int score =0;
int state = 0;
int flag = 0; 

void setup()
{	Serial.begin(9600);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(12);
    vw_setup(4000);  // Bits per sec
    pinMode(13, OUTPUT);

    vw_rx_start();       // Start the receiver PLL running
}
    void loop()
{
  
    
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
		  if(buf[0]=='1'){
				score=score+10;
                                flag = 0; 
			  }  
	   else if(buf[0]=='2'){
					score=score+5;
                                        flag = 0; 
				}
		
		   else if(buf[0]=='3'){
					score=score+2;
                                        flag = 0; 
				}

	}



	
 if(flag == 0){
 Serial.print("score:");
        Serial.print(score);
		Serial.println();
 flag = 1;
 }
 

       
       

	

}
