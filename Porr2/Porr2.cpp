#include <omp.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include "stdafx.h"
#include <math.h>
#define dim 32

double a[dim][dim];
double a_cpy[dim][dim];


double y[dim / 16];
double x[dim - dim / 16];
double b[dim - dim / 16];
double b0[dim / 16];

int medium = dim - dim / 16;
int little = dim / 16;

double W[dim - dim / 16];
double v[dim - dim / 16];

LARGE_INTEGER StartingTime, EndingTime;
LARGE_INTEGER Frequency;

double rowSum = 0;
void generateMatrix()
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
	for (int k = 0; k < dim; k++)
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
			a[i][i] = (rowSum * 2) * -1;
		}
		rowSum = 0;
	}

	//wyœwietlenie
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j< dim; j++)
		{
			printf("%.0lf ", a[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	generateMatrix();
	system("pause");
	////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	///////////////////////////////////////////////////

	//QueryPerformanceFrequency(&Frequency);
	//QueryPerformanceCounter(&StartingTime);

	//QueryPerformanceCounter(&EndingTime);
	//double timeElapsed = ((double)(EndingTime.QuadPart) - (double)(StartingTime.QuadPart)) / (double)Frequency.QuadPart;

	//printf("\n\n Elapsedtime = %.10lf\n", timeElapsed);
	//printf("\n ");
}