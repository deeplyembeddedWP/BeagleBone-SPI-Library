/*
* Main.c
*
*  Created on: Sep 6, 2017
*  Author: Vinay Divakar
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "SPI.h"

/* Enable SPI Debug */
#define SPI_DBG

/* Externs - SPI.c */
extern unsigned char Tx_spi[SPIDEV_BYTES_NUM];
extern unsigned char RX_spi[SPIDEV_BYTES_NUM];
int main()
{
    int i = 0;
    memset(Tx_spi, 0, sizeof(Tx_spi));
    memset(RX_spi, 0, sizeof(RX_spi));
    Tx_spi[0] = 0xAA;
    Tx_spi[1] = 0x0F;
    if (SPI_DEV1_init() == -1)
        printf("(Main)spidev1.0 initialization failed\r\n");

    else
        printf("(Main)spidev1.0 initialized - READY\r\n");

#ifdef SPI_DBG
    while (1)

    {
        if (SPIDEV1_transfer(Tx_spi, RX_spi, NO_OF_BYTES) == 0)
            printf("(Main)spidev1.0: Transaction Complete\r\n");

        else
            printf("(Main)spidev1.0: Transaction Failed\r\n");
        usleep(100000);
        printf("%d\r\n", ++i);
    }
#endif
}

