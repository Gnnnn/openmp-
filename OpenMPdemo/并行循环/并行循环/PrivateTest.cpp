// File: PrivateTest.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//private����
int PrivateTest()
{
	cout<<"private�����\n";
	int i=0,j=10;
	#pragma omp parallel for private(j)
	for(i=0;i<8;i++)
	{
		j=10;
		cout<<i<<":"<<j<<"\n";
		j++;
		cout<<i<<":"<<j<<"\n";
	}	
	return 0;
}

