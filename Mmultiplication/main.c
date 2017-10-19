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
        char buff[200];
        getlogin_r(buff, sizeof(buff));
        //puts(buff);
        struct m_data* r = read_matrices("a.txt", "b.txt");
        //struct m_data *x = create_mdata(3, 3, 3, 3);
        /*multiply_naive(x);
        multiply_row_threaded(x);
        multiply_element_threaded(x);*/
        /*for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
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
