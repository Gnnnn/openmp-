// File: CopyInTest.cpp 
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
int Num01;
//private����
int CopyInTest()
{
	cout<<"CopyInTest�����\n";
	int i=0,j,chunkSize = 1;
	double starttime,endtime;	
	

	starttime=omp_get_wtime();
	#pragma omp threadprivate(Num01)
		Num01=10;
	#pragma omp parallel for private(j)
	for(i=0;i<8;i++)
	{
		for(j=0;j<100000000;j++);
		cout<<"Ϊ��"<<Num01<<"\n";
	}
	endtime=omp_get_wtime();
	cout<<"�����ʱΪ��"<<endtime-starttime<<"s\n";
	return 0;
}