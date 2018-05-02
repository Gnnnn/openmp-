// File: FirstPrivateTest.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//FirstPrivateTest测试
int FirstPrivateTest()
{
	cout<<"firstprivate输出：\n";
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

