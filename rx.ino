
#include <VirtualWire.h>
int score =0;
int state = 0;
int flag = 0; 
int over=0;
int i=0;
int j=0;

void setup()
{	Serial.begin(9600);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(12);
    vw_setup(4000);  // Bits per sec
    pinMode(13, OUTPUT);

    vw_rx_start();       // Start the receiver PLL running
   //  Serial.print("Current Run:0");
}
    void loop()
{
  
    
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
		  if(buf[0]=='1'){
				score=score+1;
                                flag = 0; 
                               // Serial.print("Current Run:1");
			  }  
	   else if(buf[0]=='2'){
					score=score+2;
                                        flag = 0; 
                                      //  Serial.print("Current Run:2");
				}
		
		   else if(buf[0]=='3'){
					score=score+3;
                                        flag = 0; 
                                       // Serial.print("Current Run:3");
				}

                   else if(buf[0]=='4'){
					score=score+4;
                                        flag = 0; 
                                       // Serial.print("Current Run:4");
				}
                   else if(buf[0]=='5'){
					score=score+5;
                                        flag = 0; 
                                      //  Serial.print("Current Run:5");
				}
                   else if(buf[0]=='6'){
					score=score+6;
                                        flag = 0; 
                                       // Serial.print("Current Run:6");
				}
   i++;


	}



	
 if(flag == 0){

 //Serial.print("   Run:");
   if(i==6)
        {j=j+1; i=0;}

        Serial.print(score);
        Serial.println();

     
if(j==2)
{
  score=0;
  j=0;
}
		



 flag = 1;
 }
 

       
       

	

}
