// File: ����ѭ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;

int PrivateTest();
int FirstPrivateTest();
int LastPrivateTest();
int ReductionTest();
int ScheduleTest();
int CopyInTest();

int _tmain(int argc, _TCHAR* argv[])
{
	int i=0;
	//PrivateTest();
	//FirstPrivateTest();
	//LastPrivateTest();
	//ReductionTest();
	//ScheduleTest();
	CopyInTest();
	
	/*cout<<"�����\n";
	int i=0,j=10;
	j=0;
	#pragma omp parallel for private(j)
	for(i=0;i<8;i++)
	{
		cout<<i<<":"<<j<<"\n";
		j++;
		cout<<i<<":"<<j<<"\n";
	}*/
	cin>>i;
	return 0;
}

