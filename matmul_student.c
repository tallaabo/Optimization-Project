#include "matrix.h"
#include <stdlib.h>
/*
 * Computes the product of two matrices and stores result in a third matrix
 * Mathematically: C = A*B
 * Assumes that A->ncols == B->nrows
 * Assumes C is already set up such that C->nrows == A->nrows and C->ncols == B->ncols
 * Arguments:
 *  A: First multiplication operand
 *  B: Second multiplication operand
 *  C: Destination
 */
void matmul_student(const matrix_t *A, const matrix_t *B, matrix_t *C) {
    // Allocate BT with dimensions switched
    matrix_t BT;
    BT.nrows = B->ncols;
    BT.ncols = B->nrows;
    BT.data = (int *)malloc(BT.nrows * BT.ncols * sizeof(int));

    // Transpose B to BT
    for (int i = 0; i < B->nrows; i++) {
        for (int j = 0; j < B->ncols; j++) {
            MSET(&BT, j, i, MGET(B, i, j)); // Set BT[j][i] to B[i][j]
        }
    }

    // Perform multiplication using A and BT
    for (int i = 0; i < A->nrows; i++) {
        for (int j = 0; j < BT.nrows; j++) {
            int sum = 0;
            for (int k = 0; k < A->ncols; k++) {
                sum += MGET(A, i, k) * MGET(&BT, j, k);
            }
            MSET(C, i, j, sum);
        }
    }

    // Free the dynamically allocated memory for BT
    free(BT.data);
}
