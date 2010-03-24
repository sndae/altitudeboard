#include <avr/io.h>
#include <stdio.h>

#include "uart.h"

static int uart0_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart0_putchar, NULL, _FDEV_SETUP_WRITE);

void uart0_init(){
	UBRR0H = 0;							//Baudrate 115 200
	UBRR0L = 12;
	UCSR0A = (1<<U2X0);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); 	//Receiver and transmitter enabled
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);	//8 bits

	stdout = &mystdout;
}

void uart0_send(char c){
	// Wait for empty transmit buffer
	while ( !( UCSR0A & (1<<UDRE0)) );
	// Put data into buffer, sends the data
	UDR0 = c;
}

char uart0_rec(){
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}

static int uart0_putchar(char c, FILE *stream){
    if (c == '\n') uart0_putchar('\r', stream);
    uart0_send(c);
    return 0;
}


