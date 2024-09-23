#include "matrix.h"
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
void matmul(const matrix_t *A, const matrix_t *B, matrix_t *C) {
    for (int i = 0; i < A->nrows; i++) {
        for (int j = 0; j < B->ncols; j++) {
            int sum = 0;
            for (int k = 0; k < A->ncols; k++) {
                sum += MGET(A, i, k) * MGET(B, k, j);
            }
            MSET(C, i, j, sum);
        }
    }
}
