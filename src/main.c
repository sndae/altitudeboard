#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "i2c.h"
#include "defs.h"
#include "temp.h"


int main(){
	//Ports initializing
	DDRC = 0b11111100;
	DDRD = 0b00000010;
	
	

	uart0_init();
	i2c_init();

	int16 temperature = 0;
	int8 i;
	int8 tempdiv[2];

	i2cStop();
	i2cStart();
	i2cWaitForComplete();

	i2cSendData(TEMP_WRITE_ADDR);
	i2cWaitForComplete();

	i2cSendData(TEMP_TEMP_REG);
	i2cWaitForComplete();
	i2cStop();

	while(1){
		i2cStart();
		i2cWaitForComplete();
		i2cSendData(TEMP_READ_ADDR);
		i2cWaitForComplete();

		if( i2cStatusOk(MR_SLA_ACK) ){
			for(i=0; i<2; i++){
				i2cReceiveByte(1);
				i2cWaitForComplete();
				tempdiv[i] = i2cGetReceivedByte();
			}

			temperature = tempdiv[0]<<4 | tempdiv[1]>>4;
		}

		printf("%d\n", temperature);

		_delay_ms(1000);

	}
	return 0;
}

