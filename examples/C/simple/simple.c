// simple.C
// David_Harris@hmc.edu 24 December 2021
// Simple illustration of compiling C code

//#include <stdio.h>
#include "util.h"
extern int printf(const char* fmt, ...);
extern int _comp1(void);

/*
long sum(long N) {
   long result, i;
   result = 0;
   for (i=1; i<=N; i++) {
       result = result + i;
   }
   return result; 

   int a;
   asm volatile ("li s0, 10;");

   asm volatile(
	   "li %0, 3;"			
	   //  "csrrs %0, 0xF14, zero" //CSSRS rd, mhartid, 0
	   : "=r"(a) //output
	   : //input
	   : //clobbered
		);
   return a;
}
*/

int main(void) {
    int s[1], expected[1];
    //    s[0] = sum(4);
    s[0] = _comp1();
    printf("s = %d\n", s[0]);
    expected[0] = 42;
    return verify(1, s, expected); // 0 means success
}
