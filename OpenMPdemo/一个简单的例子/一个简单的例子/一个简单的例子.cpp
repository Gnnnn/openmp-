// 一个简单的例子.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<omp.h>
#include <iostream>
using namespace std;

//循环测试函数
void test()
{
	for(int i=0;i<1000000;i++)//测试设置循环次数分别为10000和1000000
	{
	}
}

int _tmain1(int argc, _TCHAR* argv[])
{
	cout<<"这是一个并行测试程序!\n";
	double start = omp_get_wtime( );//获取起始时间

	#pragma omp parallel for
	for(int i = 0; i < 8; i++) //测试设置循环次数分别为10000、100
	{ 
		test();
	}
		
	double end = omp_get_wtime( );
	cout<<"计算耗时为："<<end - start<<"\n";

	cin>>end;
	return 0;
}



