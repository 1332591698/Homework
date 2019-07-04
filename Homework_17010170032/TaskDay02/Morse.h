#ifndef Morse_h
#define Morse_h
class Morse
{
	public:
		Morse(int pin);
		void dot();
		void dash();
    void c_space();
    void w_space();
	private:
		int _pin;
		int _delayTime=250;
};
#endif
