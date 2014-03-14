/*
 * FnordLampen.c
 *
 * Created: 23.12.2012 01:29:23
 *  Author: Stefan
 */ 



#include <avr/io.h>

int main(void)
{
	uint32_t x,xs,i,rot,gruen,blau;
	uint16_t led;
	float r,g,b;
	DDRB = 255;
	DDRD = 255;
	xs = 1 + (1 << 3) + (1 << 6) + (1 << 9);
    x = xs;
	
	rot = 900;
	gruen = 900;
	blau = 900;
	b = 0;
	r = 1;
	g = 0;
	
	
	i= 0;
	x=0;
	while(1){
		x++;
		if(x==12){
			x=0;
			i++;
		}
		if(i==16)i=0;
		led = 1<<i;
		PORTB = ~(led);
		PORTD = ~(led>>8);
		
		
		
	}
	
	while(1)
    {
		b+= (g-b)/100;
		g+= r/100;
		r-= g/100;
		
		rot = r*250+250;
		gruen = g*250+250;
		blau = b*250+250;
		//PORTB = ~x;
		//PORTD = ~(x >> 8);
		//x = x << 1;
		//if(x > 4000) x = xs;
		
		
		
		
		for(i=0;i<250;i++){
			PORTB = ~(i<rot);
		}			
		for(i=0;i<250;i++){
			PORTB = ~((i<gruen)<<1);
		}			
		for(i=0;i<250;i++){
			PORTB = ~((i<blau)<<2);
		}			
    }
}
