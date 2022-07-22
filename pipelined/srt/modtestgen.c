/* testgen.c */

/* Written 7/21/2022 by Cedar Turek

   This program creates test vectors for modulo
   calculation from integer divide.
   */

/* #includes */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constants */

#define ENTRIES  10
#define RANDOM_VECS 500

/* Prototypes */

void output(FILE *fptr, long a, long b, long rem);
void printhex(FILE *fptr, long x);
double random_input(void);

/* Main */

void main(void)
{
  FILE *fptr;
  long a, b, rem;
  long list[ENTRIES] = {1, 3, 5, 18, 25, 33, 42, 65, 103, 255};
  int i, j;

  if ((fptr = fopen("modtestvectors","w")) == NULL) {
    fprintf(stderr, "Couldn't write testvectors file\n");
    exit(1);
  }

  for (i=0; i<ENTRIES; i++) {
    b = list[i];
    for (j=0; j<ENTRIES; j++) {
      a = list[j];
      rem = a%b;
      output(fptr, a, b, rem);
    }
  }

  fclose(fptr);
}

/* Functions */

void output(FILE *fptr, long a, long b, long rem)
{
  printhex(fptr, a);
  fprintf(fptr, "_");
  printhex(fptr, b);
  fprintf(fptr, "_");
  printhex(fptr, rem);
  fprintf(fptr, "\n");
}

void printhex(FILE *fptr, long m)
{
    fprintf(fptr, "%016llx", m);
}    

double random_input(void)
{
  return 1.0 + rand()/32767.0;
}
  
