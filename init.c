/*********************************************************
 **							**
 **			 init.c				**
 **							**
 **     initialise main particle and grid variables	**
 **							**
 *********************************************************/


#include <stdio.h>
#include <math.h>
#include "es.h"

void init(void)
{

    /* local variables */

    int i;

    int ncell, epcell;
    double xdodx;

    i_time = 0;		 	/* initialise time counter */


    /* derived parameters */

/*    dt = dt*2*pi;*/

    dx = grid_length/nx;	/* mesh size */

    omega_p = sqrt(rho0);	/* plasma frequency */

    lambda_d = vte/omega_p;	/* Debye length */

    xdodx = lambda_d/dx;	/* ratio */

    ncell = ne/nx;		/* # particles per cell */

    epcell = ne_EP/nx;

    for (i=0; i<=nx; i++)
	pphi[i] = 0.0;

    for ( i=0; i<=nt; i++ )
    {
	Energy_P[i] = 0.0;
	Energy_E[i] = 0.0;
	Energy_P_EP[i] = 0.0;
	TotalEnergy[i] = 0.0;
    }

    /* printf("time: %f, x: %f, y: %f\n", time, x, y); */  

    printf("\n Input parameters: \n\n");
    printf("# mesh points = %d\n", nx);
    printf("# plasma particles = %d\n", ne);
    printf("# plasma particles/cell = %d\n", ncell);

    if (energic_particle != 0)
    {
	printf("# EP = %d\n", ne_EP);
	printf("# EP/cell = %d\n", epcell);
    }

    printf("grid length = %f\n\n", grid_length);

    printf("\nthermal velocity = %f\n",vte);
    printf("mesh size = %f\n",dx);
    printf("Debye length = %f\n\n",lambda_d);

    printf("timestep = %f\n",dt);
    printf("# timesteps = %d\n", nt);
    printf("run time = %f\n",dt*nt);

    dt = dt*2*pi;

}
