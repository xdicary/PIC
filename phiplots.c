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
fprintf(plot_file, "%d	%f	%f\n", i, phi_50[i], Ex_50[i]);
}
fclose(plot_file);
}
