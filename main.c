#include <stdio.h>
#include <math.h>

#include "matrix.h"

double getEuclideanNorm(Matrix *matrix);
void printMatrix(Matrix *matrix);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("homework2 file1\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        //ferror
        printf("File \"%s\" is not found\n", argv[1]);
        return 2;
    }
    Matrix *matrix = create_matrix_from_file(file);
    fclose(file);

    printMatrix(matrix);
    printf("%lf\n", getEuclideanNorm(matrix));
    free_matrix(matrix);
    
	return 0;
}

double getEuclideanNorm(Matrix *matrix) {
    double squaresSum = 0;

    for (int i = 0; i < matrix->rowsCount; ++i) {
        for (int j = 0; j < matrix->columnsCount; ++j) {
            squaresSum += pow(matrix->map[i][j], 2);
        }
    }

    return sqrt(squaresSum);
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rowsCount; ++i) {
        for (int j = 0; j < matrix->columnsCount; ++j) {
            printf("%0.1lf ", matrix->map[i][j]);
        }

        printf("\n");
    }
}
