// File: ScheduleTest.cpp 
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//private测试
int ScheduleTest()
{
	cout<<"ScheduleTest输出：\n";
	int i=0,j,chunkSize = 1;
	double starttime,endtime;	
	cout<<"请输入并行块的大小（1-200）：\n";
	cin>>chunkSize;
	starttime=omp_get_wtime();
	#pragma omp parallel for private(j) schedule(static,chunkSize)
	for(i=0;i<200;i++)
	{
		for(j=0;j<100000000;j++);
	}
	endtime=omp_get_wtime();
	cout<<"计算耗时为："<<endtime-starttime<<"s\n";
	return 0;
}