#include "es.h"
#include "math.h"

void perturbation(void)
{
    int j;
    if ( perturbation_switch == 1 )
    {
	for ( j=1; j<=nx; j++ )
	    rho1[j] = rho1[j] + 1.0*sin(2.0*pi*(0.1*j+0.25*i_time));	/* v = omega/k */
    }
}
