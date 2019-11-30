#include "stdafx.h"
#include "Arrays.h"
#include <stdlib.h> 
#define N 1000
int inputArrKxK[N][N];
int resultArrK[N];
int outputArrK[N];
int nexOutputArrK[N];
int iArrayK[N][N];

void GenerateKxK() 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< N; j++)
		{
			inputArrKxK[i][j] = rand() % 200 - 100;
			if (i == j||i==N-1||j==N-1) {
				inputArrKxK[i][j] += 100*1000;
				if (i == j)
					iArrayK[i][j] = 1;
			}
		}
		resultArrK[i] = rand() % 200 - 100;
	}
}
void CalculateKxK(int previous[N],int next[N]) 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			next[i] += previous[j] * inputArrKxK[i][j];
		}
	}

	memcpy(next, previous, sizeof(next));
}
