// ͬ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void FindMaxNum();
void DataRaceTest();
void FindMaxNumCritical();
void AtomicTest();
void FindMaxNumLock();
void OrderedTest();
void MasterTest();
int _tmain(int argc, _TCHAR* argv[])
{
	//FindMaxNum();
	//DataRaceTest();
	//FindMaxNumCritical();
	//AtomicTest();
	//FindMaxNumLock();
	//OrderedTest();
	MasterTest();
	int i;
	cin>>i;
	return 0;
}

