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
    fprintf(x, "row=100 col=100000\n");
    for (int i = 0; i < 100; i++)
     {
        for (int j = 0; j < 100000; j++)
         {
             fprintf(x, "%d ", i+j);
         }
         fprintf(x, "\n");
     }
    fclose(x);
    y = fopen("b.txt", "w");
    fprintf(y, "row=100000 col=100\n");
    for (int i = 0; i < 100000; i++)
     {
        for (int j = 0; j < 100; j++)
         {
            fprintf(y, "%d ", i==j);
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
        printf("First matrix is of size: %dx%d\n", data->arow_size, data->acol_size);
        printf("Second matrix is of size: %dx%d\n", data->brow_size, data->bcol_size);
        printf("Output matrix is of size: %dx%d\n\n", data->arow_size, data->bcol_size);

        //-------------------------------------------------------------------------------------------------
        gettimeofday(&start, NULL);
        multiply_row_threaded(data);
        gettimeofday(&stop, NULL);
        end_time(data, data->arow_size, "each row");
        //--------------------------------------------------------------------------------------------------
        printf("--------------------------------------------------------------------------------------------\n");
        gettimeofday(&start, NULL);
        multiply_element_threaded(data);
        end_time(data, data->arow_size * data->bcol_size, "each element");

        write_output("c.txt", data);
        free(data);

    }
    else if (argc == 4)
    {
        struct m_data* data = read_matrices(argv[1], argv[2]);
/*        gettimeofday(&start, NULL);
        multiply_naive(data);
        end_time(data, 1, "whole matrix");*/

        //-------------------------------------------------------------------------------------------------
        gettimeofday(&start, NULL);
        multiply_row_threaded(data);
        end_time(data, data->arow_size * data->bcol_size, "each row");
        //--------------------------------------------------------------------------------------------------
        gettimeofday(&start, NULL);
        multiply_element_threaded(data);
        end_time(data, data->arow_size * data->bcol_size, "each element");
        write_output(argv[3], data);
        free(data);
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