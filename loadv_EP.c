/*************************************************
 **						**
 **    Set up particle velocity distribution	**
 **						**
 *************************************************/


#include "es.h"
#include "math.h"
#include "time.h"

void loadv_EP(int ne_EP, double vx_EP[])
{

    int i;
    double b;

    for (i=0; i<ne_EP; i++)
    {
	b = (double) random() / random_max;

        if ( b < 0.5 )
	    vx_EP[i] = 0.2*log(2.0*b);

        else
	    vx_EP[i] = -0.2*log(2.0*(1-b));

        vx_EP[i] = vx_EP[i]+2.5;
    }
}
