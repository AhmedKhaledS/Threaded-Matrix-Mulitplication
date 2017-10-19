#include <stdio.h>
#include <stdlib.h>
#include "matrices_data.h"
#include "naive_mmultiplication.h"
#include "file_processing.h"
#include "matrix_util.h"
#include "multiply.h"

/*struct m_data* create_mdata(unsigned int row1, unsigned int col1,
            unsigned int row2, unsigned int col2)
{
    struct m_data *matrix_data = (struct m_data *)malloc(sizeof(struct m_data));
    matrix_data->arow_size = row1;
    matrix_data->brow_size = row2;
    matrix_data->acol_size = col1;
    matrix_data->bcol_size = col2;
    matrix_data->matrix_a = (long long **)malloc(row1 * sizeof(long long *));
    matrix_data->matrix_b = (long long **)malloc(row2 * sizeof(long long *));
    matrix_data->matrix_o = (long long **)malloc(row1 * sizeof(long long *));
    if (matrix_data->matrix_a == NULL || matrix_data->matrix_b == NULL)
        fprintf(stderr, "Error while allocating memory for matrices\n");
    for (int i = 0; i < row1; i++)
        matrix_data->matrix_a[i] = (long long *) malloc((size_t)col1 * sizeof(long long));
    for (int i = 0; i < row2; i++)
        matrix_data->matrix_b[i] = (long long *) malloc((size_t)col2 * sizeof(long long));
    for (int i = 0; i < row1; i++)
        matrix_data->matrix_o[i] = (long long *) malloc((size_t)col2 * sizeof(long long));
    return matrix_data;
}

void multiply_naive(struct m_data *data)
{
    for (int i = 0; i < data->arow_size; i++)
    {
        for (int j = 0; j < data->bcol_size; j++)
        {
            data->matrix_o[i][j] = 0;
            for (int k = 0; k < data->acol_size; k++)
            {
                data->matrix_o[i][j] += (data->matrix_a[i][k]
                                    * data->matrix_b[k][j]);
            }
        }
    }
    return;
}*/

int main(int argc, char* argv[])
{
    // No specific files contains matrices A and B.
    // So they are in a.txt b.txt by default.
    if (argc == 1)
    {
        struct m_data *x = create_mdata(3, 3, 3, 3);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                x->matrix_a[i][j] = i+j, x->matrix_b[i][j] = i+j;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                x->matrix_a[i][j] = i+j, x->matrix_b[i][j] = i+j;
        multiply_naive(x);
        /*for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                printf("%I64d ", *(*(x->matrix_o+i)+j));
            printf("\n");
        }*/
    }
    else if (argc == 4)
    {

    }
    else
    {
        fprintf(stderr, "Invalid arguments are passed!\n");
    }
    return 0;
}
