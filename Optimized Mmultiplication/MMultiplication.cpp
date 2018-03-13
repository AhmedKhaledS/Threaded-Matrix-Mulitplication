#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

#define L1_CACHE_LINE 64
#define SM (L1_CACHE_LINE / sizeof (int))

const int N = 1000;

int mat1[N][N], mat2[N][N], res[N][N];
int trnspz[N][N];

// For the third method.
int *rmul1, *rmul2, *rres;
int i2, j2, k2;

// Further Optimization can be acheived by using compiler optimization flags for matrices operations: -funroll-loops | -march=native | -mfpmath=sse | -O3
// Command line Compilation command: "g++ -O3 -funroll-loops -march=native -mfpmath=sse MMultiplication.cpp -o mul && ./mul" --- Disable third method if used this

int main() 
{
	srand(time(NULL));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			mat1[i][j] = rand() % 200, mat2[i][j] = rand() % 200;


		// Naive method.
		clock_t begin = clock();

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int k = 0; k < N; ++k)
				{
					res[i][j] += mat1[i][k] * mat2[k][j];				
				}
			}
		}
		clock_t end = clock();


		// Transposed method;
		clock_t begin2 = clock();
		
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				trnspz[i][j] = mat2[j][i];

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < N; ++k)
					res[i][j] += mat1[i][k] * trnspz[j][k];

		clock_t end2 = clock();
		

	// Optimized version utilizing L1 cache line
	clock_t begin3 = clock();

	for (int i = 0; i < N; i += SM)
		for (int j = 0; j < N; j += SM)
			for (int k = 0; k < N; k += SM)
				for (i2 = 0, rres = &res[i][j], rmul1 = &mat1[i][k]; i2 < SM; ++i2, rres += N, rmul1 += N)
					for (k2 = 0, rmul2 = &mat2[k][j]; k2 < SM; ++k2, rmul2 += N)
						for (j2 = 0; j2 < SM; ++j2)
							rres[j2] += rmul1[k2] * rmul2[j2];

	clock_t end3 = clock();

	printf("Time elapsed for Naive method: %.3f, \n", (double)(end - begin) / CLOCKS_PER_SEC);
	printf("Time elapsed for Transpozed method: %.3f, \n", (double)(end2 - begin2) / CLOCKS_PER_SEC);
	printf("Time elapsed for Optimized method for L1 cache: %.3f, \n", (double)(end3 - begin3) / CLOCKS_PER_SEC);

	
	return 0;
}