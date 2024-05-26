#include <asf.h>

#define STANDARD_MODE_FAST_MODE 0x0
#define FAST_MODE_PLUS 0X01
#define HIGHSPEED_MODE 0X02
#define SLAVE_ADDR 0x12

#define BUF_SIZE 3


/* Function Prototype */
void i2c_clock_init(void);
void i2c_pin_init(void);
void i2c_master_init(void);
void i2c_master_transact(void);
uint32_t calculate_baud(uint32_t, uint32_t);


uint8_t tx_buf[BUF_SIZE] = {1, 2, 3};

uint8_t rx_buf[BUF_SIZE];

uint8_t i;

volatile bool tx_done = false, rx_done = false;



/* I2C handler */
void SERCOM2_Handler(void)
{

    // WRITE TO SLAVE ?

    /* Master on bus interrupt checking */
    if (SERCOM2->I2CM.INTFLAG.bit.MB)
    {
        if (i == BUF_SIZE)
        { /* After transferring the last byte stop condition will be sent */
            SERCOM2->I2CM.CTRLB.bit.CMD = 0x3;
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);
            tx_done = true;
            i = 0;
        }
        else
        { /* placing the data from transmitting buffer to DATA register*/
            SERCOM2->I2CM.DATA.reg = tx_buf[i++];
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);
        }
    }


    // READ FROM SLAVE ? 

    /* Slave on bus interrupt checking */
    if (SERCOM2->I2CM.INTFLAG.bit.SB)
    {
        if (i == (BUF_SIZE-1))
        { /* NACK should be sent before reading the last byte */
            SERCOM2->I2CM.CTRLB.reg |= SERCOM_I2CM_CTRLB_ACKACT;
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);
            SERCOM2->I2CM.CTRLB.bit.CMD = 0x3;
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);
            rx_buf[i++] = SERCOM2->I2CM.DATA.reg;
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);
            rx_done = true;
        }
        else
        {
            SERCOM2->I2CM.CTRLB.reg &= ~SERCOM_I2CM_CTRLB_ACKACT;
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);

            rx_buf[i++] = SERCOM2->I2CM.DATA.reg;
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);

            /* sending ACK after reading each byte */
            SERCOM2->I2CM.CTRLB.bit.CMD = 0x2;
            while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);
        }
    }

}



/*Assigning pin to the alternate peripheral function*/
static inline void pin_set_peripheral_function(uint32_t pinmux)
{
    uint8_t port = (uint8_t)((pinmux >> 16)/32);
    PORT->Group[port].PINCFG[((pinmux >> 16) - (port*32))].bit.PMUXEN = 1;
    PORT->Group[port].PMUX[((pinmux >> 16) - (port*32))/2].reg &= ~(0xF << (4 * ((pinmux >>
    16) & 0x01u)));
    PORT->Group[port].PMUX[((pinmux >> 16) - (port*32))/2].reg |= (uint8_t)((pinmux &
    0x0000FFFF) << (4 * ((pinmux >> 16) & 0x01u)));
}



/* calculating the BAUD value using Fgclk,Fscl,Trise
FSCL =fGCLK / (10 + BAUD +BAUDLOW + fGCLKTRISE )*/
uint32_t calculate_baud(uint32_t fgclk, uint32_t fscl)
{
    float f_temp, f_baud;
    f_temp = ((float)fgclk/(float)fscl) - (((float)fgclk/(float)1000000)*0.3);
    f_baud = (f_temp/2)-5;
    return ((uint32_t)f_baud);
}



/* SERCOM clock and peripheral bus clock initialization */
void i2c_clock_init()
{
    struct system_gclk_chan_config gclk_chan_conf;
    uint32_t gclk_index = SERCOM2_GCLK_ID_CORE;
    /* Turn on module in PM */
    system_apb_clock_set_mask(SYSTEM_CLOCK_APB_APBC, PM_APBCMASK_SERCOM2);
    /* Turn on Generic clock for I2C */
    system_gclk_chan_get_config_defaults(&gclk_chan_conf);

    /* Default is generator 0. Otherwise need to configure like below */
    /* gclk_chan_conf.source_generator = GCLK_GENERATOR_1; */
    system_gclk_chan_set_config(gclk_index, &gclk_chan_conf);
    system_gclk_chan_enable(gclk_index);
}


