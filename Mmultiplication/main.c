#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matrices_data.h"
#include "file_processing.h"
#include "matrix_util.h"
#include "multiply.h"



int main(int argc, char* argv[])
{
    // No specific files contains matrices A and B.
    // So they are in a.txt b.txt by default.
    if (argc == 1)
    {
        //puts(buff);
        struct m_data* data = read_matrices("a.txt", "b.txt");
        //struct m_data *x = create_mdata(3, 3, 3, 3);
        multiply_naive(data);
        for (int i = 0; i < data->arow_size; i++)
        {
            for (int j = 0; j <  data->bcol_size; j++)
                printf("%d ", *(*(data->matrix_o+i)+j));
            printf("\n");
        }
        multiply_row_threaded(data);
        for (int i = 0; i < data->arow_size; i++)
        {
            for (int j = 0; j <  data->bcol_size; j++)
                printf("%d ", *(*(data->matrix_o+i)+j));
            printf("\n");
        }
        multiply_element_threaded(data);
        for (int i = 0; i < data->arow_size; i++)
        {
            for (int j = 0; j <  data->bcol_size; j++)
                printf("%d ", *(*(data->matrix_o+i)+j));
            printf("\n");
        }
/*        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j <  3; j++)
                printf("%d ", *(*(x->matrix_o+i)+j));
            printf("\n");
        }*/
        /*free(x->matrix_a);
        free(x->matrix_b);
        free(x->matrix_o);
        free(x);*/
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
