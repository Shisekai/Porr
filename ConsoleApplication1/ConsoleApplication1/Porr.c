#include "stdafx.h"
#include <omp.h>
#include <Windows.h>
#include "Arrays.h"
#include <time.h>

void main()
{

	int i;
	int j = 0;
	GenerateKxK();
	clock_t t;
	t = clock();

	
	
#pragma omp parallel for
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Calculate(i);
			}
			int id = omp_get_thread_num();
			printf("Hello (%d)", id);
			printf("World (%d)\n", id);

		}
	}
	
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("%f time elapsed\n",time_taken);



	
	system("pause");
}

