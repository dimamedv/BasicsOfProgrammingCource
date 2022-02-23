#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "matrix.h"
#include "../../algorithms/array/array.h"
#include "../../algorithms/algorithms.h"
#include "math.h"


typedef struct assert assert;

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
     for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix *m) {
    for (int row = 0; row < m->nRows; row++)
        for (int column = 0; column < m->nCols; column++)
            scanf("%d", &m->values[row][column]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(&ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int row = 0; row < m.nRows; row++) {
        for (int column = 0; column < m.nCols; column++)
            printf("%d ", m.values[row][column]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix *m, int i1, int i2) {
    int *tmp = m->values[i1];
    m->values[i1] = m->values[i2];
    m->values[i2] = tmp;
}

void swapColumns(matrix *m, int j1, int j2) {
    for (int row = 0; row < m->nRows; row++)
        swap(&m->values[row][j1], &m->values[row][j2]);
}

void insertionSortRowsMatrixByRowCriteria(matrix *m,
                                          int (*criteria)(int *, int)) {
    int subArray[m->nRows];
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++)
        subArray[rowIndex] = criteria(m->values[rowIndex], m->nCols);
    for (int rowIndex = 1; rowIndex < m->nRows; rowIndex++) {
        int currentCriteriaValue = subArray[rowIndex];
        int *currentRow = m->values[rowIndex];
        int currentPosition = rowIndex;
        while (currentPosition > 0 &&
               currentCriteriaValue > subArray[currentPosition - 1]) {
            subArray[currentPosition] = subArray[currentPosition - 1];
            m->values[currentPosition] = m->values[currentPosition - 1];
            currentPosition--;
        }
        subArray[currentPosition] = currentCriteriaValue;
        m->values[currentPosition] = currentRow;
    }
}

void getColumnOfMatrix(int *column, matrix *m, int j) {
    for (int row = 0; row < m->nRows; row++) {
        column[row] = m->values[row][j];
    }
}

void moveColumn(matrix *m, int from, int to) {
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
        m->values[rowIndex][to] = m->values[rowIndex][from];
    }
}

void setColumn(const int *a, matrix *m, int j) {
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++)
        m->values[rowIndex][j] = a[rowIndex];
}

void insertionSortColsMatrixByColCriteria(matrix *m,
                                          int (*criteria)(int*, int)) {
    int subArray[m->nCols];
    for (int columnIndex = 0; columnIndex < m->nCols; columnIndex++) {
        int currentColumn[m->nRows];
        getColumnOfMatrix(currentColumn, m, columnIndex);
        subArray[columnIndex] = criteria(currentColumn, m->nRows);
    }

    for (int columnIndex = 1; columnIndex < m->nCols; columnIndex++) {
        int currentColumnCopy[m->nRows];
        getColumnOfMatrix(currentColumnCopy, m, columnIndex);
        int currentCriteriaValue = subArray[columnIndex];
        int currentPosition = columnIndex;
        while (currentPosition > 0 &&
               currentCriteriaValue > subArray[currentPosition - 1]) {
            subArray[currentPosition] = subArray[currentPosition - 1];
            moveColumn(m, currentPosition - 1, currentPosition);
            currentPosition--;
        }
        subArray[currentPosition] = currentCriteriaValue;
        setColumn(currentColumnCopy, m, currentPosition);
    }
}

bool isSquareMatrix(const matrix *m) {
    return m->nRows == m->nCols;
}

bool areTwoMatricesEqual(const matrix *m1, const matrix *m2) {
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols)
        return false;
    for (int rowIndex = 0; rowIndex < m1->nRows; rowIndex++) {
        if (memcmp(m1->values[rowIndex],
                   m2->values[rowIndex], sizeof(int) * m1->nRows) != 0)
            return false;
    }
    return true;
}

bool isEMatrix(matrix *m) {
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < m->nCols; columnIndex++) {
            if ((m->values[rowIndex][columnIndex] != 1 &&
                 rowIndex == columnIndex) ||
                (m->values[rowIndex][columnIndex] != 0 &&
                 rowIndex != columnIndex))
                return false;
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return false;
    for (int rowIndex = 1; rowIndex < m->nRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < rowIndex; columnIndex++)
            if (m->values[rowIndex][columnIndex] !=
            m->values[columnIndex][rowIndex])
                return false;
    }
    return true;
}

void transposeSquareMatrix(matrix *m) {
    assert(isSquareMatrix(m));
    for (int rowIndex = 1; rowIndex < m->nRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < rowIndex; columnIndex++){
            swap(&m->values[rowIndex][columnIndex],
                 &m->values[columnIndex][rowIndex]);
        }
    }
}

position getMinValuePos(matrix *m) {
    int min = m->values[0][0];
    position pos = {0, 0};
    for (int row = 0; row < m->nRows; row++)
        for (int column = 0; column < m->nCols; column++)
            if (m->values[row][column] < min) {
                min = m->values[row][column];
                pos.rowIndex = row;
                pos.colIndex = column;
            }
    return pos;
}

position getMaxValuePos(matrix *m) {
    int max = m->values[0][0];
    position pos = {0, 0};
    for (int row = 0; row < m->nRows; row++)
        for (int column = 0; column < m->nCols; column++)
            if (m->values[row][column] > max) {
                max = m->values[row][column];
                pos.rowIndex = row;
                pos.colIndex = column;
            }
    return pos;
}

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows,
                                     int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++) ms[k].values[i][j] = values[l++];
    return ms;
}

