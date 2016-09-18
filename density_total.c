/*****************************************
 **					**
 **	      Electron density		**
 **					**
 *****************************************/

#include "es.h"

void density_total(double rho1[], double rho2[])
{
    int j, iwl, iwr;

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
