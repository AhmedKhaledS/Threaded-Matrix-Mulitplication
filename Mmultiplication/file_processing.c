#include <unistd.h>
#include "file_processing.h"


struct m_data *read_matrices(char *m1_file_name, char *m2_file_name)
{
    FILE *input_a, *input_b;
    input_a = fopen(m1_file_name, "r");
    char dir[255];
    getcwd(dir, sizeof(dir));
    puts(dir);
   // input_b = fopen(m2_file_name, "r");
    if (input_a == NULL)
    {
        fprintf(stderr, "There is no such file with the required name!\n");
        return NULL;
    }
    char buffer[20];
    if (fgets(buffer, sizeof(buffer), input_a) != NULL)
    {
        char *token = strtok(buffer, " ");
        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }

}
void write_output(char *m_file_name, struct m_data *datum)
{
    FILE *output;
}
