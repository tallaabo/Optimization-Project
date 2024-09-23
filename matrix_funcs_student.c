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

void get_every_fifth_student(const matrix_t *matrix, long results[RESULTS_LEN]) {

    for (int i = 0; i < matrix->nrows; i++) {
        int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        int j = 0;
        for (; j + 5 < matrix->ncols; j += 5) {     //getting every fifth
            sum0 += MGET(matrix, i, j);             // 0 5 10 ...
            sum1 += MGET(matrix, i, j + 1);         // 1 6 11 ...
            sum2 += MGET(matrix, i, j + 2);         // 2 7 12 ...
            sum3 += MGET(matrix, i, j + 3);         // 3 8 13 ...
            sum4 += MGET(matrix, i, j + 4);         // 4 9 14 ...
        }
        // Cleanup loop for remaining columns
        for (; j < matrix->ncols; j++) {
            results[j % RESULTS_LEN] += MGET(matrix, i, j);
        }
        // copy sums into the results array
        results[0] += sum0;
        results[1] += sum1;
        results[2] += sum2;
        results[3] += sum3;
        results[4] += sum4;
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
long get_every_student(const matrix_t *matrix) {
    // TODO Not Yet Implemented
    long sum = 0;
    for (int i = 0; i < matrix->nrows; i++) {
        long sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
        int j = 0;
        for (; j < matrix->ncols - (matrix->ncols % 4); j += 4) {
            sum0 += MGET(matrix, i, j);             // 0 4 8 ...
            sum1 += MGET(matrix, i, j + 1);         // 1 5 9 ...
            sum2 += MGET(matrix, i, j + 2);         // 2 6 10 ...
            sum3 += MGET(matrix, i, j + 3);         // 3 7 11 ...
        }
        // cleanup loop
        for (; j < matrix->ncols; j++) {
            sum += MGET(matrix, i, j);
        }
        sum += sum0;
        sum += sum1;
        sum += sum2;
        sum += sum3;
    }    
    return sum;
}