void swapRowsWithMinAndMaxElementsOfSquareMatrix(matrix *m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void revertRowsOfMatrix(matrix *m) {
    for (int rowIndex = 0; rowIndex < m->nRows / 2; rowIndex++) {
        swapRows(m, rowIndex, m->nRows - rowIndex - 1);
    }
}

void sortRowsByMaxElement(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(m, &getMax);
    revertRowsOfMatrix(m);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void revertColumnsOfMatrix(matrix *m) {
    for (int columnIndex = 0; columnIndex < m->nCols / 2; columnIndex++) {
        swapColumns(m, columnIndex, m->nCols - columnIndex - 1);
    }
}

void sortColsByMinElement(matrix *m) {
    insertionSortColsMatrixByColCriteria(m, &getMin);
    revertColumnsOfMatrix(m);
}

matrix mulMatrices(matrix *m1, matrix *m2) {
    assert(m1->nCols == m2->nRows);
    int resultRows = m1->nRows;
    int resultColumns = m2->nCols;
    matrix result = getMemMatrix(resultRows, resultColumns);
    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultColumns; j++) {
            int sum = 0;
            for (int k = 0; k < m1->nCols; k++) {
                sum += m1->values[i][k] * m2->values[k][j];
            }
            result.values[i][j] = sum;
        }
    }
    return result;
}

void getCopyOfMatrix(matrix *destination, matrix *source) {
    for (int row = 0; row < source->nRows; row++) {
        for (int column = 0; column < source->nCols; column++) {
            destination->values[row][column] = source->values[row][column];
        }
    }
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    matrix mCopy = getMemMatrix(m->nRows, m->nCols);
    getCopyOfMatrix(&mCopy, m);
    if (isSymmetricMatrix(m))
        *m = mulMatrices(&mCopy, &mCopy);
    freeMemMatrix(mCopy);
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        long long cur = a[i];
        for (int j = i + 1; j < n; j++)
            if (cur == a[j])
                return false;
    }
    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long a[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        a[i] = getSum(m.values[i], m.nRows);
    }
    if (isUnique(a, m.nRows))
        transposeSquareMatrix(&m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix mResult = mulMatrices(&m1, &m2);
    return isEMatrix(&mResult);
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int sumOfMaxes = 0;
    for (int i = 0; i < m.nRows; i++) {
        int rowIndex = i;
        int columnIndex = 0;
        int maxValue = m.values[rowIndex][columnIndex];
        while (rowIndex < m.nRows && columnIndex < m.nCols) {
            maxValue = max(maxValue, m.values[rowIndex][columnIndex]);
            rowIndex++;
            columnIndex++;
        }
        sumOfMaxes += maxValue;
    }
    for (int i = 1; i < m.nCols; i++) {
        int rowIndex = 0;
        int columnIndex = i;
        int maxValue = m.values[rowIndex][columnIndex];
        while (rowIndex < m.nRows && columnIndex < m.nCols) {
            maxValue = max(maxValue, m.values[rowIndex][columnIndex]);
            rowIndex++;
            columnIndex++;
        }
        sumOfMaxes += maxValue;
    }
    return sumOfMaxes;
}


int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(&m);
    position minPos = maxPos;
    for (int colIndex = maxPos.colIndex; colIndex >= 0; colIndex--) {
        for (int rowIndex = maxPos.rowIndex - maxPos.colIndex + colIndex;
             rowIndex >= 0; rowIndex--) {
            if (m.values[rowIndex][colIndex] <
                m.values[minPos.rowIndex][minPos.colIndex]) {
                minPos.rowIndex = rowIndex;
                minPos.colIndex = colIndex;
            }
        }
    }
    for (int colIndex = maxPos.colIndex; colIndex < m.nCols; colIndex++) {
        for (int rowIndex = maxPos.rowIndex + maxPos.colIndex - colIndex;
             rowIndex >= 0; rowIndex--) {
            if (m.values[rowIndex][colIndex] <
                m.values[minPos.rowIndex][minPos.colIndex]) {
                minPos.rowIndex = rowIndex;
                minPos.colIndex = colIndex;
            }
        }
    }
    return m.values[minPos.rowIndex][minPos.colIndex];
}

float getDistance(int *a, int n) {
    int sumOfRoots = 0;
    for (int i = 0; i < n; i++) {
        sumOfRoots += a[i] * a[i];
    }
    return sqrt(sumOfRoots);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix *m,
                                           float (*criteria)(int *, int)) {
    float subArray[m->nRows];
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++)
        subArray[rowIndex] = criteria(m->values[rowIndex], m->nCols);
    for (int rowIndex = 1; rowIndex < m->nRows; rowIndex++) {
        float currentCriteriaValue = subArray[rowIndex];
        int *currentRow = m->values[rowIndex];
        int currentPosition = rowIndex;
        while (currentPosition > 0 &&
               currentCriteriaValue > subArray[currentPosition - 1]) {
            subArray[currentPosition] = subArray[currentPosition - 1];
            m->values[currentPosition] = m->values[currentPosition - 1];
            currentPosition--;
        }
        subArray[currentPosition] = currentCriteriaValue;
        m->values[currentPosition] = currentRow;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(&m, &getDistance);
    revertRowsOfMatrix(&m);
}

int countEqClassesByRowSum(matrix m) {
    int classValues[m.nRows];
    int sizeCV = 0;
    for (int rowIndex = 0; rowIndex < m.nRows; rowIndex++) {
        int sumOfRow = getSum(m.values[rowIndex], m.nCols);
        int position = linearSearch_(classValues, sizeCV, sumOfRow);
        if (position == sizeCV)
            append_(classValues, &sizeCV, sumOfRow);
    }
    return sizeCV;
}