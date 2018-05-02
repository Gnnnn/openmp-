//File: Test03.cpp
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//循环测试函数
void test03(int space)
{
	for(int i=0;i<space;i++)
	{
		for(int j=0;j<1000;j++);
	}
}

int main()
{
	int total=36288000;
	cout<<"在总计算量一定的情况下测试程序!\n";
	cout<<"请输入并行次数：\n";
	int N=1;
	cin>>N;
	int space =total/N;
	cout<<"开始进行计算...\n";
	double start = omp_get_wtime( );//获取起始时间
	#pragma omp parallel for
	for(int i = 0; i < N; i++)
	{ 
		test03(space);
	}		
	double end = omp_get_wtime( );//获取结束时间
	cout<<"计算耗时为："<<end - start<<"\n";
	cin>>end;
	return 0;
}