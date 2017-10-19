#ifndef MATRICES_DATA_H_INCLUDED
#define MATRICES_DATA_H_INCLUDED

struct state
{
    unsigned int curr_row, curr_col;
};

struct m_data
{
    unsigned int arow_size, brow_size, acol_size, bcol_size;
    long long **matrix_a, **matrix_b, **matrix_o;
};


#endif // MATRICES_DATA_H_INCLUDED
