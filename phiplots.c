
/*****************************************
**					**
**	 Plot phi E v with time		**
**					**
******************************************/

#include "es.h"

FILE *plot_file;

void phiplots(void)
{
    char cfile[40];
    int i;


    sprintf(cfile,"phiet.data");

    plot_file = fopen(cfile,"w");

    for (i=0; i<=nt; i++)
    {
	fprintf(plot_file, "%d	%f	%f\n", i, phi_mid[i], Ex_mid[i]);
    }

    fclose(plot_file);



    sprintf(cfile,"v.data");

    plot_file = fopen(cfile,"w");

    for (i=0; i<ne; i++)
    {
	fprintf(plot_file, "%f	%f\n", vm[i], vx[i]);
    }

    fclose(plot_file);



    sprintf(cfile,"Energy.data");

    plot_file = fopen(cfile,"w");

    for (i=1; i<=nt; i++)
    {
        fprintf(plot_file, "%d  %f	%f\n", i, TotalEnergy[i], Energy_P_EP[i]);
    }

    fclose(plot_file);


    sprintf(cfile,"xt.data");

    plot_file = fopen(cfile,"w");

    for (i=1; i<=nt; i++)
    {
        fprintf(plot_file, "%d  %f	%f	%f	%f	%f\n", i, x_time[0][i], x_time[1][i], x_time[2][i], x_time[3][i], x_time[4][i]);
    }

    fclose(plot_file);


    if ( energic_particle != 0 )
    {
    sprintf(cfile,"xept.data");

    plot_file = fopen(cfile,"w");

    for (i=1; i<=nt; i++)
    {
        fprintf(plot_file, "%d  %f      %f      %f      %f      %f\n", i, x_EP_time[0][i], x_EP_time[1][i], x_EP_time[2][i], x_EP_time[3][i], x_EP_time[4][i]);
    }

    fclose(plot_file);
    }
}
