#include "Arduino.h"
#include "Morse.h"
Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_delayTime);
	digitalWrite(_pin,LOW);
	delay(_delayTime);
}
void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_delayTime*3);
	digitalWrite(_pin,LOW);
	delay(_delayTime);
}
void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_delayTime*3);
}
void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_delayTime*7);
}
