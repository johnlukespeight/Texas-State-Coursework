/* Edit by Jeremy Hester, Jason Farrell, John-Luke Speight 12/09/21*/

#include "MatrixMath.h"


#define N  (8)

mtx_type A[N][N];
mtx_type B[N][N];
mtx_type C[N][N];
mtx_type v[N];      // This is a row vector
mtx_type w[N];

mtx_type maxVal = 1000;  // maxValimum random matrix entry range
int maximum = 1000;

int main()

{
   // int operations =0;
    // Initialize matrices
    for (int i = 0; i < N; i++)
    {
        v[i] = i + 1;                  // vector of sequential numbers
        for (int j = 0; j < N; j++)
        {
            int place =(rand()%maximum+1);
            A[i][j] = place;
            if (i == j)
            {
                B[i][j] = 1.0f;                  // B is identity
            }
            else
            {
                B[i][j] = 0.0f;
            }
        }
    }
    
    
    Matrix.Multiply((mtx_type*)A, (mtx_type*)B, N, N, N, (mtx_type*)C);

    printf("\nAfter multiplying C = A*B:");
    Matrix.Print((mtx_type*)A, N, N, 'A');
    Matrix.Print((mtx_type*)B, N, N, 'B');
    Matrix.Print((mtx_type*)C, N, N, 'C');
    Matrix.Print((mtx_type*)v, N, 1, 'v');

    printf("                         ");

    Matrix.Add((mtx_type*) B, (mtx_type*) C, N, N, (mtx_type*) C);
    printf("\nC = B+C (addition in-place)");
    Matrix.Print((mtx_type*)C, N, N, 'C');
    Matrix.Print((mtx_type*)B, N, N, 'B');

    Matrix.Copy((mtx_type*)A, N, N, (mtx_type*)B);
    printf("\nCopied A to B:");
    Matrix.Print((mtx_type*)B, N, N, 'B');

    Matrix.Invert((mtx_type*)A, N);
    printf("\nInverted A:");
    Matrix.Print((mtx_type*)A, N, N, 'A');

    Matrix.Multiply((mtx_type*)A, (mtx_type*)B, N, N, N, (mtx_type*)C);
    printf("\nC = A*B");
    Matrix.Print((mtx_type*)C, N, N, 'C');

    // Because the library uses pointers and DIY indexing,
    // a 1D vector can be smoothly handled as either a row or col vector
    // depending on the dimensions we specify when calling a function
    Matrix.Multiply((mtx_type*)C, (mtx_type*)v, N, N, 1, (mtx_type*)w);
    printf("\n C*v = w:");
    Matrix.Print((mtx_type*)v, N, 1, 'v');
    Matrix.Print((mtx_type*)w, N, 1, 'w');
    //operations ++;

   


  //while(operations<100);
}
