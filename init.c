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

    i_time = 0;		 	/* initialise time counter */

    /* derived parameters */

    dx = grid_length/nx;	/*  mesh size */

    omega_p = sqrt(rho0);	/* plasma frequency */

    lambda_d = vte/omega_p;	/* Debye length */

    xdodx = lambda_d/dx;	/* ratio */

    ncell = ne/nx;		/* # particles per cell */

    if( energic_particle != 0 )
	ncell = (ne+ne_EP)/nx;

    for (i=0; i<=nx; i++)
	pphi[i] = 0.0;

    if (bc_particle >= 2)
    {
         /**  for reflective bcs to work properly, must place particle
              boundaries half a mesh spacing inside field boundaries  **/

         wall_left = dx/2.;
         wall_right = grid_length-dx/2.;
         plasma_end = wall_right;               /* actually want min(end,wr) */
    }
    else
    {
         /*  periodic boundaries */

         wall_left = 0.;
         wall_right = grid_length;
         plasma_start = 0.;
         plasma_end = grid_length;
    }

    xload = plasma_end - plasma_start;          /* length for particle loading */

    qe = -rho0*xload/ne;

    e_mass = qe / q_over_me;


    /* printf("time: %f, x: %f, y: %f\n", time, x, y); */  

    printf("\n Input parameters: \n\n");
    printf("# particles = %d\n", ne);

    if( energic_particle != 0 )
	printf("# EP = %d\n", ne_EP);

    printf("# mesh points = %d\n", nx);
    printf("# particles/cell = %d\n", ncell);
    printf("grid length = %f\n\n", grid_length);

    printf("\nthermal velocity = %f\n",vte);
    printf("mesh size = %f\n",dx);
    printf("Debye length = %f\n\n",lambda_d);

    printf("timestep = %f\n",dt);
    printf("# timesteps = %d\n", nt);
    printf("run time = %f\n",dt*nt);

}
