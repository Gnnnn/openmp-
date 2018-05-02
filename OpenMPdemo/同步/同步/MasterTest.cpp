//File :MasterTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void MasterTest()
{
	int a[4], i, j;
	omp_set_nested(1);//���ÿ��Բ���Ƕ��
	#pragma omp parallel num_threads(2)
	{
		i=omp_get_thread_num();
		printf_s("���������е�ǰ�߳�ID = %d\n", i);
		#pragma omp parallel for
        for (j = 0; j < 4; j++)
		{
			printf_s("��ǰ�߳���Ŀ = %d����ǰ�߳�ID = %d\n", omp_get_num_threads(),omp_get_thread_num());
            a[j] = j + j;
		}
		#pragma omp master
		{
            for (j = 0; j < 4; j++)
                printf_s("a[%d] = %d\n", j, a[j]);
			printf_s("Master����ǰ�߳���Ŀ = %d����ǰ�߳�ID = %d\n", omp_get_num_threads(),omp_get_thread_num());
		}
		#pragma omp barrier
	}	
}