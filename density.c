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

    re = qe/dx;			/*  charge weighting factor */

    if (energic_particle != 0)
	re = re*ne/(ne+ne_EP);
     
    for (j=0; j<=nx+1; j++) 
    {
	rho_plasma[j] = 0.0;
	rho_EP[j] = 0.0;
	rho_all[j] = 0.0;
    }

    /* gather density onto grid from particles */

    for (i=0; i<ne; i++)
    {
        xa = x[i]/dx;
        j1 = xa;
        j2 = j1 + 1;
        f2 = xa - j1;
        f1 = 1.0 - f2;
        rho_plasma[j1] = rho_plasma[j1] + re*f1;
        rho_plasma[j2] = rho_plasma[j2] + re*f2;
    }

    if ( energic_particle != 0 )
    {
        for (i=0; i<ne_EP; i++)
        {
            xa = x_EP[i]/dx;
            j1 = xa;
            j2 = j1 + 1;
            f2 = xa - j1;
            f1 = 1.0 - f2;
            rho_EP[j1] = rho_EP[j1] + re*f1;
            rho_EP[j2] = rho_EP[j2] + re*f2;
        }
    }

    for (j=0; j<=nx+1; j++)
	rho_all[j] = rho_plasma[j] + rho_EP[j];

    if (bc_field == 1)
    {
        /* periodic boundaries */ 
        rho_all[0] += rho_all[nx];
        rho_all[nx] = rho_all[0];
    }

    else     			
	/* bc_field =2 */
    {
        /* reflective - 1st and last (ghost) cells folded back onto physical grid */
        iwl = wall_left/dx;
        rho_all[iwl+1] += rho_all[iwl];
        rho_all[iwl] = 0.0;	

        iwr = wall_right/dx;
        rho_all[iwr] += rho_all[iwr+1];
        rho_all[iwr+1] = rho_all[iwr];
    }     

}
