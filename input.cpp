
#include "input.h"

int Read_File(char *filename, int size, double **matr) {
    FILE *file = fopen(filename, "r");
   

    if (file == NULL) {
        printf("Капец файл не прочитался\n");
        return 1;
    }

    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if (fscanf(file, "%lf", &matr[i][j]) != 1) {
            printf("ERROR: Element of matrix is not Valid\n");
            fclose(file);
            return 1;
            }       
        }
    }
fclose(file);

// // ==============
//     FILE *file_matrix = fopen("matrix.txt", "w");
//      if (file_matrix == NULL) {
//         printf("Файл matrix не работает\n");
//         return 1;
//     }

//     for(int i = 0; i < size; i++) {
//         for (int j = 0; j < size; j++) {
//         fprintf(file_matrix, "%lf ", matr[i][j]);
//         }
//         fprintf(file_matrix, "\n");
//     }
    
//     fclose(file_matrix);
    return 0;
}


// ============== //

void Print_Matr(int line, int row, int m, double **matr) {
    int lines_to_print = line;
    if (m < line) {
        lines_to_print = m;
    }

    int rows_to_print = row;
    if (m < row) {
        rows_to_print = m;
    }

    for (int i = 0; i < lines_to_print; i++) {
        for (int j = 0; j < rows_to_print; j++) {
            printf(" %10.3e", matr[i][j]);
        }
        printf("\n");
    }
}

void Simple_Print(int size, double **matr) {
     for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
        printf(" %10.3e", matr[i][j]);
        }
        printf("\n");
    }
}