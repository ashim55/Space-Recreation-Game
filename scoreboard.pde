import processing.serial.*;
Serial myPort;
String sensorReading="";
int sensor;
PFont font;
int i=0;
int m=0;
int j=0;
int person=0;

int player_a_Run = 0;
int player_a_Over = 0;
int player_a_Ball = 0;

int player_b_Run = 0;
int player_b_Over = 0;
int player_b_Ball = 0;
int stop=0;

// UI Variable

int width_a = 200;
int width_b = 900;
int inc_height = 100;

int player_ab_height=150+inc_height ;
int score_ab_height=280+inc_height;
int over_ab_height=360+inc_height;
int ball_ab_height=440+inc_height;

int cv=0;

void setup() {
  size(1200,660);
  myPort = new Serial(this, "COM4", 9600);
  myPort.bufferUntil('\n');
  font = createFont(PFont.list()[2],32);
  textFont(font);
}

void draw() {
  //The serialEvent controls the display
}  

void serialEvent (Serial myPort){
 sensorReading = myPort.readStringUntil('\n');
  if(sensorReading != null){
    sensorReading=trim(sensorReading);
  }
  
 sensor=Integer.parseInt(sensorReading);
 
 cv=sensor-m;
 
 if(m !=sensor ){i++;}
 
 if(i==6)
        {j=j+1; i=0;}
        if(j==2 && person==0){person=1;player_a_Run=sensor; player_a_Over=j;player_a_Ball=i;j=0;i=0; sensor=0; }
        
        if(j==2 && person==1){person=2;player_b_Run=sensor; player_b_Over=j;player_b_Ball=i;j=0;i=0;  sensor=0; }
        
        if(player_a_Over==2 && player_b_Over==2   )
        {
          person=2 ; stop=1;
        }
        if(person==1 && player_a_Run<sensor){person=3;player_b_Run=sensor; player_b_Over=j;player_b_Ball=i;}

  writeText("" + sensor);

 m=sensor;


}


void writeText(String textToWrite){
  background(255, 204, 0);
  fill(0);
  textSize(60);
  fill(222,84,72);
  text("Score Board", 390, 80); 
  fill(0);
   text("Current Score:"+cv, 350, 150);  
  
  if(person==0)
  {
    
    
    textSize(120);
    text(textToWrite, width_a, score_ab_height);  
   textSize(32); 
   text("Player A", width_a, player_ab_height);   
   text("Over", width_a, over_ab_height);   
   text(j+"."+i, width_a, ball_ab_height); 
   
   textSize(120);
   text(player_b_Run, width_b, score_ab_height); 
   textSize(32);   
   text("Player B", width_b, player_ab_height);   
   text("Over", width_b, over_ab_height);   
   text(player_b_Over+"."+player_b_Ball, width_b, ball_ab_height);  
 
  
  }
  
  else if(person==1){
    
  textSize(120); 
   text(player_a_Run, width_a, score_ab_height);   
   textSize(32); 
   text("Player A", width_a, player_ab_height);   
   text("Over", width_a, over_ab_height);   
   text(player_a_Over+"."+player_a_Ball, width_a, ball_ab_height); 
   
      
    textSize(120); 
   text(textToWrite, width_b, score_ab_height);
   textSize(32); 
    text("Player B", width_b, player_ab_height);   
   text("Over", width_b, over_ab_height);   
   text(j+"."+i, width_b, ball_ab_height);  
 
 }
 else if(person==2)
 {
   textSize(120); 
   text(player_a_Run, width_a, score_ab_height);  
   textSize(32);  
   text("Player A", width_a, player_ab_height);   
   text("Over", width_a, over_ab_height);   
   text(player_a_Over+"."+player_a_Ball, width_a, ball_ab_height); 
   
   textSize(120); 
   text(player_b_Run, width_b, score_ab_height);  
  textSize(32);  
   text("Player B", width_b, player_ab_height);   
   text("Over", width_b, over_ab_height);   
   text(player_b_Over+"."+player_b_Ball, width_b, ball_ab_height);  
   
   if(player_a_Run > player_b_Run){ text("Winer A ", 300, 600);  }
   else if (player_a_Run < player_b_Run) { text("Winer B ", 300, 600);  }
   else{ text("Match Draw ", 300, 600);  }
   
     
 
 
 }
 
 else if(person==3)
 {
    textSize(120); 
   text(player_a_Run, width_a, score_ab_height);  
   textSize(32);  
   text("Player A", width_a, player_ab_height);   
   text("Over", width_a, over_ab_height);   
   text(player_a_Over+"."+player_a_Ball, width_a, ball_ab_height); 
   
  textSize(120); 
   text(player_b_Run, width_b, score_ab_height);  
  textSize(32);  
   text("Player B", width_b, player_ab_height);   
   text("Over", width_b, over_ab_height);   
   text(player_b_Over+"."+player_b_Ball, width_b, ball_ab_height); 
   
    text("Winer B ", 300, 600);  
 
 
 }
 
 
   
   
}

