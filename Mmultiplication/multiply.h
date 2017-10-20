#ifndef MULTIPLY_H_INCLUDED
#define MULTIPLY_H_INCLUDED
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrices_data.h"
#include "matrix_util.h"

/**
 * This function runs naive matrix multiplication method
 * with a single thread and with complexity O(n^3).
 * @param data A pointer to the structure that holds data for multiplication.
 */
void multiply_naive(struct m_data *data);

/**
 * This function runs matrix multiplication method
 * using a thread for each row in the output matrix.
 * @param data A pointer to the structure that holds data for multiplication.
 */
void multiply_row_threaded(struct m_data *data);

/**
 * This function runs matrix multiplication method
 * using a thread for each element in the output matrix.
 * @param data A pointer to the structure that holds data for multiplication.
 */
void multiply_element_threaded(struct m_data *data);

/**
 * This function is used by the thread that calculate some element in the
 * output matrix.
 * @param ptr A pointer to the structure that holds state(the current element
 * in the output matrix).
 * @return A generic pointer to the data required to be returned.
 */
void *calculate_element(void *ptr);

/**
 * This function is used by the thread that calculate some row in the output
 * matrix.
 * @param ptr A pointer to the structure that holds state(the current row
 * in the output matrix).
 * @return A generic pointer to the data required to be returned.
 */
void *calculate_row(void *ptr);

#endif // MULTIPLY_H_INCLUDED
