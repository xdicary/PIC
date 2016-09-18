/*************************************************  
 **						**
 **			es.h			**
 **						**
 ** 	      Header file for espic.c 		**
 **    containing global arrays and variables	**
 ** 						**
 *************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
   
#define pi 3.14159265
#define exp 2.71828185
#define random_max 2147483647   /* max. allowed integer (32-bit) */
#define Q = 1.602e-19
#define Me = 9.109e-31
#define K = 1.381e-23
#define EPS0 = 8.854e-12
#define Mi_over_Me = 1836
#define sqrtioe = 42.8486

#define MaxParticle 50001
#define MaxEP 5001
#define MaxGrid 101
#define MaxTimestep 3001

/* particle arrays */ 

double x[MaxParticle];		/* position */
double vm[MaxParticle];		/* velocity */
double vx[MaxParticle];		/* velocity_x */

double x_EP[MaxEP];		/* position of EP */
double vx_EP[MaxEP];		/* velocity_x of EP */

/* grid arrays */

double rho1[MaxGrid];		/* electron density */
double rho2[MaxGrid];		/* EP density*/
double rhoall[MaxGrid];		/* density of all */
double rhot[MaxGrid];		/* net density */
double Ex[MaxGrid];		/* electric field */
double phi[MaxGrid];		/* potential */
double pphi[MaxGrid];		/* perturbation potential */

double Ex_50[MaxTimestep];
double phi_50[MaxTimestep];

/* plasma constants, parameters */

 double qe;                      /* macro-electron charge */
 double vte;                     /* thermal velocity */
 double q_over_me;               /* charge/mass ratio */
 double e_mass;                  /* macro-electron mass */
 double xload;                   /* plasma length */
 double plasma_start;            /* LH edge of plasma */
 double plasma_end;              /* RH edge of plasma */
 double wall_left;               /* LH particle boundary */
 double wall_right;              /* RH particle boundary */
 double rho0;                    /* background (ion) density */
 double grid_length;             /* grid length */
 double omega_p;                 /* plasma frequency */
 double lambda_d;                /* Debye-length */ 

 int ne, ni;                    /* # simulation electrons, ions */

 int ne_EP, ni_EP;

/* grid variables */

 int  nt;                       /* # timesteps */
 int  i_time;                   /* current timestep */
 double  dt;                     /* timestep */

 long  nx;                       /* # grid points */
 double  dx;                     /* mesh size */

 int  bc_particle;              /* particle boundary condition switch */
 int  bc_field;                 /* field boundary condition */

 int energic_particle;
 int perturbation_switch;

/* diagnostic parameters */
 
 int  iout;                     /* frequeny of printed output */
 int  igraph;                   /* frequeny of graphical output */
 int  ihist;                    /* frequeny of time-history output */

