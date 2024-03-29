#include "stdafx.h"
#include <omp.h>
#include <Windows.h>
#include "Arrays.h"
#include <time.h>
#include <dlgs.h>

void main()
{

	int i;
	int j = 0;
	clock_t t;
	double time_taken;
	GenerateMatrixValues();

		t = clock();
		breakFlag = 0;
		int threads =1;
		
#pragma omp parallel for num_threads(threads) ordered //schedule(static,25)
		for (j = 0; j < 100; j++)
		{
#pragma omp parallel for num_threads(threads) ordered //schedule(static,100)
			for (i = N - 1; i >= 0; i--)
			{
				//flag[i] = 0;
				//counter[i] = 0;
				//while (counter[i] < 100 && flag[i] != 1)
				//{
					CalculateMatrix(i);
					counter[i]++;
				//}
			}
			CheckMatrix();
			if (norm < 1e-3)
				break;
		}
		t = clock() - t;
		time_taken = ((double)t) / CLOCKS_PER_SEC;
	
		CheckMatrix();
		if (norm <= 1) 
		{
			printf("Converged\n");
			printf("norm %f\n", norm);
		}
	
	else
	{
		printf("Not Converged\n");
		printf("norm %f\n", norm);
	}
	

	
	printf("%f time elapsed\n",time_taken);


	
	system("pause");
}


