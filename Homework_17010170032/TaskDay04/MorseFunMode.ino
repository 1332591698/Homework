String dataStr="";
int delayT=250;
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
      dataStr="";
      while(Serial.available()>0)
      {
          dataStr+=char(Serial.read());
          delay(2);
        }
        if(dataStr.length()>0)
        {
          for(int i=0;i<dataStr.length();i++)
            {
              sendMorse(dataStr[i]);
            }
          }
    }
}
void sendMorse(char data)
{
      switch(data)
      {
        case 'a'://*-
        dot();dash();
        c_space();
        break;
        
        case 'b'://-***
        dash();dot();dot();dot();
        c_space();
        break;
        
        case 'c'://-*-*
        dash();dot();dash();dot();
        c_space();
        break;
        
        case 'd'://-**
        dash();dot();dot();
        c_space();
        break;
        
        case 'e'://*
        dot();
        c_space();
        break;
        
        case 'f'://**-*
        dot();dot();dash();dot();
        c_space();
        break;
        
        case 'g'://--*
        dash();dash();dot();
        c_space();
        break;
        
        case 'h'://****
        dot();dot();dot();dot();
        c_space();
        break;
        
        case 'i'://**
        dot();dot();
        c_space();
        break;
        
        case 'j'://*---
        dot();dash();dash();dash();
        c_space();
        break;
        
        case 'k'://-*-
        dash();dot();dash();
        c_space();
        break;
        
        case 'l'://*-**
        dot();dash();dot();dot();
        c_space();
        break;
        
        case 'm'://--
        dash();dash();
        c_space();
        break;
        
        case 'n'://-*
        dash();dot();
        c_space();
        break;
        
        case 'o'://---
        dash();dash();dash();
        c_space();
        break;
        
        case 'p'://*--*
        dot();dash();dash();dot();
        c_space();
        break;
        
        case 'q'://--*-
        dash();dash();dot();dash();
        c_space();
        break;
        
        case 'r'://*-*
        dot();dash();dot();
        c_space();
        break;
        
        case 's'://***
        dot();dot();dot();
        c_space();
        break;
        
        case 't'://-
        dash();
        c_space();
        break;

        case 'u'://**-
        dot();dot();dash();
        c_space();
        break;
        
        case 'v'://***-
        dot();dot();dot();dash();
        c_space();
        break;
        
        case 'w'://*--
        dot();dash();dash();
        c_space();
        break;
        
        case 'x'://-**-
        dash();dot();dot();dash();
        c_space();
        break;
        
        case 'y'://-*--
        dash();dot();dash();dash();
        c_space();
        break;
        
        case 'z'://--**
        dash();dash();dot();dot();
        c_space();
        break;
        
        case ' '://same as , --**--
        dash();dash();dot();
        dot();dash();dash();
        w_space();
        break;
        
        case '\n'://same as . *-*-*-
        dot();dash();dot();
        dash();dot();dash();
        w_space();
        break;

        default:
        break;
        }
      c_space();
}
void dot()
{
  digitalWrite(13, HIGH);
  delay(delayT);
  digitalWrite(13, LOW);
  delay(delayT);
}
void dash()
{
  digitalWrite(13, HIGH);
  delay(delayT*3);
  digitalWrite(13, LOW);
  delay(delayT);
}
void c_space()
{
  digitalWrite(13,LOW);
  delay(delayT*3);
}
void w_space()
{
  digitalWrite(13,LOW);
  delay(delayT*7);
}