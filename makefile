#
#	Makefile for 'espic' - electrostatic PIC code
#       - see file es.h for file descriptions.
#

# default flags - optimisation level 2
# - check local compiler for details ('man cc') 

#FFLAGS = -w -O2

# with debug option
FFLAGS = -w -g

# math library

LIBS = -lm

#  compiler

FC = cc

#  sources

SRCS =  espic.c init.c  loadx.c  loadv.c density.c  field.c diagnostics.c \
        plots.c  push.c  boundaries.c histories.c phiplots.c


#  objects

OBJS = espic.o  init.o  loadx.o loadv.o  density.o  field.o diagnostics.o \
       plots.o  push.o boundaries.o  histories.o phiplots.o

#  rules for compiling objects

.c.o:
	$(FC) -c $(FFLAGS) $<


espic:   $(OBJS)
	$(FC) $(FFLAGS) $(LIBS) -o espic $(OBJS)


clean:
	rm -f espic *.o *~ *.dat *.data





