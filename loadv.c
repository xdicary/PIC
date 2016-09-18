/*************************************************
 **						**
 **    Set up particle velocity distribution	**
 **						**
 *************************************************/


#include "es.h"
#include "math.h"
#include "time.h"

void loadv(int ne, double vx[])
{

    int i, j;
    double a[2], b, xx, rs, theta;

    for (i = 0; i<ne; i++)
    {

	for (j = 0; j<2; j++)
	    a[j] = (double) random() / random_max;

	xx = (double) -exp*a[1]*log(a[1]);

	while (a[0]*a[0] > xx)
	    for (j = 0; j<2; j++)
		a[j] = (double) random() / random_max;

	vm[i] = (double) vte*sqrt(-1.5*log(a[1]));
    
	rs = (double) random() / random_max;
	theta = 2*pi*rs;                        /* random angle */

	vx[i] = vm[i]*sin(theta);               /* x-component of velocity */

    }

}
