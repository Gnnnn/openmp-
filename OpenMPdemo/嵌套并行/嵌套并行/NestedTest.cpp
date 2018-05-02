//File :NestedTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void NestedTest()
{
	int i,j,k;
	k=omp_get_nested();
	cout<<"�Ƿ�֧�ֲ���Ƕ�ף�"<<k<<"\n";
	omp_set_nested(1);//����֧��Ƕ�ײ���
	k=omp_get_nested();
	cout<<"�Ƿ�֧�ֲ���Ƕ�ף�"<<k<<"\n";
	double starttime,endtime;
	starttime=omp_get_wtime();
	#pragma omp parallel for
	for(i=0;i<2;i++)
	{
		#pragma omp parallel for
		for(j=0;j<4;j++)
		{
			cout<<"  i="<<i<<"  j="<<j<<"  Threads:"<<omp_get_num_threads()<<"  ThreadID:"<<omp_get_thread_num()<<"\n";
		}
		cout<<"  I="<<i<<"  Threads:"<<omp_get_num_threads()<<"  ThreadID:"<<omp_get_thread_num()<<"\n";
	}	
	endtime=omp_get_wtime();
	k=omp_get_nested();
	cout<<"�Ƿ�֧�ֲ���Ƕ�ף�"<<k<<"\n";
	cout<<"�����ʱ��"<<endtime-starttime<<"s\n";
}