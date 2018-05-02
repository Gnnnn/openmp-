// File: PrivateTest.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//private测试
int PrivateTest()
{
	cout<<"private输出：\n";
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

