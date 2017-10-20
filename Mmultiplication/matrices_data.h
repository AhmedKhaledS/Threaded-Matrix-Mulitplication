#ifndef MATRICES_DATA_H_INCLUDED
#define MATRICES_DATA_H_INCLUDED
#include <string.h>

/**
 * The state for which the current element in the output matrix
 * (row-number and column-number).
 */
struct state
{
    unsigned int curr_row, curr_col;
};

/**
 * The structure that hold the 3 matrices (2 inputs to be
 * multiplied and 1 output matrix).
 * Also it hold the sizes of all matrices.
 */
struct m_data
{
    unsigned int arow_size, brow_size, acol_size, bcol_size;
    long long **matrix_a, **matrix_b, **matrix_o;
};


#endif // MATRICES_DATA_H_INCLUDED
