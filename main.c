#include <assert.h>
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

void test() {
    test_swapRowsWithMinAndMaxElementsOfSquareMatrix_differentRows();
    test_swapRowsWithMinAndMaxElementsOfSquareMatrix_sameRow();
    test_sortRowsByMaxElement_differentMaxes1();
    test_sortRowsByMaxElement_differentMaxes2();
    test_sortRowsByMaxElement_sameMaxes();
    test_sortColsByMinElement_differentMins1();
    test_sortColsByMinElement_differentMins2();
    test_sortColsByMinElement_sameMins();
}

int main() {
    test();
}
