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
     
    for (j=0; j<=nx+1; j++) 
    { rho[j]=0.0; }		/* zero density array */

    /* gather density onto grid from particles */

    for (i=1; i<=ne; i++)
    {
        xa = x[i]/dx;
        j1 = xa;
        j2 = j1 + 1;
        f2 = xa - j1;
        f1 = 1.0 - f2;
        rho[j1] = rho[j1] + re*f1;
        rho[j2] = rho[j2] + re*f2;
    }


    if (bc_field == 1)
    {
        /* periodic boundaries */ 
        rho[0] += rho[nx];
        rho[nx] = rho[0];
    }

    else     			
	/* bc_field =2 */
    {
        /* reflective - 1st and last (ghost) cells folded back onto physical grid */
        iwl = wall_left/dx;
        rho[iwl+1] += rho[iwl];
        rho[iwl] = 0.0;	

        iwr = wall_right/dx;
        rho[iwr] += rho[iwr+1];
        rho[iwr+1] = rho[iwr];
    }     

}
