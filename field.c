
/*************************************************
 **						**
 **      Field calculation - slab geometry	**
 **						**
 *************************************************/

#include "es.h"
#include "math.h"

extern void tdma(void);

void field(void)
{
    int j;

    /* Add neutral background to get net density */
 
    for (j=0; j<=nx; j++)
	rhot[j] = rho[j] + rho0;

    /* Use tridiagonal matrix algorithm to solve Poisson equation and work out the potential from the density of charge */

    tdma();

    if ( perturbation_switch == 2 )
    {
/*	for (j=nx; j>71; j--)
	{
	    pphi[j] = pphi[j-22];
	    phi[j] = phi[j] + pphi[j];
	}
	for (j=0; j<29; j++)
	{
	    pphi[j] = pphi[j+22];
	    phi[j] = phi[j] + pphi[j];
	}

	for (j=29; j<=71; j++)
	{
	    pphi[j] = 0.5*sin(2.0*pi*(0.1*(j-50)+0.22*i_time));
	    phi[j] = phi[j] + pphi[j];
	}
*/
	if ( i_time%22 == 0 )
	{
	for (j=nx; j>0; j--)
	{
	    pphi[j] = pphi[j-1];
	    phi[j] = phi[j] + pphi[j];
	}
	pphi[0] = 0.1*sin(2.0*pi*0.22*i_time);
	phi[0] = phi[0] + pphi[0];
	}
	else
	{
	for (j=nx; j>=0; j--)
	    phi[j] = phi[j] + pphi[j];
	}
    }

    /* Field is calculated by central difference */

    Ex[0] = ( phi[0] - phi[1] )/dx;

    for (j=1; j<=nx-1; j++)
        Ex[j] = 0.5*( phi[j-1] - phi[j+1] )/dx;

    Ex[nx] = ( phi[nx-1] - phi[nx] )/dx;

/*    for (j=0; j<nx; j++)
	Ex[j] = ( phi[j+1] - phi[j] )/dx;

    Ex[nx] = Ex[nx-1];
*/
    /* Record E&phi at the 50th grid  */

    Ex_50[i_time] = Ex[50];
    phi_50[i_time] = phi[50];
}
 
