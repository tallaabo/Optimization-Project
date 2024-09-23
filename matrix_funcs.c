#include <stdlib.h>
#include "matrix.h"

/*
 * Computes five different sums of elements in the array. Each sum is computed
 * from the set of elements with the same remainder when their respective
 * indexes are divided by 5. That is, results[x] is the sum of all matrix
 * elements with an index i such that i % 5 == x.
 * Arguments:
 *   matrix: Pointer to a matrix_t containing data to sum
 *   results: Array of 5 longs to hold sums
 */
/*
 * A version of get_every_fifth to be written by YOU. Takes the same arguments
 * and should provide the same functionality but in a way which is better
 * optimized.
 */
void get_every_fifth(const matrix_t *matrix, long results[RESULTS_LEN]) {
    for (int i = 0; i < matrix->nrows; i++) {
        for (int j = 0; j < matrix->ncols; j++) {
            int q = j % RESULTS_LEN;
            results[q] += MGET(matrix, i, j);
        }
    }
}

/*
 * Computes the sum of every element in a matrix
 * Arguments:
 *   matrix: Pointer to a matrix_t containing data to sum
 * Returns: Sum of all matrix elements
 */
/*
 * A Version of get_every to be written by YOU. Takes the same arguments and
 * returns the same value. It should provide the same functionality as
 * get_every but in a way which is better optimized.
 */
long get_every(const matrix_t *matrix) {
    long sum = 0;
    for (int i = 0; i < matrix->nrows; i++) {
        for (int j = 0; j < matrix->ncols; j++) {
            sum += MGET(matrix, i, j);
        }
    }
    return sum;
}

void initialize_results(long results[RESULTS_LEN]) {
    for (int i = 0; i < RESULTS_LEN; i++) {
        results[i] = 0;
    }
}

void set_up_random_matrix(matrix_t *matrix, int nrows, int ncols, int seed) {
    if (matrix == NULL) {
        return;
    }
    matrix->nrows = nrows;
    matrix->ncols = ncols;
    matrix->data = malloc(sizeof(int) * nrows * ncols);
    srand(seed);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            MSET(matrix, i, j, rand() % 100);
        }
    }
}

void set_up_zero_matrix(matrix_t *matrix, int nrows, int ncols) {
    if (matrix == NULL) {
        return;
    }
    matrix->nrows = nrows;
    matrix->ncols = ncols;
    matrix->data = calloc(nrows * ncols, sizeof(int));
}

void free_matrix(matrix_t *matrix) {
    free(matrix->data);
}
