//File: Pi_MP.cpp
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//函数fx
double function02(int i,int n)
{
	double x=(double)(2*i+1)/(2*n);
	return 1/(1+x*x);
}
//计算π
void GetPi_MP()
{
	int i,n;
	cout<<"修改后的并行程序！\n请输入计算次数：\n";
	cin>>n;
	double total = 0,tempTotal;
	
	int cpuCount=omp_get_max_threads();	//获取线程最大数目
	int chunkSize =n/cpuCount;
	cout << chunkSize;
	double startTime=omp_get_wtime();
	#pragma omp parallel for private(tempTotal)
	//#pragma omp parallel for shared(total) private(i,tempTotal) schedule(static,chunkSize)
	for(i=0;i<n;i++)
	{
		tempTotal=function02(i,n);
		#pragma omp critical
		total = total +tempTotal;
	}
	double endTime=omp_get_wtime();
	total=total*4/n;	
	cout<<"计算结果为："<<total<<"\n";
	cout<<"计算所需时间："<<endTime-startTime<<"\n";
}

