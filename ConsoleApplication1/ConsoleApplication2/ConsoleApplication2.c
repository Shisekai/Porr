#include <omp.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include "stdafx.h"

#define dim 100

double a[dim][dim];
double a_cpy[dim][dim];

double W[dim];
double v[dim];

double b[dim];

double x[dim];

void GenerateMatrixValues()
{
	srand(time(0));
	double rowSum = 0;

	for (int i = 0; i < dim; i++)
	{
		x[i] = 0;
	}

	for (int i = 0; i < dim; i++)
	{
		b[i] = rand() % 200 - 100;
		while (b[i] == 0)
		{
			b[i] = rand() % 200 - 100;
		}
		//printf("b[%d] %.0lf\n", i, b[i]);
	}

	printf("\n b[0] = %lf \n", b[0]);


	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j<dim; j++)
		{
			a[i][j] = 0;
		}
	}

	for (int i = 0; i<dim - 1; i++)
	{
		a[dim - 1][i] = rand() % 200 - 100;
		while (a[dim - 1][i] == 0)
		{
			a[dim - 1][i] = rand() % 200 - 100;
			//printf("\n value is 0 = %lf", a[dim - 1][i]);
		}

	}
	for (int i = 0; i<dim - 1; i++)
	{
		a[i][dim - 1] = rand() % 200 - 100;

		while (a[i][dim - 1] == 0)
		{
			a[i][dim - 1] = rand() % 200 - 100;
			//printf("\n value is 0 = %lf", a[i][dim - 1]);
		}

	}

	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j<dim; j++)
		{
			rowSum += fabs(a[i][j]);
		}
		if (rand() % 2 == 0)
		{
			a[i][i] = (rowSum + rand() % 5) * 1;
		}
		else
		{
			a[i][i] = (rowSum + rand() % 5) * -1;
		}
		rowSum = 0;
	}
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j<dim; j++)
		{
			a_cpy[i][j] = a[i][j];
		}
	}

	//printf("\n");
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j< dim; j++)
		{
			//printf("%.0lf ", a[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j< dim; j++)
		{
			//printf("%.0lf ", a_cpy[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");
}



void main()
{
	GenerateMatrixValues();
	printf("");
	system("pause");
}