
/*********************************************************
 **							**
 **      Direct field integration - slab geometry	**
 **							**
 *********************************************************/

#include "es.h"

extern void tdma(void);

void field(void)
{
    int j;
    float edc;

    /* Add neutral background to get net density */
 
    for (j=0; j<=nx; j++)
        { rhot[j] = rho[j] + rho0; }
      
    /* integrate div.E=rho directly (trapezium approx) */

    /* end point - ex=0 mirror at right wall */

    /* integrate from right to left */

/*    Ex[nx+1] = 0.0;
    edc = 0.0;

    for (j=nx; j>=1; j--)
    {
	Ex[j] = Ex[j+1] - 0.5*( rhot[j] + rhot[j+1] )*dx;
        edc = edc + Ex[j];
    }

    if (bc_field == 1)
    {*/
	/* periodic fields:  subtract off DC component */ 
	/* -- need this for consistency with charge conservation */
      
/*	for (j=1; j<=nx; j++)
    	    { Ex[j] -= edc/nx; }
*/          
	/*  end points periodic */
/*	Ex[0] = Ex[nx];
    }
*/
    /* potential - same again */
    /* - integration const. is arbitrary - phi not used for anything at present */
/*
    phi[nx+1] = 0.0;

    for (j=nx; j>=1; j--)
    {
	phi[j] = phi[j+1] + 0.5*( Ex[j] + Ex[j+1] )*dx;
    }

    phi[nx+1] = 0.0;
    phi[nx] = 0.0;
    for (j=nx-1; j>=1; j--)
    {
        phi[j] = 0.5*( rhot[j] + rhot[j+1] )*dx*dx - phi[j+2] + 2*phi[j+1];
        edc = edc + phi[j];
    }

    if (bc_field == 1)
    {
        for (j=1; j<=nx; j++)
            { phi[j] -= edc/nx; }
        phi[0] = phi[nx];
    }

    for (j=nx; j>=1; j--)
        Ex[j] = ( phi[j] - phi[j+1] )/dx;
*/
/*    phi[0] = rhot[0];

    for (j=1; j<nx+1; j++)
        phi[j] = ( rhot[j-1] - rhot[j] )/3.0;

    for (j = nx; j-->0;)
        phi[j] = phi[j] + phi[j+1]/3.0;
*/
    tdma();

    Ex[0] = ( phi[0] - phi[1] )/dx;
    for (j=1; j<=nx-1; j++)
        Ex[j] = ( phi[j-1] - phi[j+1] )/dx/2.0;
    Ex[nx] = ( phi[nx-1] - phi[nx] )/dx;

    Ex_50[i_time] = Ex[50];
    phi_50[i_time] = phi[50];
}
 
