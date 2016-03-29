/*************************************************
 **						**
 **    Set up particle velocity distribution	**
 **						**
 *************************************************/


#include "es.h"
#include "math.h"
#include "time.h"

void loadv(void)
{

    int i, j;
    float a[2], x, rs, theta;

    for (i = 1; i<=ne; i++)
    {
	for (j = 0; j<2; j++)
	    a[j] = (float) random() / random_max;

        x = (float) -exp*a[1]*log(a[1]);

	while (a[0]*a[0] > x)
	    for (j = 0; j<2; j++)
		a[j] = (float) random() / random_max;

	vm[i] = (float) vte*sqrt(-1.5*log(a[1]));

	rs = (float) random() / random_max;
	theta = 2*pi*rs;			/* random angle */

	vx[i] = vm[i]*sin(theta);		/* x-component of velocity */
    }

}
