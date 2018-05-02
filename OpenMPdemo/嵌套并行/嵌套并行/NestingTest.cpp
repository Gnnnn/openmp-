//File :NestingTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void NestingTest()
{
	int i,j;
	#pragma omp parallel for
	for(i=0;i<4;i++)
	{
		#pragma omp parallel for
		for(j=0;j<4;j++)
		{
			cout<<"j  Threads:"<<omp_get_num_threads()<<"  ThreadID:"<<omp_get_thread_num()<<"\n";
		}
		cout<<"  i="<<i<<"  Threads:"<<omp_get_num_threads()<<"\n";		
	}	
}