void setup()
{
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
char income=' ';
void loop()
{
  if(Serial.available()>0)
  {
  	income=char(Serial.read());
  }
  work();
}
void work()
{
	switch(income)
    {
      case 'f'://前进，6、7左轮，9、10右轮，5左灯，8右灯
        digitalWrite(6,HIGH);
        digitalWrite(7,LOW);
        digitalWrite(9,HIGH);
        digitalWrite(10,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(8,HIGH);
        break;
      
      case 'b'://后退
      	digitalWrite(6,LOW);
      	digitalWrite(7,HIGH);
        digitalWrite(9,LOW);
        digitalWrite(10,HIGH);
      while(!Serial.available())
      {
        digitalWrite(5,HIGH);
        digitalWrite(8,HIGH);
        delay(500);
        digitalWrite(5,LOW);
        digitalWrite(8,LOW);
        delay(500);
      }
      	break;
      
      case 'l'://左转
      	digitalWrite(6,LOW);
      	digitalWrite(7,HIGH);
        digitalWrite(9,HIGH);
        digitalWrite(10,LOW);
      while(!Serial.available())
      {
        digitalWrite(8,LOW);
        digitalWrite(5,HIGH);
        delay(500);
        digitalWrite(5,LOW);
        delay(500);
      }
      	break;
      
      case 'r'://右转
      	digitalWrite(6,HIGH);
      	digitalWrite(7,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,HIGH);
      while(!Serial.available())
      {
        digitalWrite(5,LOW);
        digitalWrite(8,HIGH);
        delay(500);
        digitalWrite(8,LOW);
        delay(500);
      }
      	break;
      	
      case 's'://停止
      	digitalWrite(6,LOW);
      	digitalWrite(7,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(5,LOW);
        digitalWrite(8,LOW);
      	break;
      
      default:
      	break;
    }
}