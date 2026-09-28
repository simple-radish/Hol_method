#include <cmath>
#include "solution.h"

int Solve_H(int size, double **matr, double *b, double *x) {
// считаем норму

    double norm = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fabs(matr[i][j]) > norm) {
                norm = fabs(matr[i][j]);
            }
        }
    }
    double eps = 1e-15 * norm;

//раздложение A = L * L^T
    for (int j = 0; j < size; j++) {
        // диагональный элемент
        double s = matr[j][j];
        for (int k = 0; k < j; k++) {
            s -= matr[j][k] * matr[j][k];
        }
        if (s <= eps) {
            return 1;   
        }
        matr[j][j] = sqrt(s);

// элементы столбца j под диагональю
        for (int i = j + 1; i < size; i++) {
            double t = matr[i][j];
            for (int k = 0; k < j; k++) {
                t -= matr[i][k] * matr[j][k];
            }
            matr[i][j] = t / matr[j][j];
        }
    }

//L * y = b
    for (int i = 0; i < size; i++) {
        double t = b[i];
        for (int k = 0; k < i; k++) {
            t -= matr[i][k] * x[k];
        }
        x[i] = t / matr[i][i];
    }

// L^T * x = y
    for (int i = size - 1; i >= 0; i--) {
        double t = x[i];
        for (int k = i + 1; k < size; k++) {
            t -= matr[k][i] * x[k];
        }
        x[i] = t / matr[i][i];
    }

    return 0;
}