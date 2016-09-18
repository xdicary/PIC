/************************************************* 
**						**
**	      Electrostatic PIC code 		**
**						**
**	  1d1v,  slab geometry, C version	**
**						**
**************************************************/

#include "es.h"				/* common variables */

/*  external routines  */

extern void init(void);			/* initialisation */ 
extern void loadx(int, double[]);		/* particle loading - positions */
extern void loadv(int, double[]);		/* particle loading - velocities */
extern void loadv_EP(int, double[]);
extern void density(void);		/* density gather */
extern void field(double[]);		/* Poisson solver */
extern void push(int, double[], double[], double[]);			/* particle pusher */
extern void boundaries(int, double[], double[]);		/* particle boundary conditions */
extern void diagnostics(void);		/* diagnostic routine */
extern void phiplots(void);
extern void input(void);
extern void perturbation(void);
/*extern void density_total(double[], double[]);*/


FILE *history_file;			/* file for writing out time histories */            

int main() 
{

    int i;

    history_file = fopen("hist.data", "w");

    input();

    init();				/* do initialisation */

    loadx(ne, x);				/* load particles onto grid */

    loadv(ne_EP, vx);				/* define velocity distribution */

    if (energic_particle != 0)
    {
	loadx(ne_EP, x_EP);

	loadv_EP(ne_EP, vx_EP);
    }

    density();				/* compute initial density from particles */

/*    density_total(rho1, rho2);*/

    perturbation();	

    field(rhoall);				/* compute initial electric field */

    diagnostics();			/* output initial conditions */

 
    for (i_time=1; i_time<=nt; i_time++) 
    {

        push(ne, x, Ex, vx);				/* push particles */

        boundaries(ne, x, vx);			/* particle boundary conditions */

        if (energic_particle != 0)
        {
	    push(ne_EP, x_EP, Ex, vx_EP);

	    boundaries(ne_EP, x_EP, vx_EP);
	}

        density();			/* compute density */

/*	density_total(rho1, rho2);*/

        field(rhoall);			/* compute electric field (Poisson) */

        diagnostics();			/* output snapshots and time-histories */

    }

    phiplots();

    close(history_file);          /*   close time-hist files */

}
