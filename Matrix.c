//README
//Wai Lwi Phyo
//CRUZID: wlphyo
//pa2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Matrix.h"
#include "List.h"


typedef struct MatrixObj
{
	struct EntryObj
	{
		double value; //column
		int column; //value
	} EntryObj;
	int size;
	int NNZ;
	List* Row;
} MatrixObj;

typedef struct EntryObj* Entry;
Entry newEntry(Entry e, int col, double val)
{
	e->column = col;
	e->value = val;
	return e;
}
//how to returns a refernce to new nxn Matrix
Matrix newMatrix(int n)
{
	Matrix M =malloc(sizeof(MatrixObj));;
	M->Row= malloc(n*sizeof(List));
	M->size =n;
	M->NNZ = 0;
	 for(int i=0; i <= n; i++)
		M->Row[i]= newList();
	return M;
}

//Free heap memory associated with *pM, set *pM to NULL
void freeMatrix(Matrix* pM)
{
	
		int sz = (*pM)->size;
		//makeZero(*pM);
		for(int i = 0; i <sz;i++)
		{
			freeList(&((*pM)->Row)[i]);
		}
					printf("Hello\n");

		//	free((*pM)->Row);
			free(*pM);
			*pM = NULL;
	
		
	
}

//AccessFunctions
//return size of Matrix
int size(Matrix M)
{
	return(M->size);
}

// Return the number of non-zero elements in M.
int NNZ(Matrix M)
{
	return(M->NNZ);
}
//check if matrix A equals Matrix B
int equals(Matrix A, Matrix B)
{
	int eq = 0; // initialize to  false
	if(size(A) != size(B)) return eq;
	if(A->NNZ != B->NNZ) return eq;
	for(int i = 0; i <=size(A);i++)
	{
		List AList = A->Row[i];
		List BList = B->Row[i];
		eq = (length(AList)==length(BList));
		moveFront(AList);
		moveFront(BList);
		while(index(AList)>=0 && eq)
		{
			if(((Entry)get(AList))->column == ((Entry)get(BList))->column)
			{
				eq = (((Entry)get(AList))->value ==((Entry)get(BList))->value);
				moveNext(AList);
				moveNext(BList);
			}
		}
	}
	return eq;
	
}
//1<=i<=size() , i<=j<=size()
//ith row, jth column, x value
void changeEntry(Matrix M, int i, int j, double x)
 {

	//check if Row and Column are within the matrix boundary
	if(i<1 || i>size(M) || j <1 || j>size(M))
	{
		printf("Invalid ith and jth position\n");
		exit(1);
	}
	Entry A;
	moveFront(M->Row[i]);
	while(index(M->Row[i]) !=-1)
	{
		A= (Entry)get(M->Row[i]);
		if(j==A->column)
		{
			if(x!=0.0)
			{
				A->value = x;
				break;
			}else
			{
				free(M->Row[i]);
				delete(M->Row[i]);
				M->NNZ--;
				break;
			}
		}else if(j< A->column) break;
		moveNext(M->Row[i]);
	}
	if(index(M->Row[i]) == -1 && x!=0.0)
	{
		Entry B = malloc(sizeof(Entry));
		append(M->Row[i],newEntry(B,j,x));
		M->NNZ++;
	}else if (x!=0.0)
	{
				A= (Entry)get(M->Row[i]);
				if(j!=A->column)
				{
					Entry B = malloc(sizeof(Entry));

					insertBefore(M->Row[i],newEntry(B,j,x));
					M->NNZ++;
				}

	}
}
void makeZero(Matrix M)
{
	for(int i =1; i <= size(M);i++) clear(M->Row[i]);
	M->NNZ=0;
}
//Make Arithmetic Operations
//copy matrix
Matrix copy(Matrix A)
{
	Matrix retM = newMatrix(size(A));
	for(int i = 1; i <= size(A);i++)
	{
		moveFront(A->Row[i]);
		while(index(A->Row[i]) != -1)	
		{
			Entry tempE = (Entry)get(A->Row[i]);
			changeEntry(retM,i,tempE->column,tempE->value);
			moveNext(A->Row[i]);
		}
	}
	return retM;

}

