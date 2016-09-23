
/*************************************************
 **						**
 **   Particle loading for uniform density	**
 **						**
 *************************************************/

#include "es.h"

/* local variables */

double dpx;					/* particle spacing */ 
int i;						/* counter */

void loadx_EP(void)
{
    dpx = xload/ne_EP;				/* particle spacing */

    /* set up initial positions */

    for (i = 0; i < ne_EP; i++)
    { 
        x_EP[i] = plasma_start + dpx*(i-0.5);
    }
}
