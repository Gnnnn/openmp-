//File :NestedTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void NestedTest()
{
	int i,j,k;
	k=omp_get_nested();
	cout<<"是否支持并行嵌套："<<k<<"\n";
	omp_set_nested(1);//设置支持嵌套并行
	k=omp_get_nested();
	cout<<"是否支持并行嵌套："<<k<<"\n";
	double starttime,endtime;
	starttime=omp_get_wtime();
	#pragma omp parallel for
	for(i=0;i<2;i++)
	{
		#pragma omp parallel for
		for(j=0;j<4;j++)
		{
			cout<<"  i="<<i<<"  j="<<j<<"  Threads:"<<omp_get_num_threads()<<"  ThreadID:"<<omp_get_thread_num()<<"\n";
		}
		cout<<"  I="<<i<<"  Threads:"<<omp_get_num_threads()<<"  ThreadID:"<<omp_get_thread_num()<<"\n";
	}	
	endtime=omp_get_wtime();
	k=omp_get_nested();
	cout<<"是否支持并行嵌套："<<k<<"\n";
	cout<<"计算耗时："<<endtime-starttime<<"s\n";
}