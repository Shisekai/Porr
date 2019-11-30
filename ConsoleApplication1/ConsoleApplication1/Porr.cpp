#include "stdafx.h"
#include <omp.h>
#include <Windows.h>
#include "Arrays.h"
#include <ctime>

void main()
{
	/*omp_set_num_threads(8);*/
	//#pragma omp parallel
	//{
	//	int id = omp_get_thread_num();
	//	printf("hello(%d)", id);
	//	printf("world(%d)\n", id);
	//}
	omp_set_num_threads(8);
	int i;
	int j;
	using namespace std;
	clock_t begin = clock();

	#pragma omp parallel for
	for (int i = 0; i < 10000000000; i++)
		j++;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", elapsed_secs);
	GenerateKxK();
	printf("%lf\n", elapsed_secs);



	
	system("pause");
}

