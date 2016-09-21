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

    int ncell;
    double xdodx;

/*    double x[ne];
    double vm[ne];
    double vx[ne];

    double rho[nx];
    double rhot[nx];
    double Ex[nx];
    double phi[nx];
    double pphi[nx];

    double Ex_50[nt];
    double phi_50[nt];
*/

    i_time = 0;		 	/* initialise time counter */


    /* derived parameters */

    dx = grid_length/nx;	/*  mesh size */

    omega_p = sqrt(rho0);	/* plasma frequency */

    lambda_d = vte/omega_p;	/* Debye length */

    xdodx = lambda_d/dx;	/* ratio */

    ncell = ne/nx;		/* # particles per cell */

    for (i=0; i<nx; i++)
	pphi[i] = 0.0;

    /* printf("time: %f, x: %f, y: %f\n", time, x, y); */  

    printf("\n Input parameters: \n\n");
    printf("# particles = %d\n", ne);
    printf("# mesh points = %d\n", nx);
    printf("# particles/cell = %d\n", ncell);
    printf("grid length = %f\n\n", grid_length);

    /*
    int k;
    int r[5];
    for (k=0; k<5; k++)
    {r[k] = random();}
    printf("Random_Max = %d\n", random_max);
    for (k=0; k<5; k++)
    {printf("Random_now = %d\n", r[k]);}
    */

    printf("\nthermal velocity = %f\n",vte);
    printf("mesh size = %f\n",dx);
    printf("Debye length = %f\n\n",lambda_d);

    printf("timestep = %f\n",dt);
    printf("# timesteps = %d\n", nt);
    printf("run time = %f\n",dt*nt);

}
