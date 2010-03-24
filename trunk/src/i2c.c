#include "i2c.h"

void i2c_init(){
	TWBR = 20; //SCL = CPU/(16 + 2 * TWBR * 4 "UPP" TWPS)
	TWSR = (1<<TWPS1)|(1<<TWPS0);
}

void i2cStart(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
}

void i2cWaitForComplete(){
	while (!(TWCR & (1<<TWINT)));
}

int8 i2cStatusOk(int8 status){
	if((TWSR & TWSR_STATUS_MASK) != status)
		return 0;
	return 1;
}

void i2cSendData(char data){
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
}

void i2cReceiveByte(int8 ackFlag){
	// begin receive over i2c
	if( ackFlag ){
		// ackFlag = TRUE: ACK the recevied data
		//outb(TWCR, (inb(TWCR)&TWCR_CMD_MASK)|BV(TWINT)|BV(TWEA));
		TWCR = (TWCR & TWCR_CMD_MASK)|(1<<TWINT)|(1<<TWEA);
	}
	else{
		// ackFlag = FALSE: NACK the recevied data
		//outb(TWCR, (inb(TWCR)&TWCR_CMD_MASK)|BV(TWINT));
		TWCR = (TWCR & TWCR_CMD_MASK)|(1<<TWINT);
	}
}

char i2cGetReceivedByte(void){
	return TWDR;
}

void i2cStop(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
