#ifndef FILE_PROCESSING_H_INCLUDED
#define FILE_PROCESSING_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix_util.h"

struct m_data *read_matrices(char *m1_file_name, char *m2_file_name);
void write_output(char *m_file_name, struct m_data *datum);

#endif // FILE_PROCESSING_H_INCLUDED
