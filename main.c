#include <assert.h>
#include <printf.h>
#include "libs/data_structures/matrix/matrix.h"

void test_swapRowsWithMinAndMaxElementsOfSquareMatrix_differentRows() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    swapRowsWithMinAndMaxElementsOfSquareMatrix(&m);
    matrix mResult = createMatrixFromArray(
            (int[]) {7, 8, 9,
                     4, 5, 6,
                     1, 2, 3},
            3, 3);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_swapRowsWithMinAndMaxElementsOfSquareMatrix_sameRow() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 9,
                     4, 5, 6,
                     7, 8, 3},
            3, 3);
    swapRowsWithMinAndMaxElementsOfSquareMatrix(&m);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 9,
                     4, 5, 6,
                     7, 8, 3},
            3, 3);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_sortRowsByMaxElement_differentMaxes1() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    sortRowsByMaxElement(&m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_sortRowsByMaxElement_differentMaxes2() {
    matrix m = createMatrixFromArray(
            (int[]) {4, 5, 6,
                     7, 8, 9,
                     1, 2, 3},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    sortRowsByMaxElement(&m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_sortRowsByMaxElement_sameMaxes() {
    matrix m = createMatrixFromArray(
            (int[]) {4, 5, 9,
                     7, 8, 9,
                     1, 2, 3},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 9,
                     7, 8, 9},
            3, 3);
    matrix mResultAlternative = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     7, 8, 9,
                     4, 5, 9},
            3, 3);
    sortRowsByMaxElement(&m);
    assert(areTwoMatricesEqual(&m, &mResult) ||
           areTwoMatricesEqual(&m, &mResultAlternative));
}

void test_sortColsByMinElement_differentMins1() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    sortColsByMinElement(&m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_sortColsByMinElement_differentMins2() {
    matrix m = createMatrixFromArray(
            (int[]) {3, 2, 1,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     6, 5, 4,
                     9, 8, 7},
            3, 3);
    sortColsByMinElement(&m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_sortColsByMinElement_sameMins() {
    matrix m = createMatrixFromArray(
            (int[]) {3, 1, 1,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 1, 3,
                     6, 5, 4,
                     9, 8, 7},
            3, 3);
    sortColsByMinElement(&m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_getSquareOfMatrixIfSymmetric1() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     2, 5, 6,
                     3, 6, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {14, 30, 42,
                     30, 65, 90,
                     42, 90, 126},
            3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_getSquareOfMatrixIfSymmetric2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 5,
                     2, 5, 6,
                     3, 6, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 5,
                     2, 5, 6,
                     3, 6, 9},
            3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_transposeIfMatrixHasNotEqualSumOfRows1() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 4, 7,
                     2, 5, 8,
                     3, 6, 9},
            3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_transposeIfMatrixHasNotEqualSumOfRows2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 1, 1,
                     7, 8, 9},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 1, 1,
                     7, 8, 9},
            3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_isMutuallyInverseMatrices1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {2, 5, 7,
                     6, 3, 4,
                     5, -2, -3},
            3, 3);
    matrix m2 = createMatrixFromArray(
            (int[]) {1, -1, 1,
                     38, -41, 34,
                     -27, 29, -24},
            3, 3);
    assert(!isMutuallyInverseMatrices(m1, m2));
}


void test_isMutuallyInverseMatrices2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {2, 5, 7,
                     6, 3, 4,
                     5, -2, -3},
            3, 3);
    matrix m2 = createMatrixFromArray(
            (int[]) {1, -1, 1,
                     -38, 41, -34,
                     27, -29, 24},
            3, 3);
    assert(isMutuallyInverseMatrices(m1, m2));
}

void test_findSumOfMaxesOfPseudoDiagonal1() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9,
                     10, 11, 12},
            4, 3);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 51);
}

void test_findSumOfMaxesOfPseudoDiagonal2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3, 4,
                     5, 6, 7, 8,
                     9, 10, 11, 12},
            3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 54);
}

void test_getMinInArea1() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2,  3,   4,
                     5, 6, 100,  8,
                     9, 10, 11, 12},
            3, 4);
    assert(getMinInArea(m) == 2);
}

void test_getMinInArea2() {
    matrix m = createMatrixFromArray(
            (int[]) {10, 2,  3,  1,
                     5,  6,  5,  8,
                     9, 100, 11, 12},
            3, 4);
    assert(getMinInArea(m) == 1);
}

void test_sortByDistances1() {
    matrix m = createMatrixFromArray(
            (int[]) {7, 8, 9,
                     1, 2, 3,
                     4, 5, 6},
            3, 3);
    matrix mResult = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3);
    sortByDistances(m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test_sortByDistances2() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3, 100,
                     4, 5, 6, 10,
                     7, 8, 9, 1},
            3, 4);
    matrix mResult = createMatrixFromArray(
            (int[]) {4, 5, 6, 10,
                     7, 8, 9, 1,
                     1, 2, 3, 100},
            3, 4);
    sortByDistances(m);
    assert(areTwoMatricesEqual(&m, &mResult));
}

void test() {
    test_swapRowsWithMinAndMaxElementsOfSquareMatrix_differentRows();
    test_swapRowsWithMinAndMaxElementsOfSquareMatrix_sameRow();
    test_sortRowsByMaxElement_differentMaxes1();
    test_sortRowsByMaxElement_differentMaxes2();
    test_sortRowsByMaxElement_sameMaxes();
    test_sortColsByMinElement_differentMins1();
    test_sortColsByMinElement_differentMins2();
    test_sortColsByMinElement_sameMins();
    test_getSquareOfMatrixIfSymmetric1();
    test_getSquareOfMatrixIfSymmetric2();
    test_transposeIfMatrixHasNotEqualSumOfRows1();
    test_transposeIfMatrixHasNotEqualSumOfRows2();
    test_isMutuallyInverseMatrices1();
    test_isMutuallyInverseMatrices2();
    test_findSumOfMaxesOfPseudoDiagonal1();
    test_findSumOfMaxesOfPseudoDiagonal2();
    test_getMinInArea1();
    test_getMinInArea2();
    test_sortByDistances1();
    test_sortByDistances2();
}

int main() {
    test();
}
