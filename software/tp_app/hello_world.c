/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "system.h"
static const uint8_t digit2segments[16] = {
 0b11000000, /* 0 */
 0b11111001, /* 1 */
 0b10100100, /* 2 */
 0b10110000, /* 3 */
 0b10011001, /* 4 */
 0b10010010, /* 5 */
 0b10000010, /* 6 */
 0b11111000, /* 7 */
 0b10000000, /* 8 */
 0b10010000, /* 9 */
 0b10001000, /* A */
 0b10000011, /* b */
 0b11000110, /* C */
 0b10100001, /* d */
 0b10000110, /* E */
 0b10001110 /* F */
};

int main()
{
    printf("Hello from Nios II!\n");

    /* Utilisation des adresses dynamiques générées dans system.h */
    volatile uint32_t *led_pio = (uint32_t *)LED_BASE;
    volatile uint32_t *sw_pio = (uint32_t *)SW_BASE;

    volatile uint32_t *hex3_0_pio = (volatile uint32_t *)HEX3_0_BASE;
    volatile uint32_t *hex5_4_pio = (volatile uint32_t *)HEX5_4_BASE;

    uint32_t count = 0;
    uint32_t pattern = 0;

    while (1) {
        uint32_t sw_value = *sw_pio; /* Lit l'état des interrupteurs */
        *led_pio = sw_value;         /* Recopie l'état sur les LEDs */

        /* Extraction des 5 chiffres décimaux */
                uint8_t d0 = count % 10;            /* Unitės (HEX0) */
                uint8_t d1 = (count / 10) % 10;     /* Dizaines (HEX1) */
                uint8_t d2 = (count / 100) % 10;    /* Centaines (HEX2) */
                uint8_t d3 = (count / 1000) % 10;   /* Milliers (HEX3) */
                uint8_t d4 = (count / 10000) % 10;  /* Dizaines de milliers (HEX4) */

                /* Construction du motif pour HEX3 à HEX0 */
                uint32_t pattern3_0 = 0;
                pattern3_0 |= (uint32_t)digit2segments[d0];
                pattern3_0 |= ((uint32_t)digit2segments[d1] << 8);
                pattern3_0 |= ((uint32_t)digit2segments[d2] << 16);
                pattern3_0 |= ((uint32_t)digit2segments[d3] << 24);
                *hex3_0_pio = pattern3_0;

                /* Construction du motif pour HEX5 et HEX4 (HEX5 éteint avec 0xFF) */
                uint32_t pattern5_4 = 0;
                pattern5_4 |= (uint32_t)digit2segments[d4]; /* HEX4 */
                pattern5_4 |= ((uint32_t)0xFF << 8);        /* HEX5 (éteint) */
                *hex5_4_pio = pattern5_4;

                /* Incrémenter le compteur et reboucler à 0 après 99999 */
                count++;
                if (count > 99999) {
                    count = 0;
                }        /* Boucle d'attente avec point-virgule correct */
        for (volatile int i = 0; i < 50000; i++);

        printf("count = %d\n", (int)count);
    }

    return 0;
}

