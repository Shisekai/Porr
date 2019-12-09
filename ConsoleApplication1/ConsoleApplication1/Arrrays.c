#include "stdafx.h"
#include "Arrays.h"
#include <stdlib.h> 
#include <stdbool.h>
#include <math.h>
#define G 0.5f
#define dim N

double rowSum;
int medium = dim - dim / (N/4);
int little = dim / (N/2);

void GenerateMatrixValues()
{
	srand(time(0));
	// wygenerowanie zer
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			a[i][j] = 0;
		}
	}
	//generacja Z strza³ki
	for (int i = medium; i < dim; i++)
	{
		for (int j = 0; j < medium; j++)
		{
			a[i][j] = rand() % 200 - 100;
			while (a[i][j] == 0)
			{
				a[i][j] = rand() % 200 - 100;
			}
		}
	}

	// generacja B strza³ki

	for (int i = 0; i < medium; i++)
	{
		for (int j = medium; j < dim; j++)
		{
			a[i][j] = rand() % 200 - 100;
			while (a[i][j] == 0)
			{
				a[i][j] = rand() % 200 - 100;
			}
		}
	}
	//generacja fi

	for (int k = 0; k < dim/little; k++)
	{
		for (int i = k * little; i < k*little + little; i++)
		{
			for (int j = k * little; j<k*little + little; j++)
			{
				a[i][j] = rand() % 200 - 100;
				while (a[i][j] == 0)
				{
					a[i][j] = rand() % 200 - 100;
				}
			}
		}
	}

	// zerowanie diagonali
	for (int i = 0; i < dim; i++)
	{
		a[i][i] = 0;
	}
	//generacja dominanty
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j<dim; j++)
		{
			rowSum += fabs(a[i][j]);
		}
		if (rand() % 2 == 0)
		{
			a[i][i] = (rowSum * 2) * 1;
		}
		else
		{
			a[i][i] = (rowSum * 2) * 1;
		}
		rowSum = 0;
	}

	//wyœwietlenie
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j< dim; j++)
		{
			//printf("%.0lf, ", a[i][j]);
		}
		//printf("\n");
	}
	for (int i = 0; i < dim; i++)
	{
		b[i]= rand() % 200 - 100;
		while (b[i] == 0)
		{
			b[i] = rand() % 200 - 100;
		}
	}
	Reset();
}

void CalculateMatrix(int j) {
	if (x[j] != 20.123123123)
		prev[j] = x[j];
	x[j] = (1 - G)*x[j];
	for (int i = 0; i < dim; i++)
	{
		if (i != j)
			x[j] -= G * (a[j][i] / a[j][j]) * x[i];
	}
	x[j] += G * b[j] / a[j][j];
	dif[j] = fabsf(prev[j] - x[j]);
	if (dif[j]<1e-0)
		flag[j] = 1;
}

void CheckMatrix() 
{
	for (int i = 0; i < N; i++)
	{
		check[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			check[i] += a[i][j] * x[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		check[i] -= b[i];
		norm += check[i] * check[i];
	}
	norm = sqrt(norm);

	
}

void MultiplyLast() 
{

	for (int j = 0; j < little+1; j++)
	{
		for (int i = 0; i < N; i++)
		{
			a[N - j-1][i] /= a[N - j-1][N -j- 1];
		}
		b[N - j - 1] /= a[N - j - 1][N - j - 1];
	}
	
}

void Reset()
{
	for (int i = 0; i<dim; i++)
	{
		flag[i] = 0;
		prev[i] = 10;
		prevDiv[i] = 1e4;
		x[i] = 20.123123123;
	}
}