// File: ReductionTest.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//ReductionTest����
int ReductionTest()
{
	cout<<"reduction�����\n";
	int i=0,j=10;
	#pragma omp parallel for reduction(+:j)
	for(i=0;i<8;i++)
	{
		j=2;
		cout<<i<<":"<<j<<"\n";
		j++;
		cout<<i<<":"<<j<<"\n";
	}
	cout<<"���j��ֵΪ:"<<j<<"\n";
	return 0;
}