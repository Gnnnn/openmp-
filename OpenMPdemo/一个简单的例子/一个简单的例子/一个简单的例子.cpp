// һ���򵥵�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<omp.h>
#include <iostream>
using namespace std;

//ѭ�����Ժ���
void test()
{
	for(int i=0;i<1000000;i++)//��������ѭ�������ֱ�Ϊ10000��1000000
	{
	}
}

int _tmain1(int argc, _TCHAR* argv[])
{
	cout<<"����һ�����в��Գ���!\n";
	double start = omp_get_wtime( );//��ȡ��ʼʱ��

	#pragma omp parallel for
	for(int i = 0; i < 8; i++) //��������ѭ�������ֱ�Ϊ10000��100
	{ 
		test();
	}
		
	double end = omp_get_wtime( );
	cout<<"�����ʱΪ��"<<end - start<<"\n";

	cin>>end;
	return 0;
}



