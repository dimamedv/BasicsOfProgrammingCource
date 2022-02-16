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

void test() {
    test_swapRowsWithMinAndMaxElementsOfSquareMatrix_differentRows();
    test_swapRowsWithMinAndMaxElementsOfSquareMatrix_sameRow();
}

int main() {
    test();
}
