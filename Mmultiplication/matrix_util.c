#include "matrix_util.h"

struct m_data* create_mdata(unsigned int row1, unsigned int col1,
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

struct state* create_state(unsigned int row, unsigned int col)
{
    struct state *st = (struct state *)malloc(sizeof(struct state));
    st->curr_row = row, st->curr_col = col;
    return st;
}

int get_numeric_value(char *str)
{
    int dec = 0, i, j, len;
    len = strlen(str);
    for(i=0; i<len; i++){
        dec = dec * 10 + ( str[i] - '0' );
    }
    return dec;
}

