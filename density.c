/*****************************************
 **					**
 **	      Electron density		**
 **					**
 *****************************************/

#include "es.h"

void density(void)
{
    double re, xa, f1, f2;
    int i, j, j1, j2, iwl, iwr;

/*    qe = -rho0*xload/ne;
    if ( energic_particle != 0 )
	qe = -rho0*xload/(ne+ne_EP);

    e_mass = qe/q_over_me;
*/
/*    re = qe/dx;			/*  charge weighting factor */
    re = -rho0*xload/((ne+ne_EP)*dx);


    for (i=0; i<=nx; i++)
    {
	rho1[i] = 0.0;
	rho2[i] = 0.0;
	rhoall[i] = 0.0;
    }

    /* gather density onto grid from particles */

    for (i=0; i<ne; i++)
    {
        xa = x[i]/dx;
        j1 = xa;
        j2 = j1 + 1;
        f2 = xa - j1;
        f1 = 1.0 - f2;
        rho1[j1] = rho1[j1] + re*f1;
        rho1[j2] = rho1[j2] + re*f2;
    }

    if ( energic_particle != 0 )
    {
	for (i=0; i<ne_EP; i++)
	{

/*	if (i_time == 759)
	{
		printf("error");
	}
*/            xa = x_EP[i]/dx;
            j1 = xa;
            j2 = j1 + 1;
            f2 = xa - j1;
            f1 = 1.0 - f2;
            rho2[j1] = rho2[j1] + re*f1;            
	    rho2[j2] = rho2[j2] + re*f2;
	}
    }

    for (j=0; j<=nx; j++)
    {
        rhoall[j] = rho1[j] + rho2[j];
    }

    if (bc_field == 1)
    {
        /* periodic boundaries */
        rhoall[0] += rhoall[nx];
        rhoall[nx] = rhoall[0];
    }

    else
        /* bc_field =2 */
    {
        /* reflective - 1st and last (ghost) cells folded back onto physical grid */
        iwl = wall_left/dx;
        rhoall[iwl+1] += rhoall[iwl];
        rhoall[iwl] = 0.0;

        iwr = wall_right/dx;
        rhoall[iwr] += rhoall[iwr+1];
        rhoall[iwr+1] = rhoall[iwr];
    }
}
