#ifndef MULTIPLY_H_INCLUDED
#define MULTIPLY_H_INCLUDED

#include "matrices_data.h"

void multiply_naive(struct m_data *data);
void multiply_row_threaded(struct m_data *data);
void multiply_element_threaded(struct m_data *data);


#endif // MULTIPLY_H_INCLUDED
