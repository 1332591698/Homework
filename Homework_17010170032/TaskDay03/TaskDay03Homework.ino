void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
int income;
void loop()
{
  if(Serial.available()>0)
  {
  	income=Serial.read();
    income-='0';
  	digitalWrite(7,LOW);
  	delay(10);
  	digitalWrite(3,(income&0x1)?HIGH:LOW);
  	digitalWrite(4,((income>>1)&0x1)?HIGH:LOW);
  	digitalWrite(5,((income>>2)&0x1)?HIGH:LOW);
  	digitalWrite(6,((income>>3)&0x1)?HIGH:LOW);
  	digitalWrite(7,HIGH);
  	while(!Serial.available());
  }
}