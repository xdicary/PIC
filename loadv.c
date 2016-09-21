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

    for (i = 1; i<ne; i=i+2)
    {

/*	if ( i%10 == 0 )
	{
	b = (double) random() / random_max;
	if ( b < 0.5 )
	    vx[i] = 0.2*log(2.0*b);
	else
	    vx[i] = -0.2*log(2.0*(1-b));
        vx[i] = vx[i]+2.5;
	}
	else	*/
/*
	{
	for (j = 0; j<2; j++)
	    a[j] = (double) random() / random_max;

        x = (double) -exp*a[1]*log(a[1]);

	while (a[0]*a[0] > x)
	    for (j = 0; j<2; j++)
		a[j] = (double) random() / random_max;

	vm[i] = (double) vte*sqrt(-1.5*log(a[1]));

	rs = (double) random() / random_max;
	theta = 2*pi*rs;

	vx[i] = vm[i]*sin(theta);		
	}
*/
	for (j=0; j<2; j++)
	    a[j] = (double) random() / random_max;

	vx[i] = sqrt(-log(a[0]))*cos(2*pi*a[1]);
	vx[i+1] = sqrt(-log(a[0]))*sin(2*pi*a[1]);

    }

}
