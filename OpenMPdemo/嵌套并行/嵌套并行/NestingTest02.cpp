//File :NestingTest02.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void test()
{
	int i;
	for(i=0;i<100000000;i++);
}
void NestingTest02()
{
	int i,j;
	double starttime,endtime;
	starttime=omp_get_wtime();
	#pragma omp parallel for
	for(i=0;i<8;i++)
	{
		#pragma omp parallel for
		for(j=0;j<8;j++)
		{
			test();
		}
	}	
	endtime=omp_get_wtime();
	cout<<"¼ÆËãºÄÊ±£º"<<endtime-starttime<<"s\n";
}