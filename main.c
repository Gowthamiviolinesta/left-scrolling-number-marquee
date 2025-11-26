#include <xc.h>
#include "ssd_display.h"

unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, BLANK, BLANK};

void init_config(void)
{
    init_ssd_control();
}

void main(void)
{
    init_config();
    unsigned char ssd[4];
    unsigned long wait = 0;
    unsigned char i = 0;

    while (1)
    {
        // always refresh SSD
        ssd[0] = digit[i % 12];
        ssd[1] = digit[(i + 1) % 12];
        ssd[2] = digit[(i + 2) % 12];
        ssd[3] = digit[(i + 3) % 12];
        display(ssd);

        // non-blocking
        if (++wait >= 500)
        {
            wait = 0;
            i++;                // update index after 1st iteration
        }
    }
}
