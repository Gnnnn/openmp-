//File: SectionsTest03.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void SectionsTest03()
{
	#pragma omp parallel
	{
		#pragma omp sections nowait //第1个sections
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
		}
		#pragma omp sections //第2个sections
		{
			#pragma omp section
			{
				cout<<"section 4 线程ID："<<omp_get_thread_num()<<"\n";
			}
			#pragma omp section
			{
				cout<<"section 5 线程ID："<<omp_get_thread_num()<<"\n";
			}
			#pragma omp section
			{
				cout<<"section 6 线程ID："<<omp_get_thread_num()<<"\n";
			}
		}
	}
}