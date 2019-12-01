#include "stdafx.h"
#include <omp.h>
#include <Windows.h>
#include "Arrays.h"
#include <time.h>

void main()
{

	omp_set_num_threads(3);
	int i;
	int j = 0;

	//clock_t begin = clock();
	GenerateKxK();

#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < 3; i++) 
		{
				CalculateKxK(i);
				printf("\n");
		}
	}

	//CalculateKxK(0);
	//CalculateKxK(1);
	//CalculateKxK(2);
	printf("");



	
	system("pause");
}

