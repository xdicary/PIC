#
#	Makefile for 'espic' - electrostatic PIC code
#       - see file es.h for file descriptions.
#

# default flags - optimisation level 2
# - check local compiler for details ('man cc') 

#FFLAGS = -w -O2

# with debug option
FFLAGS = -w 

# math library

LIBS = -lm

#  compiler

FC = cc

#  sources

SRCS =  espic.c init.c  loadx.c  loadv.c  loadx_EP.c  loadv_EP.c  density.c  field.c diagnostics.c \
        plots.c  push.c  boundaries.c histories.c phiplots.c input.c tdma.c perturbation.c


#  objects

OBJS = espic.o  init.o  loadx.o  loadv.o  loadx_EP.o  loadv_EP.o  density.o  field.o diagnostics.o \
       plots.o  push.o boundaries.o  histories.o phiplots.o input.o tdma.o perturbation.o

#  rules for compiling objects

.c.o:
	$(FC) -c $(FFLAGS) $<


espic:   $(OBJS)
	$(FC) $(FFLAGS) $(LIBS) -o espic $(OBJS)


clean:
	rm -f espic *.o *~ *.dat *.data





