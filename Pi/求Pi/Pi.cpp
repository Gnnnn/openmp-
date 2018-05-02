// File :Pi.cpp
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//����fx
double function01(int i,int n)
{
	double x=(double)(2*i+1)/(2*n);
	return 1/(1+x*x);
}
//�����
void GetPi()
{
	int n;
	cout<<"��������������\n";
	cin>>n;
	double total = 0;
	double startTime=omp_get_wtime();
	//#pragma omp parallel for reduction(+:total)
	for(int i=0;i<n;i++)
	{
		total = total + function01(i,n);
	}
	double endTime=omp_get_wtime();
	total=total*4/n;	
	cout<<"������Ϊ��"<<total<<"\n";
	cout<<"��������ʱ�䣺"<<endTime-startTime<<"\n";
}

