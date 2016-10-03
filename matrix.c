#include "matrix.h"

Matrix* create_matrix_from_file(FILE* file) {
    int rowsCount = 0, columnsCount = 0;
    fscanf(file, "%d\n%d", &rowsCount, &columnsCount);

    if (ferror(file)) {
        printf("File read error\n");
        return NULL;
    }

    if (rowsCount <= 0){
        printf("Wrong rows count\n");
    } else if (columnsCount <= 0) {
        printf("Wrong columns count\n");
    }

    struct Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rowsCount = rowsCount;
    matrix->columnsCount = columnsCount;
    matrix->map = calloc( sizeof(double *), rowsCount);

    for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
        matrix->map[rowIndex] = calloc( sizeof(double), columnsCount);

        for (int columnIndex = 0; columnIndex < columnsCount; ++columnIndex) {
            if (feof(file)) {
                printf("The quantity of numbers in the file doesn't match to defined quantity\n");
                free_matrix(matrix);
                return NULL;
            }

            double buffer = 0.0;
            fscanf(file, "%lf", &buffer);
            if (ferror(file)) {
                printf("File read error\n");
                free_matrix(matrix);
                return NULL;
            }

            set_elem(matrix, rowIndex, columnIndex, buffer);
        }

    }

    return matrix;
}

Matrix* create_matrix(int row, int col) {
    struct Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rowsCount = row;
    matrix->columnsCount = col;

    matrix->map = calloc( sizeof(double *), row);
    for (int rowIndex = 0; rowIndex < row; ++rowIndex) {
        matrix->map[rowIndex] = calloc( sizeof(double), col);

        for (int columnIndex = 0; columnIndex < col; ++columnIndex) {
            set_elem(matrix, rowIndex, columnIndex, 0.0);
        }

    }

    return matrix;
}

void free_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rowsCount; ++i) {
        free(matrix->map[i]);
    }

    free(matrix->map);
    free(matrix);
}

double get_elem(Matrix* matrix, int row, int col) {
    return matrix->map[row][col];
}

void set_elem(Matrix* matrix, int row, int col, double val) {
    matrix->map[row][col] = val;
}

int get_rows(Matrix* matrix) {
    return matrix->rowsCount;
}

int get_cols(Matrix* matrix) {
    return matrix->columnsCount;
}
