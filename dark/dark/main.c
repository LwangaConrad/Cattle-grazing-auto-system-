/*
 * dark.c
 *
 * Created: 5/4/2021 5:38:42 PM
 * Author : conrad
 */ 

#include <avr/io.h>
#define F_CPU 1000000ul
#include <util/delay.h>
#define rs PH0
#define rw PH1
#define enable PH2
#define dataline PORTJ
unsigned char word[] = "P1 Close";
unsigned char word2[] = "P2 Close";
unsigned char word3[] = "P3 Close";
unsigned char word4[] = "P4 Close";
unsigned char word5[] = "P1: Open";
unsigned char word6[] = "P2: Open";
unsigned char word7[] = "P3: Open";
unsigned char word8[] = "P4: Open";

int main(void)
{
    /*
		LWANGA CONRAD ARTHUR 
	*/
	DDRG = 0x00;
	DDRF = 0b00001111;
	DDRJ = 0xFF;
	DDRH = 0xFF;
	DDRK = 0xFF;
	DDRB = 0xFF;
	DDRA = 0xFF;
	int y,d,o,x,f,u,l,t,i;
	int wer = 0;
	TCCR0B |= (1<<CS00);
	TCNT0 = 0x0;

	PORTF = 0xFF;
	PORTA = 0x3;
	PING = 0xFF;
	PORTH &= ~(1<<enable);
	_delay_ms(1);
	PORTH |= (1<<enable);
	_delay_ms(1);

	PORTH &= ~(1<<rs);
	PORTH &= ~(1<<rw);

	PORTH &= ~(1<<enable);
	_delay_ms(1);
	PORTH |= (1<<enable);
	_delay_ms(1);

	PORTJ = 0x0F;
	PORTH &= ~(1<<enable);
	_delay_ms(1);
	PORTH |= (1<<enable);
	_delay_ms(1);

	PORTH |= (1<<rs);
	PORTH &= ~(1<<rw);

	for(y = 0; y < 8; y++){
		PORTJ = word[y];
		PORTH &= ~(1<<enable);
		_delay_ms(1);
		PORTH |= (1<<enable);
		_delay_ms(1);
	}
	for(x = 0; x < 8; x++){
		PORTJ = word2[x];
		PORTH &= ~(1<<enable);
		_delay_ms(1);
		PORTH |= (1<<enable);
		_delay_ms(1);
	}
	for(d = 0; d < 8; d++){
		PORTJ = word3[d];
		PORTH &= ~(1<<enable);
		_delay_ms(1);
		PORTH |= (1<<enable);
		_delay_ms(1);
	}
	for(o = 0; o < 8; o++){
		PORTJ = word4[o];
		PORTH &= ~(1<<enable);
		_delay_ms(1);
		PORTH |= (1<<enable);
		_delay_ms(1);
	}
	    while (1) 
    {
		//when 0 is pressed
		PORTF = 0b11111011;
		if((PINF & (1<<7)) == 0){
			//change all door statuses to open
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word5[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(u = 0; u < 8; u++){
				PORTJ = word6[u];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(l = 0; l < 8; l++){
				PORTJ = word7[l];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(t = 0; t < 8; t++){
				PORTJ = word8[t];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
					//light green led
					for (i = 0; i < 40; i++)
					{
						_delay_ms(100);
					}
					PORTB = 0xF;
					for (i = 0; i < 360; i++)
					{
						_delay_ms(100);
					}
					//close doors
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH &= ~(1<<rs);
					PORTH &= ~(1<<rw);
					
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTJ = 0x01;
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH |= (1<<rs);
					PORTH &= ~(1<<rw);

					for(y = 0; y < 8; y++){
						PORTJ = word[y];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(x = 0; x < 8; x++){
						PORTJ = word2[x];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(d = 0; d < 8; d++){
						PORTJ = word3[d];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(o = 0; o < 8; o++){
						PORTJ = word4[o];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for (i = 0; i < 200; i++)
					{
						_delay_ms(100);
					}
						//add 1 minute to grazing counter
						PORTA = 0x9f;
					for (i = 0; i < 600; i++)
					{
						_delay_ms(100);
					}
						//add 1 minute to grazing counter
						PORTA = 0x25;
					for (i = 0; i < 600; i++)
					{
						_delay_ms(100);
					}
						//add 1 minute to grazing counter
						PORTA = 0xd;
					for (i = 0; i < 600; i++)
					{
						_delay_ms(100);
					}
					//sound buzzer
					PORTK |= (1<<0);
					//switch off green led
					PORTB &= 0xF0;
					//add 1 minute to grazing counter
					PORTA = 0x99;
					//light red led
					while (wer < 60)
					{
						PORTB ^= 0xF0;
						for (i = 0; i < 10; i++)
						{
							_delay_ms(100);
						}
						if (wer == 40){
							//switch on green led
							PORTB |= 0xF;
							PORTK &= ~(1<<0);
						}
						wer++;
					}
					//switch off red led
					PORTB &= 0xF;
					for (i = 0; i < 1000; i++)
					{
						_delay_ms(100);
					}
					//sound buzzer
					PORTK |= (1<<0);
					//switch off green led
					PORTB &= 0xF0;
					//light red led
					wer = 0;
					while (wer < 60)
					{
						PORTB ^= 0xF0;
						for (i = 0; i < 10; i++)
						{
							_delay_ms(100);
						}
						if (wer == 40){
							//switch on green led
							PORTB |= 0xF;
							PORTK &= ~(1<<0);
						}
						wer++;
					}
					//switch off red led
					PORTB &= 0xF;
					for (i = 0; i < 400; i++)
					{
						_delay_ms(100);
					}
					//add 1 minute to grazing counter
					PORTA = 0x49;
					for (i = 0; i < 600; i++)
					{
						_delay_ms(100);
					}
					//add 1 minute to grazing counter
					PORTA = 0x41;
					for (i = 0; i < 600; i++)
					{
						_delay_ms(100);
					}
					//sound buzzer
					PORTK |= (1<<0);
					//switch off green led
					PORTB &= 0xF0;
					//add 1 minute to grazing counter
					PORTA = 0x1f;
					//open main door
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH &= ~(1<<rs);
					PORTH &= ~(1<<rw);
					
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTJ = 0x01;
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH |= (1<<rs);
					PORTH &= ~(1<<rw);

					for(f = 0; f < 8; f++){
						PORTJ = word5[f];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(u = 0; u < 8; u++){
						PORTJ = word6[u];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(l = 0; l < 8; l++){
						PORTJ = word7[l];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(t = 0; t < 8; t++){
						PORTJ = word8[t];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					//light red led
					wer = 0;
					while (wer < 60)
					{
						PORTB ^= 0xF0;
						for (i = 0; i < 10; i++)
						{
							_delay_ms(100);
						}
						if (wer == 40){
							PORTK &= ~(1<<0);
							//close doors
							PORTH &= ~(1<<enable);
							_delay_ms(1);
							PORTH |= (1<<enable);
							_delay_ms(1);
							
							PORTH &= ~(1<<rs);
							PORTH &= ~(1<<rw);
							
							PORTH &= ~(1<<enable);
							_delay_ms(1);
							PORTH |= (1<<enable);
							_delay_ms(1);
							
							PORTJ = 0x01;
							PORTH &= ~(1<<enable);
							_delay_ms(1);
							PORTH |= (1<<enable);
							_delay_ms(1);
							
							PORTH |= (1<<rs);
							PORTH &= ~(1<<rw);

							for(y = 0; y < 8; y++){
								PORTJ = word[y];
								PORTH &= ~(1<<enable);
								_delay_ms(1);
								PORTH |= (1<<enable);
								_delay_ms(1);
							}
							for(x = 0; x < 8; x++){
								PORTJ = word2[x];
								PORTH &= ~(1<<enable);
								_delay_ms(1);
								PORTH |= (1<<enable);
								_delay_ms(1);
							}
							for(d = 0; d < 8; d++){
								PORTJ = word3[d];
								PORTH &= ~(1<<enable);
								_delay_ms(1);
								PORTH |= (1<<enable);
								_delay_ms(1);
							}
							for(o = 0; o < 8; o++){
								PORTJ = word4[o];
								PORTH &= ~(1<<enable);
								_delay_ms(1);
								PORTH |= (1<<enable);
								_delay_ms(1);
							}
						}
						wer++;
					}
					//switch off red led
					PORTB &= 0xF;
			}
		//when 2 is pressed
		PORTF = 0b11111011;
		if((PINF & (1<<4)) == 0){
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word6[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light green led
			for (i = 0; i < 40; i++)
			{
				_delay_ms(100);
			}
			PORTB |= (1<<1);
			for (i = 0; i < 360; i++)
			{
				_delay_ms(100);
			}
			//close doors
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(y = 0; y < 8; y++){
				PORTJ = word[y];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for (i = 0; i < 200; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x9f;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x25;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0xd;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<1);
			//add 1 minute to grazing counter
			PORTA = 0x99;
			//light red led
			while (wer < 60)
			{
				PORTB ^= 0x20;
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<1);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<5);
			for (i = 0; i < 1000; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<1);
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<5);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<1);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<5);
			for (i = 0; i < 400; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x49;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x41;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<1);
			//add 1 minute to grazing counter
			PORTA = 0x1f;
			//open main door
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word6[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<5);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					PORTK &= ~(1<<0);
					//close doors
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH &= ~(1<<rs);
					PORTH &= ~(1<<rw);
					
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTJ = 0x01;
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH |= (1<<rs);
					PORTH &= ~(1<<rw);

					for(y = 0; y < 8; y++){
						PORTJ = word[y];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(x = 0; x < 8; x++){
						PORTJ = word2[x];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(d = 0; d < 8; d++){
						PORTJ = word3[d];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(o = 0; o < 8; o++){
						PORTJ = word4[o];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<5);
		}
		//when 1 is pressed
		PORTF = 0b11110111;
		if((PINF & (1<<4)) == 0){
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word5[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light green led
			for (i = 0; i < 40; i++)
			{
				_delay_ms(100);
			}
			PORTB |= (1<<0);
			for (i = 0; i < 360; i++)
			{
				_delay_ms(100);
			}
			//close doors
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(y = 0; y < 8; y++){
				PORTJ = word[y];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for (i = 0; i < 200; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x9f;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x25;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0xd;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<0);
			//add 1 minute to grazing counter
			PORTA = 0x99;
			//light red led
			while (wer < 60)
			{
				PORTB ^= 0x10;
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<0);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<4);
			for (i = 0; i < 1000; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<0);
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<4);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<0);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<4);
			for (i = 0; i < 400; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x49;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x41;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<0);
			//add 1 minute to grazing counter
			PORTA = 0x1f;
			//open main door
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word5[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<4);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					PORTK &= ~(1<<0);
					//close doors
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH &= ~(1<<rs);
					PORTH &= ~(1<<rw);
					
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTJ = 0x01;
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH |= (1<<rs);
					PORTH &= ~(1<<rw);

					for(y = 0; y < 8; y++){
						PORTJ = word[y];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(x = 0; x < 8; x++){
						PORTJ = word2[x];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(d = 0; d < 8; d++){
						PORTJ = word3[d];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(o = 0; o < 8; o++){
						PORTJ = word4[o];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<4);
		}
		//when 3 is pressed
		PORTF = 0b11111101;
		if((PINF & (1<<4)) == 0){
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word7[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light green led
			for (i = 0; i < 40; i++)
			{
				_delay_ms(100);
			}
			PORTB |= (1<<2);
			for (i = 0; i < 360; i++)
			{
				_delay_ms(100);
			}
			//close doors
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(y = 0; y < 8; y++){
				PORTJ = word[y];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for (i = 0; i < 200; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x9f;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x25;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0xd;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<2);
			//add 1 minute to grazing counter
			PORTA = 0x99;
			//light red led
			while (wer < 60)
			{
				PORTB ^= (1<<6);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<2);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<6);
			for (i = 0; i < 1000; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<2);
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<6);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<2);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<6);
			for (i = 0; i < 400; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x49;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x41;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<2);
			//add 1 minute to grazing counter
			PORTA = 0x1f;
			//open main door
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word7[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<6);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					PORTK &= ~(1<<0);
					//close doors
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH &= ~(1<<rs);
					PORTH &= ~(1<<rw);
					
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTJ = 0x01;
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH |= (1<<rs);
					PORTH &= ~(1<<rw);

					for(y = 0; y < 8; y++){
						PORTJ = word[y];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(x = 0; x < 8; x++){
						PORTJ = word2[x];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(d = 0; d < 8; d++){
						PORTJ = word3[d];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(o = 0; o < 8; o++){
						PORTJ = word4[o];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<6);
		}
		//when 4 is pressed
		PORTF = 0b11110111;
		if((PINF & (1<<5)) == 0){
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word8[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light green led
			for (i = 0; i < 40; i++)
			{
				_delay_ms(100);
			}
			PORTB |= (1<<3);
			for (i = 0; i < 360; i++)
			{
				_delay_ms(100);
			}
			//close doors
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(y = 0; y < 8; y++){
				PORTJ = word[y];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word4[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for (i = 0; i < 200; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x9f;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x25;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0xd;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<3);
			//add 1 minute to grazing counter
			PORTA = 0x99;
			//light red led
			while (wer < 60)
			{
				PORTB ^= (1<<7);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<3);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<7);
			for (i = 0; i < 1000; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<3);
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<7);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					//switch on green led
					PORTB |= (1<<3);
					PORTK &= ~(1<<0);
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<7);
			for (i = 0; i < 400; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x49;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//add 1 minute to grazing counter
			PORTA = 0x41;
			for (i = 0; i < 600; i++)
			{
				_delay_ms(100);
			}
			//sound buzzer
			PORTK |= (1<<0);
			//switch off green led
			PORTB &= ~(1<<3);
			//add 1 minute to grazing counter
			PORTA = 0x1f;
			//open main door
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);

			for(f = 0; f < 8; f++){
				PORTJ = word[f];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(x = 0; x < 8; x++){
				PORTJ = word2[x];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(d = 0; d < 8; d++){
				PORTJ = word3[d];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			for(o = 0; o < 8; o++){
				PORTJ = word8[o];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			//light red led
			wer = 0;
			while (wer < 60)
			{
				PORTB ^= (1<<7);
				for (i = 0; i < 10; i++)
				{
					_delay_ms(100);
				}
				if (wer == 40){
					PORTK &= ~(1<<0);
					//close doors
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH &= ~(1<<rs);
					PORTH &= ~(1<<rw);
					
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTJ = 0x01;
					PORTH &= ~(1<<enable);
					_delay_ms(1);
					PORTH |= (1<<enable);
					_delay_ms(1);
					
					PORTH |= (1<<rs);
					PORTH &= ~(1<<rw);

					for(y = 0; y < 8; y++){
						PORTJ = word[y];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(x = 0; x < 8; x++){
						PORTJ = word2[x];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(d = 0; d < 8; d++){
						PORTJ = word3[d];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
					for(o = 0; o < 8; o++){
						PORTJ = word4[o];
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
					}
				}
				wer++;
			}
			//switch off red led
			PORTB &= ~(1<<7);
		}
		}
	}

