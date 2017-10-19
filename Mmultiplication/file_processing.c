#include <unistd.h>
#include "file_processing.h"

int **mat1, **mat2;

struct m_data *read_matrices(char *m1_file_name, char *m2_file_name)
{
    FILE *input_a, *input_b;
    char dir[255];
    //input_b = fopen(m2_file_name, "r");
    input_a = fopen(m1_file_name, "r");
    if (input_a == NULL)
    {
        fprintf(stderr, "There is no such file with the required name!\n");
        return NULL;
    }
    char r_value[10], c_value[10];
    char r2_value[10], c2_value[10];
    read_mat1_size(input_a, r_value, c_value);

    input_b = fopen(m2_file_name, "r");
    if (input_b == NULL)
    {
        fprintf(stderr, "There is no such file with the required name!\n");
        return NULL;
    }
    read_mat2_size(input_a, r2_value, c2_value);

    unsigned r1 = get_numeric_value(r_value);
    unsigned c1 = get_numeric_value(c_value);
    unsigned r2 = get_numeric_value(r2_value);
    unsigned c2 = get_numeric_value(c2_value);
    struct m_data *datum = create_mdata(r1, c1, r2, c2);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            datum->matrix_a[i][j] = mat1[i][j];
        }
        free(mat1[i]);
    }
    free(mat1);
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            datum->matrix_b[i][j] = mat2[i][j];
        }
        free(mat2[i]);
    }
    free(mat2);
    return datum;
}

void read_mat1_size(FILE *input_a, char r_value[], char c_value[])
{
    char row[20], col[20];
    char buffer[50];
    if (fgets(buffer, sizeof(buffer), input_a) != NULL)
    {
        unsigned int count1 = 0, count2 = 0;
        bool found = false;
        int i;
        for (i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ' ')
                break;
            else if (buffer[i] == '=')
                found = true;
            else if (found)
            {
                r_value[count1++] = buffer[i];
            }
        }
        r_value[count1] = '\0';
        //printf("%s\n", r_value);
        found = false;
        for (int j = i+1; j < strlen(buffer); j++)
        {
            if (buffer[j] == '\n' || buffer[j] == ' ')
                break;
            else if (buffer[j] == '=')
                found = true;
            else if (found)
            {
                c_value[count2++] = buffer[j];
            }
        }
        c_value[count2] = '\0';
       // printf("%s\n", c_value);
    }

    mat1 = (int **)malloc(sizeof(int*) * (size_t)get_numeric_value(r_value));
    for (int i = 0; i < get_numeric_value(r_value); i++)
        mat1[i] = (int*)malloc(sizeof(int) * (size_t)get_numeric_value(c_value));
    for (int i = 0; i < get_numeric_value(r_value); i++)
    {
        for (int j = 0; j < get_numeric_value(c_value); j++)
        {
            fscanf(input_a, "%d", &mat1[i][j]);
        }
    }

    fclose(input_a);
}

void read_mat2_size(FILE *input_b, char r2_value[], char c2_value[])
{
    char buffer[50];
    if (fgets(buffer, sizeof(buffer), input_b) != NULL)
    {
        unsigned int count1 = 0, count2 = 0;
        bool found = false;
        int i;
        for (i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ' ')
                break;
            else if (buffer[i] == '=')
                found = true;
            else if (found)
            {
                r2_value[count1++] = buffer[i];
            }
        }
        r2_value[count1] = '\0';
        //printf("%s\n", r2_value);
        found = false;
        for (int j = i+1; j < strlen(buffer); j++)
        {
            if (buffer[j] == '\n' || buffer[j] == ' ')
                break;
            else if (buffer[j] == '=')
                found = true;
            else if (found)
            {
                c2_value[count2++] = buffer[j];
            }
        }
        c2_value[count2] = '\0';
        //printf("%s\n", c2_value);
    }
    mat2 = (int **)malloc(sizeof(int*) * (size_t)get_numeric_value(r2_value));
    for (int i = 0; i < get_numeric_value(r2_value); i++)
        mat2[i] = (int*)malloc(sizeof(int) * (size_t)get_numeric_value(c2_value));
    for (int i = 0; i < get_numeric_value(r2_value); i++)
    {
        for (int j = 0; j < get_numeric_value(c2_value); j++)
        {
            fscanf(input_b, "%d", &mat2[i][j]);
        }
    }
    fclose(input_b);
}

void write_output(char *m_file_name, struct m_data *datum)
{
    FILE *output;
}
