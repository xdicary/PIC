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

#define MaxParticle 100001
#define MaxEP 6001
#define MaxGrid 401
#define MaxTime 60001


/* particle arrays */ 

double x[MaxParticle];
double vm[MaxParticle];
double vx[MaxParticle];

double x_EP[MaxParticle];
double vx_EP[MaxEP];

/* grid arrays */

double rho_plasma[MaxGrid];
double rho_EP[MaxGrid];
double rho_all[MaxGrid];
double rhot[MaxGrid];
double Ex[MaxGrid];
double phi[MaxGrid];
double pphi[MaxGrid];

double Ex_mid[MaxTime];
double phi_mid[MaxTime];

double Energy_E[MaxTime];
double Energy_P[MaxTime];
double TotalEnergy[MaxTime];

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

 int perturbation_switch;
 int energic_particle;

/* diagnostic parameters */
 
 int  iout;                     /* frequeny of printed output */
 int  igraph;                   /* frequeny of graphical output */
 int  ihist;                    /* frequeny of time-history output */

