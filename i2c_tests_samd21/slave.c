#include <asf.h>
#define STANDARD_MODE_FAST_MODE 0x0
#define FAST_MODE_PLUS 0X01
#define HIGHSPEED_MODE 0X02
#define SLAVE_ADDR 0x12

#define BUF_SIZE 3


/* Function Prototype */
void i2c_clock_init(void);
void i2c_pin_init(void);
void i2c_slave_init(void);


uint8_t i = 0;
uint8_t rx_buff[BUF_SIZE];


/* SERCOM2 I2C handler */
void SERCOM2_Handler(void)
{
    /* Check for Address match interrupt */
    if(SERCOM2->I2CS.INTFLAG.bit.AMATCH)
    {
        /* clearing the Address match interrupt */
        SERCOM2->I2CS.INTFLAG.bit.AMATCH = 1;
    }


    /* Data Ready interrupt check */
    if(SERCOM2->I2CS.INTFLAG.bit.DRDY)
    {
        /* Checking for direction,
        DIR - 0 for slave read,
        DIR - 1 for slave write */
        if (SERCOM2->I2CS.STATUS.bit.DIR)
        {
            /* Slave write */
            if (i == (BUF_SIZE-1))
            {
                SERCOM2->I2CS.DATA.reg = rx_buff[i++];
                /* wait for stop condition */
                SERCOM2->I2CS.CTRLB.bit.CMD = 0x2;
                i = 0;
            }
            else
            {
                SERCOM2->I2CS.DATA.reg = rx_buff[i++];
                /* Execute a byte read operation followed by ACK/NACK reception by master */
                SERCOM2->I2CS.CTRLB.bit.CMD = 0x3;
            }
        }
        else
        {
            /* Slave read */
            if (i == (BUF_SIZE-1))
            {
                SERCOM2->I2CS.CTRLB.bit.ACKACT = 0;
                /* Execute acknowledge action succeeded by waiting for any start (S/Sr) condition */
                SERCOM2->I2CS.CTRLB.bit.CMD = 0x2;
            }
            else
            {
                rx_buff[i++] = SERCOM2->I2CS.DATA.reg;
                SERCOM2->I2CS.CTRLB.bit.ACKACT = 0;
                /* Execute acknowledge action succeeded by reception of next byte to master*/
                SERCOM2->I2CS.CTRLB.bit.CMD = 0x3;
            }
        }
    }


    if (SERCOM2->I2CS.INTFLAG.bit.PREC)
    {
        SERCOM2->I2CS.INTFLAG.bit.PREC = 1;
        if (!SERCOM2->I2CS.STATUS.bit.DIR)
        {
            rx_buff[i++] = SERCOM2->I2CS.DATA.reg;
        }
        i = 0;
    }
}


/*Assigning pin to the alternate peripheral function*/
static inline void pin_set_peripheral_function(uint32_t pinmux)
{
    uint8_t port = (uint8_t)((pinmux >> 16)/32);

    PORT->Group[port].PINCFG[((pinmux >> 16) - (port*32))].bit.PMUXEN = 1;

    PORT->Group[port].PMUX[((pinmux >> 16) - (port*32))/2].reg &= ~(0xF << (4 * ((pinmux >> 16) & 0x01u)));

    PORT->Group[port].PMUX[((pinmux >> 16) - (port*32))/2].reg |= (uint8_t)((pinmux & 0x0000FFFF) << (4 * ((pinmux >> 16) & 0x01u)));
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

    /* Default is generator 0. Other wise need to configure like below */
    /* gclk_chan_conf.source_generator = GCLK_GENERATOR_1; */
    system_gclk_chan_set_config(gclk_index, &gclk_chan_conf);
    system_gclk_chan_enable(gclk_index);
}



/* I2C pin initialization */
void i2c_pin_init()
{
    /* PA08 and PA09 set into peripheral function D*/
    pin_set_peripheral_function(PINMUX_PA08D_SERCOM2_PAD0);
    pin_set_peripheral_function(PINMUX_PA09D_SERCOM2_PAD1);
}




/* I2C Slave initialization */
void i2c_slave_init()
{
    /* By setting the SPEED bit field as 0x01, I2C communication runs at 1MHz,
    By setting the SDAHOLD bit field as 0x02, SDA hold time is configured for 300-600ns,
    By setting the RUNSTDBY bit as 0x01,Generic clock is enabled in all sleep modes,
    any interrupt can wake up the device,
    SERCOM2 is configured as an I2C Slave by writing the MODE bitfield as 0x04 */
    SERCOM2->I2CS.CTRLA.reg = SERCOM_I2CS_CTRLA_SPEED (FAST_MODE_PLUS)    |
                                        SERCOM_I2CS_CTRLA_SDAHOLD(0x2)    |
                                        SERCOM_I2CM_CTRLA_RUNSTDBY        |
                                        SERCOM_I2CS_CTRLA_MODE_I2C_SLAVE;


    /* smart mode enabled by setting the bit SMEN as 1 */
    SERCOM2->I2CS.CTRLB.reg = SERCOM_I2CS_CTRLB_SMEN;

    /* writing the slave address into ADDR register */
    SERCOM2->I2CS.ADDR.reg = SLAVE_ADDR << 1 ;

    /* Address match interrupt, Data ready interrupt,stop received
    interrupts are enabled */
    SERCOM2->I2CS.INTENSET.reg = SERCOM_I2CS_INTENSET_PREC | SERCOM_I2CS_INTENSET_AMATCH |
    SERCOM_I2CS_INTENSET_DRDY;
    
    /* SERCOM2 peripheral enabled by setting the ENABLE bit as 1*/
    SERCOM2->I2CS.CTRLA.reg |= SERCOM_I2CS_CTRLA_ENABLE;
    while((SERCOM2->I2CS.SYNCBUSY.reg & SERCOM_I2CS_SYNCBUSY_ENABLE));

    /* SERCOM2 handler enabled */
    system_interrupt_enable(SERCOM2_IRQn);
}


int main (void)
{
    system_init();
    i2c_clock_init();
    i2c_pin_init();
    i2c_slave_init();
    while(1);
}