// File: LastPrivateTest.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//LastPrivateTest����
int LastPrivateTest()
{
	cout<<"lastprivate�����\n";
	int i=0,j=10;
	#pragma omp parallel for lastprivate(j)
	for(i=0;i<8;i++)
	{
		j=5;
		cout<<i<<":"<<j<<"\n";
		j++;
		cout<<i<<":"<<j<<"\n";
	}
	cout<<"���j��ֵΪ:"<<j<<"\n";
	return 0;
}