//Scalar multiplication
Matrix scalarMult(double x, Matrix A)
{
	Matrix tempM = newMatrix(size(A));
	for(int i = 1; i <= size(A);i++)
	{
		if(length(A->Row[i]) != 0)
		{
			moveFront(A->Row[i]);
			while(index(A->Row[i]) != -1)
			{
				Entry tempE = malloc(sizeof(Entry));
				int col = (((Entry)get(A->Row[i]))->column);
				double val =(((Entry)get(A->Row[i]))->value);
				double newVal = x * val;
				append(tempM->Row[i],newEntry(tempE,col,newVal));
				tempM->NNZ++;
				moveNext(A->Row[i]);
			} 
		}
	} 
	return tempM;
}
//Sum of matrix
//pre: size A == sizeB
Matrix sum(Matrix A, Matrix B)
{
	if(size(A) != size(B))
	{
		printf("Sum() Matrices are different in size");
		exit(1);
	}
	Matrix finalM = newMatrix(size(A));

	for(int i = 1; i <= size(A);i++)
	{
		List list1 = A->Row[i];
		List list2 = B->Row[i];
		if(length(list1)!=0 && length(list2)==0)
		{
			moveFront(list1);
			while(index(list1) != -1)
			{
				changeEntry(finalM,i,((Entry)get(list1))->column,(((Entry)get(list1))->value));
				moveNext(list1);
			}
		}
		else if(length(list1)==0 && length(list2)!=0)
		{
			moveFront(list2);
			while(index(list2) != -1)
			{
				changeEntry(finalM,i,((Entry)get(list2))->column,((Entry)get(list2))->value);
				moveNext(list2);
			}
		}else if(length(list1)!=0 && length(list2)!=0)
		{
			moveFront(list1);
			moveFront(list2);
			while(index(list1) != -1 && index(list2) != -1)
			{
				if(((Entry)get(list1))->column == ((Entry)get(list2))->column)
				{
					changeEntry(finalM,i,((Entry)get(list2))->column,((((Entry)get(list1))->value)+(((Entry)get(list2))->value)));
					moveNext(list1);
					if(list1 != list2) moveNext(list2);

				}else if(((Entry)get(list1))->column < ((Entry)get(list2))->column)
				{
					changeEntry(finalM,i,((Entry)get(list1))->column,((((Entry)get(list1))->value)));
					moveNext(list1);
				}else if(((Entry)get(list1))->column > ((Entry)get(list2))->column)
				{
					changeEntry(finalM,i,((Entry)get(list2))->column,((((Entry)get(list2))->value)));
					moveNext(list2);
				}
			}
			while(index(list1) != -1)
			{
				changeEntry(finalM,i,((Entry)get(list1))->column,((((Entry)get(list1))->value)));
				moveNext(list1);
			}
			while(index(list2) != -1)
			{
				changeEntry(finalM,i,((Entry)get(list2))->column,((((Entry)get(list2))->value)));
				moveNext(list2);
			}
		}
	}
	return finalM;
}
//matrix subtraction
Matrix diff(Matrix A, Matrix B)
{
	if(size(A) != size(B))
	{
		printf("diff() Matrices are different in size");
		exit(1);
	}
	Matrix tempM = newMatrix(size(A));
	if(A == B) return tempM;
	else
	{
		tempM = sum(A,scalarMult(-1,B));
		return tempM;
	}
}
//transpose of input matrix
Matrix transpose(Matrix A)
{
	Matrix tempM = newMatrix(size(A));

	for(int i = 1; i <= size(A);i++)
	{
		moveFront(A->Row[i]);
		while(index(A->Row[i]) != -1)
		{
			changeEntry(tempM,((Entry)get(A->Row[i]))->column,i,((Entry)get(A->Row[i]))->value);
			moveNext(A->Row[i]);
		}
	}
	return tempM;
}
//Product of two matrices
Matrix product(Matrix A, Matrix B)
{
	if(size(A) != size(B))
	{
		printf("Product() Matrices are different in size");
		exit(1);
	}
	Matrix tempM = newMatrix(size(A));
	//Transposed matrix of A
	Matrix tempTM = transpose(B);
	for(int i = 1; i <= size(A);i++)
	{	
		for(int j= 1; j <= size(A);j++)
		{
			changeEntry(tempM,i,j,vectorDot(A->Row[i],tempTM->Row[j]));
		}
	}
	return tempM;

}


//Print matrix
void printMatrix(FILE* out, Matrix M)
{
	for(int i = 1; i <=size(M);i++)
	{
		if(length(M->Row[i]) == 0) continue;
		Entry x;
		moveFront(M->Row[i]);
		if(M->NNZ != 0) 
		{
			fprintf(out,"%d: ",i);
		}
		while(index(M->Row[i])>=0)
		{
			x = (Entry)get(M->Row[i]);
			if(x->value == 0)
			{
				moveNext(M->Row[i]);
			}
			else
			{
					fprintf(out,"(%d, %.1f) ",x->column,x->value);
					moveNext(M->Row[i]);
				}
			}
				if(M->NNZ != 0) fprintf(out,"\n");
		
	}
}




double vectorDot(List P, List Q)
{
	double final=0.0;
	moveFront(P);
	moveFront(Q);
	if(index(P) == -1 || index(Q) == -1) return 0;

	while(index(P) >= 0 && index(Q) >= 0)
	{
		Entry temp1 = (Entry)get(P);
		Entry temp2 = (Entry)get(Q);
		if(temp1->column > temp2->column) moveNext(Q);
		else if(temp1->column < temp2->column) moveNext(P);
		else
		{
			final = final + (temp1->value * temp2->value);
			moveNext(P);
			moveNext(Q);
		}
	
	}
	return final;
}
