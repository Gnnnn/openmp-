// File: FirstPrivateTest.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//FirstPrivateTest����
int FirstPrivateTest()
{
	cout<<"firstprivate�����\n";
	int i=0,j=10;
	#pragma omp parallel for firstprivate(j)
	for(i=0;i<8;i++)
	{
		cout<<i<<":"<<j<<"\n";
		j++;
		cout<<i<<":"<<j<<"\n";
	}	
	return 0;
}

