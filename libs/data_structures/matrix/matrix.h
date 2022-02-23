#ifndef BASICSOFPROGRAMMINGCOURSE_MATRIX_H
#define BASICSOFPROGRAMMINGCOURSE_MATRIX_H

#include <stdbool.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix *m);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix *m, int i1, int i2);

void swapColumns(matrix *m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix *m,
                                          int (*criteria)(int *, int));

void getColumnOfMatrix(int *column, matrix *m, int j);

void moveColumn(matrix *m, int from, int to);

void setColumn(const int *a, matrix *m, int j);

void insertionSortColsMatrixByColCriteria(matrix *m,
                                          int (*criteria)(int*, int));

bool isSquareMatrix(const matrix *m);

bool areTwoMatricesEqual(const matrix *m1, const matrix *m2);

bool isEMatrix(matrix *m);

bool isSymmetricMatrix(matrix *m);

void transposeSquareMatrix(matrix *m);

position getMinValuePos(matrix *m);

position getMaxValuePos(matrix *m);

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows,
                                     int nCols);

void swapRowsWithMinAndMaxElementsOfSquareMatrix(matrix *m);

int getMax(int *a, int n);

void sortRowsByMaxElement(matrix *m);

void revertRowsOfMatrix(matrix *m);

int getMin(int *a, int n);

void sortColsByMinElement(matrix *m);

matrix mulMatrices(matrix *m1, matrix *m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

int max(int a, int b);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

void sortByDistances(matrix m);

int countEqClassesByRowSum(matrix m);

int getNSpecialElement(matrix m);

void swapPenultimateRow(matrix m);

#endif //BASICSOFPROGRAMMINGCOURSE_MATRIX_H
