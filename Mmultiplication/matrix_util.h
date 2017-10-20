#ifndef MATRIX_UTIL_H_INCLUDED
#define MATRIX_UTIL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/**
 * Used to create the matrix multiplication data used for processing which
 * are (matrix_a, matrix_b, matrix_out).
 * It also dynamically allocates them upon passing the sized of the input
 * matrices in the arguments.
 * @param row1 The size of the row in the first matrix (matrix_a)
 * @param col1 The size of the column in the first matrix (matrix_b)
 * @param row2 The size of the row in the second matrix (matrix_b)
 * @param col2 The size of the column in the second matrix (matrix_b)
 * @return A pointer to the created structure that is holding the data.
 */
struct m_data* create_mdata(unsigned int row1, unsigned int col1,
            unsigned int row2, unsigned int col2);

/**
 * Used to create the the state(row and column) of the current computed
 * element in the multiplication process.
 * @param row The row number in the output matrix.
 * @param col The column number in the output matrix.
 * @return The structure state holding the current state.
 */
struct state* create_state(unsigned int row, unsigned int col);
/**
 * Parse the passed string to integer value.
 * @param str The string number.
 * @return The integer value of the number in string.
 */
int get_numeric_value(char *str);

#endif // MATRIX_UTIL_H_INCLUDED
