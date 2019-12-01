#include "stdafx.h"
#include "Arrays.h"
#include <stdlib.h> 
#include <stdbool.h>
#define N 3
#define G 0.5f

float inputArrKxK[N][N];
float resultArrK[N];
float outputArrK[N];
float nexOutputArrK[N];
float iArrayK[N][N];
float inversedArray[N][N];
float calculatedArrayA[N][N];
float calculatedArrayB[N];
bool isFinished[N];

void CalculateArray() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			calculatedArrayA[i][j] += inputArrKxK[i][j] * inversedArray[j][i] * G;
			calculatedArrayB[i] += G * inversedArray[i][j]*resultArrK[i];
		}

	}
}


void GenerateKxK() 
{
	srand(NULL);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< N; j++)
		{
			inputArrKxK[i][j] = rand() % 200 - 100;
			if (i == j||i==N-1||j==N-1) {
				inputArrKxK[i][j] += 100*N;
				if (i == j)
				{
					iArrayK[i][j] = 1;
					inversedArray[i][j] = 1/inputArrKxK[i][j];
				}
				
			}
		}
		resultArrK[i] = rand() % 200 - 100;
	}
	CalculateArray();
}



void CalculateKxK(int index) 
{
	for (int j = 0; j < N; j++)
	{
		nexOutputArrK[index] += (iArrayK[index][j] - calculatedArrayA[index][j]) * outputArrK[j]
			+ calculatedArrayB[index];
	}
	outputArrK[index] = nexOutputArrK[index];
	printf("%f\n", outputArrK[index]);
}
void Calculate(int index)
{

}