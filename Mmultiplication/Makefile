OBJ = main.o file_processing.o matrix_util.o multiply.o
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -pthread 

matMult : $(OBJ)
	$(CC) -o matMult $(OBJ) $(LDFLAGS)

main.o : matrices_data.h file_processing.h multiply.h

file_processing.o : file_processing.h

matrix_util.o : matrix_util.h matrices_data.h

multiply.o : multiply.h matrices_data.h matrix_util.h

clean:
	rm $(OBJ) matMult
