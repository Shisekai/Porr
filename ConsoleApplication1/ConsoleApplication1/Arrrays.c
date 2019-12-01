#include "stdafx.h"
#include "Arrays.h"
#include <stdlib.h> 
#include <stdbool.h>

#define G 0.5f



void GenerateKxK() 
{
	srand(NULL);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< N; j++)
		{
			inputArrKxK[i][j] = rand() % 200 - 100;
			if (i == j||i==N-1||j==N-1) {
				
				if (i == j)
				{
					inputArrKxK[i][j] += 100 * N;
				}
				
			}
		}
		resultArrK[i] = rand() % 200 - 100;
	}

}

void Calculate(int index)
{
	float sum = 0;
	outputArrK[index] = (1 - G)*outputArrK[index];
	for (int i = 0; i < N; i++)
	{
		if (i != index)
		outputArrK[index] -= G * inputArrKxK[index][i] / inputArrKxK[index][index] * outputArrK[i];
	}
	outputArrK[index] += G * resultArrK[index] / inputArrKxK[index][index];
}