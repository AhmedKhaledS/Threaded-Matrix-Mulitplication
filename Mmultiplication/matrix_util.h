#ifndef MATRIX_UTIL_H_INCLUDED
#define MATRIX_UTIL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "matrices_data.h"


struct m_data* create_mdata(unsigned int row1, unsigned int col1,
            unsigned int row2, unsigned int col2);
struct state* create_state(unsigned int row, unsigned int col);

#endif // MATRIX_UTIL_H_INCLUDED
