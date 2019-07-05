void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
String income="";
void loop()
{
  if(Serial.available()>0)
  {
    income="";
      while(Serial.available()>0)
      {
        int temp=Serial.read();
        if(temp-'0'>=0&&temp-'0'<=9) //去掉非数字的字符
        {
          income+=char(temp);
          delay(2);
        }
      }
      if(income.length()>0)
      {
        showNum(income);
      }
  }
}
//显示数字函数
void showNum(String a) 
{
  String b="";
  for(int c=a.length();c>0;c--)
  {
    b+=a[c-1];
  }
  for(int i=0;i<4;i++)
  {
  	  digitalWrite(8+i,LOW);
  	  delay(20);
  	  digitalWrite(2,(b[i]&0x1)?HIGH:LOW);
  	  digitalWrite(3,((b[i]>>1)&0x1)?HIGH:LOW);
  	  digitalWrite(4,((b[i]>>2)&0x1)?HIGH:LOW);
  	  digitalWrite(5,((b[i]>>3)&0x1)?HIGH:LOW);
  	  digitalWrite(8+i,HIGH);
  }
}