/* I2C pin initialization */
void i2c_pin_init()
{
    /* PA08 and PA09 set into peripheral function D*/
    pin_set_peripheral_function(PINMUX_PA08D_SERCOM2_PAD0); // SDA
    pin_set_peripheral_function(PINMUX_PA09D_SERCOM2_PAD1); // SCL
}


/* I2C master initialization */
void i2c_master_init()
{
    /* By setting the SPEED bit field as 0x01, I2C Master runs at Fast mode + - 1MHz,
    By setting the SDAHOLD bit field as 0x02, SDA hold time is configured for 300-600ns,
    By setting the RUNSTDBY bit as 0x01,Generic clock is enabled in all sleep modes,any
    interrupt can wake up the device,

    SERCOM2 is configured as an I2C Master by writing the MODE bitfield as 0x5 */

    SERCOM2->I2CM.CTRLA.reg = SERCOM_I2CM_CTRLA_SPEED (FAST_MODE_PLUS)    |
                                        SERCOM_I2CM_CTRLA_SDAHOLD(0x2)    |
                                        SERCOM_I2CM_CTRLA_RUNSTDBY        |
                                        SERCOM_I2CM_CTRLA_MODE_I2C_MASTER;


    /* smart mode enabled by setting the bit SMEN as 1 */
    SERCOM2->I2CM.CTRLB.reg = SERCOM_I2CM_CTRLB_SMEN;
    while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);

    /* BAUDLOW is non-zero, and baud register is loaded */
    SERCOM2->I2CM.BAUD.reg = SERCOM_I2CM_BAUD_BAUD(11) | SERCOM_I2CM_BAUD_BAUDLOW(22);
    while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);


    /* SERCOM2 peripheral enabled by setting the ENABLE bit as 1*/
    SERCOM2->I2CM.CTRLA.reg |= SERCOM_I2CM_CTRLA_ENABLE;
    while((SERCOM2->I2CM.SYNCBUSY.reg & SERCOM_I2CM_SYNCBUSY_ENABLE));


    /* bus state is forced into idle state */
    SERCOM2->I2CM.STATUS.bit.BUSSTATE = 0x1;
    while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);


    /* Both master on bus and slave on bus interrupt is enabled */
    SERCOM2->I2CM.INTENSET.reg = SERCOM_I2CM_INTENSET_MB | SERCOM_I2CM_INTENSET_SB;


    /* SERCOM2 handler enabled */
    system_interrupt_enable(SERCOM2_IRQn);
}


/* I2C master Transaction */
void i2c_master_transact(void)
{
    i = 0;
    /* Acknowledge section is set as ACK signal by
    writing 0 in ACKACT bit */
    SERCOM2->I2CM.CTRLB.reg &= ~SERCOM_I2CM_CTRLB_ACKACT;
    while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);


    /* slave address with Write(0) */
    SERCOM2->I2CM.ADDR.reg = (SLAVE_ADDR << 1) | 0;
    while(!tx_done);


    i = 0;
    /* Acknowledge section is set as ACK signal by
    writing 0 in ACKACT bit */
    SERCOM2->I2CM.CTRLB.reg &= ~SERCOM_I2CM_CTRLB_ACKACT;
    while(SERCOM2->I2CM.SYNCBUSY.bit.SYSOP);


    /* slave address with read (1) */
    SERCOM2->I2CM.ADDR.reg = (SLAVE_ADDR << 1) | 1;
    while(!rx_done);


    /*interrupts are cleared */
    SERCOM2->I2CM.INTENCLR.reg = SERCOM_I2CM_INTENCLR_MB | SERCOM_I2CM_INTENCLR_SB;
}


int main (void)
{
    system_init();

    i2c_clock_init();

    i2c_pin_init();


    i2c_master_init();
    
    i2c_master_transact();


    while(1);
}