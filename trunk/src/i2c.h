#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include "defs.h"

#define START				0x08
#define REP_START			0x10
// Master Transmitter
#define MT_SLA_ACK			0x18
#define MT_SLA_NACK			0x20
#define MT_DATA_ACK			0x28
#define MT_DATA_NACK		0x30
#define MT_ARB_LOST			0x38
// Master Receiver
#define MR_ARB_LOST			0x38
#define MR_SLA_ACK			0x40
#define MR_SLA_NACK			0x48
#define MR_DATA_ACK			0x50
#define MR_DATA_NACK		0x58

#define TWCR_CMD_MASK		0x0F
#define TWSR_STATUS_MASK	0xF8

void i2c_init();
void i2cStart();
void i2cWaitForComplete();
void i2cStop();
int8 i2cStatusOk(int8 status);
void i2cSendData(char data);
void i2cReceiveByte(int8 ackFlag);
char i2cGetReceivedByte(void);


#endif /* I2C_H_ */
