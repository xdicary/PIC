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
extern void loadx(void);		/* particle loading - positions */
extern void loadv(void);		/* particle loading - velocities */
extern void density(void);		/* density gather */
extern void field(void);		/* Poisson solver */
extern void push(void);			/* particle pusher */
extern void boundaries(void);		/* particle boundary conditions */
extern void diagnostics(void);		/* diagnostic routine */

FILE *history_file;			/* file for writing out time histories */            

int main() 
{

    int i;

    history_file = fopen("hist.data", "w");

    init();				/* do initialisation */

    loadx();				/* load particles onto grid */

    loadv();				/* define velocity distribution */

    density();				/* compute initial density from particles */

    field();				/* compute initial electric field */

    diagnostics();			/* output initial conditions */

 
    for (i_time=1; i_time<=nt; i_time++) 
    {

        push();				/* push particles */

        boundaries();			/* particle boundary conditions */

        density();			/* compute density */

        field();			/* compute electric field (Poisson) */

        diagnostics();			/* output snapshots and time-histories */

    }


    close(history_file);          /*   close time-hist files */

}
