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

//for third method.
int *rmul1, *rmul2, *rres;
int i2, j2, k2;

int main() 
{
	freopen("compile-flags-transposed.txt", "w", stdout);
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			mat1[i][j] = rand() % 200, mat2[i][j] = rand() % 200;

	// for (int n = 50; n < 1050; n += 50)
	// {
	// 	// Naive method.
	// 	clock_t begin = clock();

	// 	for (int i = 0; i < n; ++i)
	// 	{
	// 		for (int j = 0; j < n; ++j)
	// 		{
	// 			for (int k = 0; k < n; ++k)
	// 			{
	// 				res[i][j] += mat1[i][k] * mat2[k][j];				
	// 			}
	// 		}
	// 	}
	// 	clock_t end = clock();
	// 	cout << (double)(end - begin) / CLOCKS_PER_SEC << "\n";		
	// }

	for (int n = 50; n < 1050; n += 50)
	{
		// Transposed method;
		clock_t begin2 = clock();
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				trnspz[i][j] = mat2[j][i];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
					res[i][j] += mat1[i][k] * trnspz[j][k];

		clock_t end2 = clock();
		cout << (double)(end2 - begin2) / CLOCKS_PER_SEC << "\n";		
	}

	// Optimized version utilizing L1 cache line
	// clock_t begin3 = clock();

	// for (int i = 0; i < N; i += SM)
	// 	for (int j = 0; j < N; j += SM)
	// 		for (int k = 0; k < N; k += SM)
	// 			for (i2 = 0, rres = &res[i][j], rmul1 = &mat1[i][k]; i2 < SM; ++i2, rres += N, rmul1 += N)
	// 				for (k2 = 0, rmul2 = &mat2[k][j]; k2 < SM; ++k2, rmul2 += N)
	// 					for (j2 = 0; j2 < SM; ++j2)
	// 						rres[j2] += rmul1[k2] * rmul2[j2];

	// clock_t end3 = clock();

	// printf("Time elapsed for Naive method: %.3f, \n", (double)(end - begin) / CLOCKS_PER_SEC);
	// printf("Time elapsed for Transpozed method: %.3f, \n", (double)(end2 - begin2) / CLOCKS_PER_SEC);
	// printf("Time elapsed for Optimized method for L1 cache: %.3f, \n", (double)(end3 - begin3) / CLOCKS_PER_SEC);

	
	return 0;
}
	// printf("Matrix 1: \n");
	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < N; ++j)
	// 	{
	// 		printf("%d ", mat1[i][j]);
	// 	}
	// 	printf("\n");
	// }

	// printf("Matrix 2: \n");
	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < N; ++j)
	// 	{
	// 		printf("%d ", mat2[i][j]);
	// 	}
	// 	printf("\n");
	// }


	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < N; ++j)
	// 	{
	// 		printf("%d ", res[i][j]);
	// 	}
	// 	printf("\n");
	// }	