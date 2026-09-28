#include <stdlib.h>
#include <math.h>
#include <cstdio>
#include <ctime>

#include "func.h"
#include "input.h"
#include "solution.h"


using namespace std;

int main (int argc, char *argv[]) {
int n;
int m;
int k; 
// ======= n + Проверка
if (argc != 4 && argc != 5) {
    printf("ERROR Wrong initial command\n");
    return 1;
}
if (sscanf(argv[1], "%d", &n) != 1) { 
    printf("ERROR: n is not Valid\n"); 
    return 1;}

if (sscanf(argv[2], "%d", &m) != 1) {
    printf("Error m is not Valid\n");
    return 1;
}

if (sscanf(argv[3], "%d", &k) != 1) {
    printf("Error k is not valid\n");
    return 1;
}

if (k < 0 || k >4) {
    printf("Error k i not in range\n");
    return 1;
}

if (m<=0) {
    printf("ERROR : m<= 0\n");
    return 1;
}

if (n<=0) {
    printf("ERROR : n<= 0\n");
    return 1;
}

if (k==0 && argc !=5) {
    printf("ERROR filename is not given\n");
    return 1;
}

if (k!=0 && argc != 4){
    printf("ERROR: excess filename\n");
    return 1;
}

// ==========
double **Matrix = new double*[n];
for (int i = 0; i < n; ++i) {
    Matrix[i] = new double[n];
}

// =========== 
//     printf("argc = %d\n", argc);
// for (int i = 0; i < argc; i++) {
//     printf("argv[%d] = %s ||  \n", i, argv[i]); 
// }

// =========== Read_File
if (k==0) {
    int res = Read_File(argv[4], n, Matrix);
    if (res!=0) {
        for (int i = 0; i < n; ++i) {
        delete[] Matrix[i]; 
        }
        delete[] Matrix;
        return 1;
    } 
}
else {
    Build_Matrix(k, n, Matrix);
}

// ======= Печатаю фрагмент матрицы
// if (m>n) {
//     m = n;
// }
// Simple_Print(m, Matrix);
Print_Matr(n, n, m, Matrix);

// ======= Столбец B
double *row = new double[n];
Row_B(Matrix, row, n);
// printf("Row B: \n");
// for (int i = 0; i < n; ++i) {
//     printf("%lf \n", row[i]);
// }

// ==========
// if (k!=0){
//     Build_Matrix(k, n, Matrix);
// }
// Simple_Print(n, Matrix);

double *x = new double[n];

clock_t t = clock();
int sol = Solve_H(n, Matrix, row, x);
t = clock() - t;

if (sol != 0) {
    printf("ERROR: matrix is not positive definite\n");
    for (int i = 0; i < n; ++i) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    delete[] row;
    delete[] x;
    return 1;
}

double *x_rows[1];
x_rows[0] = x;
printf("x:\n");
Print_Matr(1, n, m, x_rows);

printf("time = %.2f\n", (double)t / CLOCKS_PER_SEC);

for (int i = 0; i < n; ++i) {
    delete[] Matrix[i];
}
delete[] Matrix;
delete[] row;
delete[] x;
return 0;
}