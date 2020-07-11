#define A_PIN 5
#define B_PIN 7
#define C_PIN 8
#define D_PIN 2
#define E_PIN 4
#define F_PIN 6
#define G_PIN 10
#define H1 0 
#define H2 1
#define M1 9
#define M2 11
#define LED 3
#define H_SWITCH 13
#define M_SWITCH 12

typedef unsigned int uint;
unsigned int seconds,minutes,hours;
long prevTime=0,prevBlink=0;
bool led;

void setup() {
  for(int i=0;i<=11;i++)
      pinMode(i,OUTPUT);
 pinMode(H1,HIGH);
 pinMode(H2,HIGH);
 pinMode(M1,HIGH);
 pinMode(M1,HIGH);
 pinMode(12,INPUT_PULLUP);
 pinMode(13,INPUT_PULLUP);
}

void loop() 
{
//  pinSelect(12,seconds%10);
//  pinSelect(11,seconds/10);
  pinSelect(M2,minutes%10);
  pinSelect(M1,minutes/10);
  pinSelect(H2,hours%10);
  pinSelect(H1,hours/10);
  
  if(!digitalRead(M_SWITCH))
  {
    delay(200);
    if(minutes==59)
      minutes=0;
    else
      minutes++;
  }
  if(!digitalRead(H_SWITCH))
  {
    delay(200);
    if(hours==23)
      hours=0;
    else
      hours++;
  }
  if(millis()-prevBlink>497)
  {
    led=!led;
    digitalWrite(LED,led);
    prevBlink=millis();
  }
  if(millis()-prevTime>994)
  {
      seconds++;
      if(seconds>59)
      {
        seconds=0;
        minutes++;
        if(minutes>59)
        {
          minutes=0;
          hours++;
          if(hours>23)
            hours=0;
        }
      }
    prevTime=millis();
  }
}

void pinSelect(uint pin,uint n)
{
  digitalWrite(pin,LOW);
  SevenSegDisp(n);
  delay(1);
  digitalWrite(pin,HIGH);
} 

void segPins(bool a,bool b,bool c,bool d,bool e,bool f,bool g)
{
  digitalWrite(A_PIN,a);
  digitalWrite(B_PIN,b);
  digitalWrite(C_PIN,c);
  digitalWrite(D_PIN,d);
  digitalWrite(E_PIN,e);
  digitalWrite(F_PIN,f);
  digitalWrite(G_PIN,g);
}

void SevenSegDisp(uint digit)
{
  switch(digit)
  {
    case 0:
      segPins(1,1,1,1,1,1,0);
    break;
    case 1:
      segPins(0,1,1,0,0,0,0);
    break;
    case 2:
      segPins(1,1,0,1,1,0,1);
    break;
    case 3:
      segPins(1,1,1,1,0,0,1);
    break;
    case 4:
      segPins(0,1,1,0,0,1,1);
    break;
    case 5:
      segPins(1,0,1,1,0,1,1);
    break;
    case 6:
      segPins(1,0,1,1,1,1,1);
    break;
    case 7:
      segPins(1,1,1,0,0,0,0);
    break;
    case 8:
      segPins(1,1,1,1,1,1,1);
    break;
    case 9:
      segPins(1,1,1,1,0,1,1);
    break;
  }
}
