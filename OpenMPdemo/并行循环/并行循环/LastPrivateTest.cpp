// File: LastPrivateTest.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//LastPrivateTest测试
int LastPrivateTest()
{
	cout<<"lastprivate输出：\n";
	int i=0,j=10;
	#pragma omp parallel for lastprivate(j)
	for(i=0;i<8;i++)
	{
		j=5;
		cout<<i<<":"<<j<<"\n";
		j++;
		cout<<i<<":"<<j<<"\n";
	}
	cout<<"最后j的值为:"<<j<<"\n";
	return 0;
}