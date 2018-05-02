//File: Pi_MP.cpp
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//����fx
double function02(int i,int n)
{
	double x=(double)(2*i+1)/(2*n);
	return 1/(1+x*x);
}
//�����
void GetPi_MP()
{
	int i,n;
	cout<<"�޸ĺ�Ĳ��г���\n��������������\n";
	cin>>n;
	double total = 0,tempTotal;
	
	int cpuCount=omp_get_max_threads();	//��ȡ�߳������Ŀ
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
	cout<<"������Ϊ��"<<total<<"\n";
	cout<<"��������ʱ�䣺"<<endTime-startTime<<"\n";
}

