//File: Test02.cpp
#include "stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
//ѭ�����Ժ���
void test02()
{
	for(int i=0;i<5000000;i++)
	{
		for(int j=0;j<1000;j++);
	}
}

int main1()
{
	cout<<"�����������һ������²��Գ���!\n";
	cout<<"�����벢�д�����\n";
	int N=1;
	cin>>N;
	cout<<"��ʼ���м���...\n";
	double start = omp_get_wtime( );//��ȡ��ʼʱ��
	#pragma omp parallel for
	for(int i = 0; i < N; i++)
	{ 
		test02();
	}		
	double end = omp_get_wtime( );//��ȡ����ʱ��
	cout<<"�����ʱΪ��"<<end - start<<"\n";
	cin>>end;
	return 0;
}