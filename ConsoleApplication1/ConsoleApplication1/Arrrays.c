#include "stdafx.h"
#include "Arrays.h"
#include <stdlib.h> 
#include <stdbool.h>
#include <math.h>
#define G 0.5f
#define dim N

double a[dim][dim];
double a_cpy[dim][dim];

double b[dim];

double y[dim / 8];
double x[dim];
double Bb[dim - dim / 8][dim / 8 + 1];
double Bb_cpy[dim - dim / 8][dim / 8 + 1];
double b0[dim / 8];

double Wiy[dim / 8];

int medium = dim - dim / 16;
int little = dim / 16;
int fi_size = dim / 8;

double ZW[dim / 8][dim / 8];
double Zv[dim / 8][1];
double Wv[dim - dim / 8][dim / 8 + 1];

int StartingTime, EndingTime;
int Frequency;

double rowSum = 0;
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
	for (int k = 0; k < dim / fi_size; k++)
	{
		for (int i = k * fi_size; i < k*fi_size + fi_size; i++)
		{
			for (int j = k * fi_size; j<k*fi_size + fi_size; j++)
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
			a[i][i] = N * 100; //(rowSum * 40) * 1;
		}
		else
		{
			a[i][i] = N * 100;//(rowSum * 40) * 1;
		}
		rowSum = 0;
	}

	//kopia
	for (int i = 0; i < dim; i++)
	{
		for (int k = 0; k < dim; k++)
		{
			a_cpy[i][k] = a[i][k];
		}
	}
	//printf("\n A = \n");
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j< dim; j++)
		{
			//printf("%.0lf ", a_cpy[i][j]);
		}
		//printf("\n");
	}

	//wyœwietlenie
	//for (int i = 0; i<dim; i++)
	//{
	//	for (int j = 0; j< dim; j++)
	//	{
	//		printf("%.0lf ", a[i][j]);
	//	}
	//	printf("\n");
	//}

	//generacja b;
	for (int i = 0; i < dim; i++)
	{
		b[i] = rand() % 200 - 100;
		while (b[i] == 0)
		{
			b[i] = rand() % 200 - 100;
		}
	}
	for (int i = 0; i < dim; i++)
	{
		//printf("\n %lf", b[i]);
	}
	//printf("\n b0 = \n");
	for (int i = 0; i< fi_size; i++)
	{
		b0[i] = b[dim - fi_size + i];
		//printf("\n %lf", b0[i]);
	}
	///generacja Bb;
	for (int k = 0; k < dim - fi_size; k++)
	{
		for (int j = 0; j < fi_size; j++)
		{
			Bb[k][j] = a[k][medium - little + j];
		}
	}

	for (int i = 0; i < dim - fi_size; i++)
	{
		Bb[i][fi_size] = b[i];
	}
	//printf("\n Bb0 = \n");
	for (int i = 0; i < dim - fi_size; i++)
	{
		for (int k = 0; k < fi_size + 1; k++)
		{
			//printf("%lf ", Bb[i][k]);
		}
		//printf("\n");
	}

	//kopia bb0
	for (int i = 0; i < dim - fi_size; i++)
	{
		for (int k = 0; k < fi_size + 1; k++)
		{
			Bb_cpy[i][k] = Bb[i][k];
		}
	}

	//printf("\n Bb0_cpy = \n");
	//for (int i = 0; i < dim - little; i++)
	//{
	//	for (int k = 0; k < little + 1; k++)
	//	{
	//		printf("%lf ", Bb0_cpy[i][k]);
	//	}
	//	printf("\n");
	//}
	Reset();
}

void CalculateMatrix(int i) {
	prev[i] = x[i];
	x[i] = (1 - G)*x[i];
	for (int j = 0; j < dim; j++)
	{
		if (j != i)
			x[i] -= G * (a[i][j] / a[i][i]) * x[j];
	}
	x[i] += G * b[i] / a[i][i];
	//if (fabs(x[i]) > 1e5) 
	//{
	//	x[i] = prev[i];
	//	flag[i] = 1; 
	//	
	//	//printf("%f %f\n",j,x[j]);
	//}

	
	dif[i] = fabsf(prev[i] - x[i]);
	if (dif[i]>1e5)
	{
		flag[i] = 1;
	}
	
	//if (norm > 1e4)
	//	flag[i] = 1;
}

void CheckMatrix() 
{
	norm = 0;
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
		prev[i] = 0;//a[i][i] / b[i];
		x[i] = a[i][i] / b[i];
	}
}