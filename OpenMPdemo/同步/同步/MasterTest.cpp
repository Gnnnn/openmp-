//File :MasterTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void MasterTest()
{
	int a[4], i, j;
	omp_set_nested(1);//设置可以并行嵌套
	#pragma omp parallel num_threads(2)
	{
		i=omp_get_thread_num();
		printf_s("顶级并行中当前线程ID = %d\n", i);
		#pragma omp parallel for
        for (j = 0; j < 4; j++)
		{
			printf_s("当前线程数目 = %d，当前线程ID = %d\n", omp_get_num_threads(),omp_get_thread_num());
            a[j] = j + j;
		}
		#pragma omp master
		{
            for (j = 0; j < 4; j++)
                printf_s("a[%d] = %d\n", j, a[j]);
			printf_s("Master：当前线程数目 = %d，当前线程ID = %d\n", omp_get_num_threads(),omp_get_thread_num());
		}
		#pragma omp barrier
	}	
}