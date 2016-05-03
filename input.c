/*************************************************
**						**
**		Parameters input		**
**						**
**************************************************/


#include "es.h"

void input(void)
{
    /* set up simulation parameters */

    nt = 2000;			/* # timesteps  */
    nx = 100;                   /* # grid points */

    ne = 102000;		/* # electrons   */
    ni = 0;                     /* # ions (fixed) */

    grid_length = 100.0;        /* size of spatial grid */
    plasma_start = 0.;          /* plasma edge */

    dt = 0.1;			/* normalised timestep */

    q_over_me = -1;             /* electron charge:mass ratio */

    rho0 = 1.0;			/* background ion density */
    vte = 1.4;			/* thermal velocity */

    bc_field = 1;               /* field boundary conditions:  1 = periodic, */
                                /*                             2 = reflective */

    bc_particle = 1;            /* particle BCs:  1 = periodic, */
                                /*                2 = reflective, */
                                /*                3 = thermal */

    ihist = 1;                  /* frequency of time-history output */
    igraph = 50;                /* freq. of graphical snapshots */
    iout = 10;                  /* freq. of printed diags. */
}
