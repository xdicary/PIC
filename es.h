/*************************************************  
 **						**
 **			es.h			**
 **						**
 ** 	Header file for pices.c 		**
 ** 	containing global arrays and variables	**
 ** 						**
 *************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
   
#define pi 3.14159265
#define exp 2.71828185
#define random_max 2147483647   /* max. allowed integer (32-bit) */
#define NP_MAX 1000001             /* max. # particles */
#define NX_MAX 1001              /* max. # grid points */
#define Q = 1.602e-19
#define Me = 9.109e-31
#define K = 1.381e-23
#define EPS0 = 8.854e-12

/* particle arrays */ 

 float x[NP_MAX];               /* position */
 float vm[NP_MAX];              /* velocity */ 
 float vx[NP_MAX];		/* velocity_x */

/* grid arrays */

 float rho[NX_MAX];             /* electron density */
 float rhot[NX_MAX];		/* net density */
 float Ex[NX_MAX];              /* electric field */ 
 float phi[NX_MAX];             /* potential */
 float Ex_50[1000];
 float phi_50[1000];

/* plasma constants, parameters */

 float qe;                      /* macro-electron charge */
 float vte;                     /* thermal velocity */
 float q_over_me;               /* charge/mass ratio */
 float e_mass;                  /* macro-electron mass */
 float xload;                   /* plasma length */
 float plasma_start;            /* LH edge of plasma */
 float plasma_end;              /* RH edge of plasma */
 float wall_left;               /* LH particle boundary */
 float wall_right;              /* RH particle boundary */
 float rho0;                    /* background (ion) density */
 float grid_length;             /* grid length */
 float omega_p;                 /* plasma frequency */
 float lambda_d;                /* Debye-length */ 

 int ne, ni;                    /* # simulation electrons, ions */

/* grid variables */

 int  nt;                       /* # timesteps */
 int  i_time;                   /* current timestep */
 float  dt;                     /* timestep */

 long  nx;                       /* # grid points */
 float  dx;                     /* mesh size */

 int  bc_particle;              /* particle boundary condition switch */
 int  bc_field;                 /* field boundary condition */

/* diagnostic parameters */
 
 int  iout;                     /* frequeny of printed output */
 int  igraph;                   /* frequeny of graphical output */
 int  ihist;                    /* frequeny of time-history output */

