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

    int ncell;
    float xdodx;

    /* set up simulation parameters */

    nt = 100;			/* # timesteps  */
    nx = 100;			/* # grid points */

    ne = 1000;			/* # electrons   */
    ni = 0;			/* # ions (fixed) */
     
    grid_length = 100.0;	/* size of spatial grid */
    plasma_start = 0.;		/* LH plasma edge */

    dt = 0.2;			/* normalised timestep */
     
    q_over_me=-1.0;		/* electron charge:mass ratio */

    rho0 = 1.0;			/* background ion density */
    vte = 0.1;			/* thermal velocity */

    bc_field = 1;		/* field boundary conditions:  1 = periodic, */
				/*                             2 = reflective */

    bc_particle = 1;  		/* particle BCs:  1 = periodic, */
                       		/*                2 = reflective, */
                       		/*                3 = thermal */

    ihist = 1;         		/* frequency of time-history output */
    igraph = 50;      		/* freq. of graphical snapshots */
    iout = 10;         		/* freq. of printed diags. */

    i_time = 0;		 	/* initialise time counter */


    /* derived parameters */

    dx = grid_length/nx;	/*  mesh size */

    omega_p = sqrt(rho0);	/* plasma frequency */

    lambda_d = vte/omega_p;	/* Debye length */

    xdodx = lambda_d/dx;	/* ratio */

    ncell = ne/nx;		/* # particles per cell */

    /* printf("time: %f, x: %f, y: %f\n", time, x, y); */  

    printf("\n Input parameters: \n\n");
    printf("# particles = %d\n", ne);
    printf("# mesh points = %d\n", nx);
    printf("# particles/cell = %d\n", ncell);
    printf("grid length = %f\n\n", grid_length);

    int k;
    int r[5];
    for (k=0; k<5; k++)
    {r[k] = random();}
    printf("Random_Max = %d\n", random_max);
    for (k=0; k<5; k++)
    {printf("Random_now = %d\n", r[k]);}

    printf("\nthermal velocity = %f\n",vte);
    printf("mesh size = %f\n",dx);
    printf("Debye length = %f\n\n",lambda_d);

    printf("timestep = %f\n",dt);
    printf("# timesteps = %d\n", nt);
    printf("run time = %f\n",dt*nt);

}
