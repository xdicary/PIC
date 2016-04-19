
/*************************************************
 **						**
 **      Field calculation - slab geometry	**
 **						**
 *************************************************/

#include "es.h"

extern void tdma(void);

void field(void)
{
    int j;
    float edc;

    /* Add neutral background to get net density */
 
    for (j=0; j<=nx; j++)
        { rhot[j] = rho[j] + rho0; }
      
    /* Use tridiagonal matrix algorithm to solve Poisson equation and work out the potential from the density of charge */

    tdma();

    /* Field is calculated by central difference */

    Ex[0] = ( phi[0] - phi[1] )/dx;

    for (j=1; j<=nx-1; j++)
        Ex[j] = ( phi[j-1] - phi[j+1] )/dx/2.0;

    Ex[nx] = ( phi[nx-1] - phi[nx] )/dx;

    /* Record E&phi at the 50th grid  */

    Ex_50[i_time] = Ex[50];
    phi_50[i_time] = phi[50];
}
 
