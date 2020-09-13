//README
//Wai Lwi Phyo
//CRUZID: wlphyo
//pa2
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#define MAX 10000
struct processNum
{
	int row,col;
	double val;
};

int main(int argc, char* argv[])
{
	FILE* in;
	FILE* out;
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"w");
	int mSize; //matrix size
	int aNNZ; //matrix A NNZ
	int bNNZ; //Matrix B NNZ
	struct processNum MatrixA[MAX];
	struct processNum MatrixB[MAX];
	
	if(argc != 3) 
	{
		printf("Usage: %s <input file> <output file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	if(in ==NULL)
	{
		printf("Unable to read from file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}

	if(fscanf(in,"%d%d%d",&mSize,&aNNZ,&bNNZ) != 3) exit(1);
	Matrix A = newMatrix(mSize);
	Matrix B = newMatrix(mSize);
	Matrix C,D,E,F,G,H,I,J;
	for(int i = 0; i <aNNZ;i++)
	{
		if(fscanf(in,"%d %d %lf", &MatrixA[i].row,&MatrixA[i].col,&MatrixA[i].val) !=3)
			exit(1);
	}
	for(int i = 0; i<aNNZ;i++)
	{
		 changeEntry(A,MatrixA[i].row,MatrixA[i].col,MatrixA[i].val);
	}
	for(int i = 0; i <bNNZ;i++)
	{
		if(fscanf(in,"%d %d %lf", &MatrixB[i].row,&MatrixB[i].col,&MatrixB[i].val) !=3)
			exit(1);
	}
	for(int i = 0; i<bNNZ;i++)
	{
		 changeEntry(B,MatrixB[i].row,MatrixB[i].col,MatrixB[i].val);
	}
	fclose(in);

	fprintf(out,"A has %d non-zero entries:\n", NNZ(A));
    printMatrix(out, A);
   fprintf(out,"\n");
    
	fprintf(out,"B has %d non-zero entries:\n", NNZ(B));
    printMatrix(out, B);
    fprintf(out,"\n");
    
    C = scalarMult(1.5, A);
   fprintf(out,"(1.5)*A =\n");
    printMatrix(out, C);
    fprintf(out,"\n");
    
	D = sum(A, B);
    fprintf(out,"A+B =\n");
    printMatrix(out, D);
    fprintf(out,"\n");
    
   E = sum(A, A);
   fprintf(out,"A+A =\n");
   printMatrix(out, E);
   fprintf(out,"\n");

   F = diff(B,A);
   fprintf(out,"B-A =\n");
   printMatrix(out, F);
   fprintf(out,"\n");

   G = diff(A,A);
   fprintf(out,"A-A =\n");
   printMatrix(out, G);
   fprintf(out,"\n");
  
   H = transpose(A);
   fprintf(out,"Transpose(A) =\n");
   printMatrix(out, H);
   fprintf(out,"\n");
   
    I = product(A,B);
   fprintf(out,"A*B =\n");
   printMatrix(out, I);
   fprintf(out,"\n");
   
    J = product(B, B);
   fprintf(out,"B*B =\n");
   printMatrix(out, J);
   fprintf(out,"\n");
   fclose(out);

    freeMatrix(&A);

    freeMatrix(&B);

   freeMatrix(&C);
   freeMatrix(&D);
   freeMatrix(&E);
   freeMatrix(&F);
   freeMatrix(&G);
   freeMatrix(&H);
    freeMatrix(&I); 
    freeMatrix(&J);
  
   

	return 0;
}
