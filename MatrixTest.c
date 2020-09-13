//README
//Wai Lwi Phyo
//CRUZID: wlphyo
//pa2
#include <stdio.h> 
#include <stdlib.h>
#include "Matrix.h"
     
int main(int argc, char* argv[]){
	int n=15;
	Matrix A = newMatrix(n);
	 Matrix B = newMatrix(n);
     //Matrix C,F,H;// D,E,F,G,H;
      changeEntry(A, 1, 1, 1);
           changeEntry(A, 1, 3, 1);

       // changeEntry(A, 1, 1, 1);
        changeEntry(B, 1, 1, 1);
        changeEntry(B, 1, 3, 1);
         changeEntry(A, 1, 3, 0);
		  if(equals(A, B)) printf("yes\n");

    printf("A is %d\n", NNZ(A));
    printMatrix(stdout, A);
    printf("\n");

    printf("%d\n", NNZ(B));
    printMatrix(stdout, B);
    printf("\n");

    //~ C = scalarMult(1.5, A);
    //~ printf("%d\n", NNZ(C));
    //~ printMatrix(stdout, C);
    //~ printf("\n");

   //~ D = sum(A, B);
   //~ printf("%d\n", NNZ(D));
   //~ printMatrix(stdout, D);
   //~ printf("\n");

   //~ E = diff(A, B);
   //~ printf(" E is %d\n", NNZ(E));
   //~ printMatrix(stdout, E);
   //~ printf("\n");

   //~ F = transpose(A);
   //~ printf("%d\n", NNZ(F));
   //~ printMatrix(stdout, F);
   //~ printf("\n");

   //~ G = product(B, B);
   //~ printf("G is %d\n", NNZ(G));
   //~ printMatrix(stdout, G);
   //~ printf("\n");

   //~ H = copy(A);
   //~ printf("H is %d\n", NNZ(H));
   //~ printMatrix(stdout, H);
   //~ printf("\n");

   //~ printf("%s\n", equals(A, H)?"true":"false" );
   //~ printf("%s\n", equals(A, B)?"true":"false" );
   //~ printf("%s\n", equals(A, A)?"true":"false" );

   //~ makeZero(A);
   //~ printf("%d\n", NNZ(A));
   //~ printMatrix(stdout, A);

    //~ freeMatrix(&A);
    //~ freeMatrix(&B);
   //~ freeMatrix(&C);
   //~ freeMatrix(&D);
   //~ freeMatrix(&E);
   //~ freeMatrix(&F);
   //~ freeMatrix(&G);
   //~ freeMatrix(&H);

   return EXIT_SUCCESS;
}

