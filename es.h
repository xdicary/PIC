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

/* particle arrays */ 

/* extern double x[];		/* position */
/* extern double vm[];		/* velocity */
/* extern double vx[];		/* velocity_x */
double x[50001];
double vm[50001];
double vx[50001];

/* grid arrays */

/* extern double rho[];		/* electron density */
/* extern double rhot[];		/* net density */
/* extern double Ex[];		/* electric field */
/* extern double phi[];		/* potential */
/* extern double pphi[];		/* perturbation potential */
double rho[101];
double rhot[101];
double Ex[101];
double phi[101];
double pphi[101];

/* extern double Ex_50[];*/
/* extern double phi_50[];*/
double Ex_50[2001];
double phi_50[2001];

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

/* grid variables */

 int  nt;                       /* # timesteps */
 int  i_time;                   /* current timestep */
 double  dt;                     /* timestep */

 long  nx;                       /* # grid points */
 double  dx;                     /* mesh size */

 int  bc_particle;              /* particle boundary condition switch */
 int  bc_field;                 /* field boundary condition */

 int perturbation_switch;

/* diagnostic parameters */
 
 int  iout;                     /* frequeny of printed output */
 int  igraph;                   /* frequeny of graphical output */
 int  ihist;                    /* frequeny of time-history output */

