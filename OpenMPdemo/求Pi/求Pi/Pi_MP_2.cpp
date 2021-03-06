//File: Pi_MP_2.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//函数fx
double function03(int start,int end,int n)
{
	double total=0,x;
	for(int i=start;i<end;i++)
	{
		 x=(double)(2*i+1)/(2*n);
		 total+=1/(1+x*x);
	}
	return total;
}
void Pi_MP_2()
{
	int n;
	cout<<"这是修改后的并行程序!\n请输入计算次数：\n";
	cin>>n;
	double startTime=omp_get_wtime();
	int cpuCount=omp_get_max_threads();	//获取线程最大数目
	double total = 0,tempTotal;
	int tempN=n/cpuCount;
	#pragma omp parallel for private(tempTotal)
	for(int j=0;j<cpuCount;j++)
	{
		int tempI=j*tempN;
		tempTotal=function03( tempI,tempI+tempN,n);
		#pragma omp critical
		total +=tempTotal;
	}
	double endTime=omp_get_wtime();
	total=total*4/n;	
	printf("计算结果为：%E  \n",total);
	cout<<"计算所需时间："<<endTime-startTime<<"\n";
}
