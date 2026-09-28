#include "func.h"

void Row_B(double **matr, double *row, int size){
    for (int i = 0; i < size; i++){
        row[i] = 0;
        for (int j = 0; j < size; j+=2){
            row[i] += matr[i][j];
        }
    }
}


int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}


double F(int k, int n, int i, int j) {
    if (k == 1) 
    {
        return (double)(n - max(i,j) + 1);
    }
    else if (k == 2)
    {
        return (double)max(i,j);
    }
    else if (k == 3)
    {
        return (double)abs(i - j);
    }
    else if (k == 4)
    {
        return (1.0 / (double)(i + j - 1.0));
    }
    return 0;
}

void Build_Matrix(int k, int size, double **matr) {
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            matr[i][j] = F(k, size, i + 1, j + 1);
        }
    }
}