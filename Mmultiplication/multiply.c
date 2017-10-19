#include "multiply.h"

struct m_data *mat_data;

void multiply_naive(struct m_data *data)
{
    mat_data = data;
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
}
void multiply_row_threaded(struct m_data *data)
{
    mat_data = data;
    unsigned int threads_number = data->arow_size;
    pthread_t row_threads[threads_number];
    for (int i = 0; i < data->arow_size; i++)
    {
        struct state *st = create_state(i, 0);
        int ret = pthread_create(&row_threads[i], NULL, calculate_row, (void *)st);
        if (ret != 0)
            fprintf(stderr, "Error occured while creating thread, error code = %d\n", ret);
    }
    for (int i = 0; i < threads_number; i++)
    {
        pthread_join(row_threads[i], NULL);
    }
    return;
}
void multiply_element_threaded(struct m_data *data)
{
    mat_data = data;
    unsigned int threads_number = data->arow_size;
    pthread_t element_threads[threads_number * threads_number];
    unsigned int counter = 0;
    for (int i = 0; i < data->arow_size; i++)
    {
        for (int j = 0; j < data->bcol_size; j++)
        {
            struct state *st = create_state(i, j);
            int ret = pthread_create(&element_threads[counter++], NULL, calculate_element, (void *)st);
            if (ret != 0)
                fprintf(stderr, "Error occured while creating thread, error code = %d\n", ret);
        }
    }
    for (int i = 0; i < threads_number * threads_number; i++)
    {
        pthread_join(element_threads[i], NULL);
    }
    return;
}


void *calculate_row(void *ptr)
{
    struct state *st = (struct state *) ptr;
    for (int i = 0; i < mat_data->bcol_size; i++)
    {
        mat_data->matrix_o[st->curr_row][i] = 0;
        for (int j = 0; j < mat_data->acol_size; j++)
        {
            mat_data->matrix_o[st->curr_row][i] += (mat_data->matrix_a[st->curr_row][j]
                                                  * mat_data->matrix_b[j][i]);
        }
    }
    free(st);
    pthread_exit(NULL);
}

void *calculate_element(void *ptr)
{
    struct state *st = (struct state *) ptr;
    mat_data->matrix_o[st->curr_row][st->curr_col] = 0;
    for (int i = 0; i < mat_data->acol_size; i++)
    {
        mat_data->matrix_o[st->curr_row][st->curr_col] += (mat_data->matrix_a[st->curr_row][i]
                                                 * mat_data->matrix_b[i][st->curr_col]);
    }
    free(st);
    pthread_exit(NULL);
}
