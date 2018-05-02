//File: SectionsTest02.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void SectionsTest02()
{
	#pragma omp parallel sections num_threads(4)
	{
		#pragma omp section
		{
			cout<<"section 1 线程ID："<<omp_get_thread_num()<<"\n";
		}
		#pragma omp section
		{
			cout<<"section 2 线程ID："<<omp_get_thread_num()<<"\n";
		}
		#pragma omp section
		{
			cout<<"section 3 线程ID："<<omp_get_thread_num()<<"\n";
		}
		#pragma omp section
		{
			cout<<"section 4 线程ID："<<omp_get_thread_num()<<"\n";
		}
	}
}