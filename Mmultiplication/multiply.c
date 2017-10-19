#include "multiply.h"

void multiply_naive(struct m_data *data)
{
    for (int i = 0; i < data->arow_size; i++)
    {
        for (int j = 0; j < data->bcol_size; j++)
        {
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

}
void multiply_element_threaded(struct m_data *data)
{

}
