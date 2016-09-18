
/*************************************************
 **						**
 **   Particle loading for uniform density	**
 **						**
 *************************************************/

#include "es.h"

void loadx(int ne, double x[])
{
    double dpx;                                     /* particle spacing */
    int i;                                          /* counter */

    dpx = xload/ne;

    /* set up initial positions */

    for (i = 0; i < ne; i++)
    { 
        x[i] = plasma_start + dpx*(i-0.5);
    }
}
