//README
//Wai Lwi Phyo
//CRUZID: wlphyo
//pa2

//Exported Type
typedef struct MatrixObj* Matrix;
typedef struct ListObj* List;
//constructor-destructor
Matrix newMatrix(int n);
void freeMatrix(Matrix* pM);

// Access functions 
// Return the size of square Matrix M.
int size(Matrix M);
// Return the number of non-zero elements in M.
int NNZ(Matrix M);
//check if two matrices are the same
int equals(Matrix A, Matrix B);

//Manipulation Procedures
// Changes the ith row, jth column of M to the value x.
// Pre: 1<=i<=size(M), 1<=j<=size(M)
void changeEntry(Matrix M, int i, int j, double x);
// Re-sets M to the zero Matrix.
void makeZero(Matrix M);
// Prints a string representation of Matrix M to filestream out. Zero rows 
// are not printed.  Each non-zero is represented as one line consisting 
// of the rownumber, followed by a colon, a space, then a space separated 
// list of pairs"(col, val)" giving the column numbers and non-zero values 
// in that row.The double val will be rounded to 1 decimal point.
void printMatrix(FILE* out, Matrix M);

//Arithmetic Operations
// Returns a reference to a new Matrix object having the same entries as A.
Matrix copy(Matrix A);
// Returns a reference to a new Matrix object representing xA.
Matrix scalarMult(double x, Matrix A);
// Returns a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B);
// Returns a reference to a new Matrix object representing A-B.
// pre: size(A)==size(B)
Matrix diff(Matrix A, Matrix B);
// Returns a reference to a new Matrix object representing the transpose A
Matrix transpose(Matrix A);
// Returns a reference to a new Matrix object representing AB
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B);
//dot product
double vectorDot(List P, List Q);
