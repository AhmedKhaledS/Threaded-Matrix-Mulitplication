#include <stdio.h>
#include <stdlib.h>
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
    fprintf(x, "row=160 col=10000\n");
    for (int i = 0; i < 160; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            fprintf(x, "%d ", i+j);
        }
        fprintf(x, "\n");
    }
    fclose(x);
    y = fopen("b.txt", "w");
    fprintf(y, "row=10000 col=200\n");
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            fprintf(y, "%d ", j+i);
        }
        fprintf(y, "\n");
    }
    fclose(y);*/
    // No specific files contains matrices A and B.
    // So they are in a.txt b.txt by default.
    if (argc == 1)
    {
        struct m_data* data = read_matrices("a.txt", "b.txt");
        gettimeofday(&start, NULL);
        multiply_naive(data);
        end_time(data, 1, "whole matrix");

        //---------------------------------------------------------
        gettimeofday(&start, NULL);
        multiply_row_threaded(data);
        gettimeofday(&stop, NULL);
        end_time(data, data->arow_size, "each row");
        //--------------------------------------------------------------------------------------------------
        gettimeofday(&start, NULL);
        multiply_element_threaded(data);
        end_time(data, data->arow_size * data->bcol_size, "each element");
        write_output("c.txt", data);
    }
    else if (argc == 4)
    {
        struct m_data* data = read_matrices(argv[1], argv[2]);
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
        write_output(argv[3], data);
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
    printf(" -Time taken in micro-seconds is %ld microseconds\n",
           ((stop.tv_sec - start.tv_sec)*1000000L + stop.tv_usec) - start.tv_usec);
}