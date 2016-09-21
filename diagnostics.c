
/*********************************************************
 **							**
 **	Diagnostics - graphics and printed output	**
 **							**
 *********************************************************/

#include "es.h"

void diagnostics(void)
{

    /* write run information to terminal */

    if (i_time % iout == 0) 
    {
        printf("timestep: %d\n", i_time);
    }

    /* do graphics snapshots */

    if (i_time % igraph == 0) 
    {
        plots();
    }

    /* write out time-dep. quantities to file */
 
    if (i_time % ihist == 0) 
    {
        histories(); 
    }
}
