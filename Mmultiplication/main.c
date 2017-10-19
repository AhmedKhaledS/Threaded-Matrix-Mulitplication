#include <stdio.h>
#include <stdlib.h>
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
        struct m_data *x = create_mdata(3, 3, 3, 3);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                x->matrix_a[i][j] = i+j, x->matrix_b[i][j] = i+j;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                x->matrix_a[i][j] = i+j, x->matrix_b[i][j] = i+j;
        multiply_naive(x);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                printf("%d ", *(*(x->matrix_o+i)+j));
            printf("\n");
        }
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
