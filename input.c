/*************************************************
**						**
**		Parameters input		**
**						**
**************************************************/


#include "es.h"

void input(void)
{
    /* set up simulation parameters */

    nt = 50000;			/* # timesteps  */
    nx = 500;                   /* # grid points */

    ne = 100000;		/* # electrons   */
    ni = 0;                     /* # ions (fixed) */

    ne_EP = 5000;
    ni_EP = 0;

    grid_length = 100.0;        /* size of spatial grid */
    plasma_start = 0.;          /* plasma edge */

    dt = 0.01;			/* normalised timestep */

    q_over_me = -1;             /* electron charge:mass ratio */

    rho0 = 1.0;			/* background ion density */
    vte = 1.0;			/* thermal velocity */


    energic_particle = 0;       /* 0 = no energic particles,    */
                                /* 1 = energic electrons,       */
                                /* 2 = energic ions             */


    perturbation_switch = 0;	/* 0 = no perturbation, 			*/
				/* 1 = perturbation on initial density,		*/
				/* 2 = perturbation on boundary potential	*/

    bc_field = 1;               /* field boundary conditions:  1 = periodic, */
                                /*                             2 = reflective */

    bc_particle = 1;            /* particle BCs:  1 = periodic, */
                                /*                2 = reflective, */
                                /*                3 = thermal */

    ihist = 1;                  /* frequency of time-history output */
    igraph = 5000;                /* freq. of graphical snapshots */
    iout = 1000;			/* freq. of printed diags. */
}
