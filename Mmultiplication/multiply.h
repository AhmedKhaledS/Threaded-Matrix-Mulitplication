#ifndef MULTIPLY_H_INCLUDED
#define MULTIPLY_H_INCLUDED
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrices_data.h"
#include "matrix_util.h"

void multiply_naive(struct m_data *data);
void multiply_row_threaded(struct m_data *data);
void multiply_element_threaded(struct m_data *data);
void *calculate_element(void *ptr);
void *calculate_row(void *ptr);

#endif // MULTIPLY_H_INCLUDED
