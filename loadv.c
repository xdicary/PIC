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
    double a[2], b, x, rs, theta;

    for (i = 1; i<=ne; i++)
    {

	if ( i%10 == 0 )	/* 10% */
	{
	b = (double) random() / random_max;
	if ( b < 0.5 )
	    vx[i] = 0.2*log(2.0*b);
	else
	    vx[i] = -0.2*log(2.0*(1-b));
        vx[i] = vx[i]+2.5;
	}
	else
	{
	for (j = 0; j<2; j++)
	    a[j] = (double) random() / random_max;

        x = (double) -exp*a[1]*log(a[1]);

	while (a[0]*a[0] > x)
	    for (j = 0; j<2; j++)
		a[j] = (double) random() / random_max;

	vm[i] = (double) vte*sqrt(-1.5*log(a[1]));

	rs = (double) random() / random_max;
	theta = 2*pi*rs;			/* random angle */

	vx[i] = vm[i]*sin(theta);		/* x-component of velocity */
	}
    }

}
