//File: SectionsTest03.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void SectionsTest03()
{
	#pragma omp parallel
	{
		#pragma omp sections nowait //��1��sections
		{
			#pragma omp section
			{
				cout<<"section 1 �߳�ID��"<<omp_get_thread_num()<<"\n";
			}
			#pragma omp section
			{
				cout<<"section 2 �߳�ID��"<<omp_get_thread_num()<<"\n";
			}
			#pragma omp section
			{
				cout<<"section 3 �߳�ID��"<<omp_get_thread_num()<<"\n";
			}
		}
		#pragma omp sections //��2��sections
		{
			#pragma omp section
			{
				cout<<"section 4 �߳�ID��"<<omp_get_thread_num()<<"\n";
			}
			#pragma omp section
			{
				cout<<"section 5 �߳�ID��"<<omp_get_thread_num()<<"\n";
			}
			#pragma omp section
			{
				cout<<"section 6 �߳�ID��"<<omp_get_thread_num()<<"\n";
			}
		}
	}
}