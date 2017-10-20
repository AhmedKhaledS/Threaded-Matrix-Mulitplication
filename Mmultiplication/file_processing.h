#ifndef FILE_PROCESSING_H_INCLUDED
#define FILE_PROCESSING_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "matrix_util.h"
#include "matrices_data.h"

/**
 * This function is responsible for reading the input matrices
 * with the specified file names from the arguments.
 * @param m1_file_name The name of the file that contains the first
 * matrix in the input
 * @param m2_file_name The name of the file that contains the second
 * matrix in the input
 * @return A pointer to the structure created that corresponds the data
 * taken from both files.
 */
struct m_data *read_matrices(char *m1_file_name, char *m2_file_name);

/**
 * This function writes the output matrix to the file with the specified
 * name in the argument.
 * @param m_file_name The file name of the output matrix.
 * @param datum the structure that holds the data of all matrices (input
 * and output matrices).
 */
void write_output(char *m_file_name, struct m_data *datum);

#endif // FILE_PROCESSING_H_INCLUDED
