// 分段并行.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void SectionsTest();
void SectionsTest02();
void SectionsTest03();
int _tmain(int argc, _TCHAR* argv[])
{
	SectionsTest();
	cout<<"\n";
	//SectionsTest02();

	SectionsTest03();
	int i;
	cin>>i;
	return 0;
}

