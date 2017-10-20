#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matrices_data.h"
#include "file_processing.h"
#include <sys/time.h>
#include "multiply.h"

void end_time(struct m_data *data, unsigned int num, const char* type);
struct timeval stop, start;

int main(int argc, char* argv[])
{

/*    FILE *x, *y;
    x = fopen("a.txt", "w");
    fprintf(x, "row=1000 col=100\n");
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            fprintf(x, "%d ", i+j);
        }
        fprintf(x, "\n");
    }
    fclose(x);
    y = fopen("b.txt", "w");
    fprintf(y, "row=100 col=100\n");
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            fprintf(y, "%d ", i==j ? 1 : 0);
        }
        fprintf(y, "\n");
    }
    fclose(y);*/
    // No specific files contains matrices A and B.
    // So they are in a.txt b.txt by default.
    if (argc == 1)
    {
        struct m_data* data = read_matrices("a.txt", "b.txt");
/*        gettimeofday(&start, NULL);
        multiply_naive(data);
        end_time(data, 1, "whole matrix");*/

        //---------------------------------------------------------
        gettimeofday(&start, NULL);
        multiply_row_threaded(data);
        end_time(data, data->arow_size * data->bcol_size, "each row");
        //--------------------------------------------------------------------------------------------------
        gettimeofday(&start, NULL);
        multiply_element_threaded(data);
        end_time(data, data->arow_size * data->bcol_size, "each element");
        write_output("c.txt", data);
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

void end_time(struct m_data *data, unsigned int num, const char* type)
{
    gettimeofday(&stop, NULL);
    printf("By using the threads to calculate %s:\n", type);
    printf(" -Number of threads used for this method is: %d\n", num);
    printf(" -Time taken in seconds is %lu\n", stop.tv_sec - start.tv_sec);
    printf(" -Time taken in micro seconds is %lu\n", stop.tv_usec - start.tv_usec);
}