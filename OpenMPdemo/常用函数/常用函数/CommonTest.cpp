//File :CommonTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;

void CommonTest()
{
	int i,k;
	double starttime,endtime;
	cout<<"���߳��У�"<<"\n";
	i=omp_get_num_threads();//��ȡ�߳���Ŀ
	cout<<"�߳���Ŀ��"<<i<<"\n";
	i=omp_get_max_threads();//��ȡ����߳���Ŀ
	cout<<"����߳���Ŀ��"<<i<<"\n";
	i=omp_get_thread_num();//��ǰ�߳�ID
	cout<<"��ǰ�߳�ID��"<<i<<"\n";
	i=omp_get_num_procs();//��ȡ������õĴ�������Ŀ
	cout<<"������õĴ�������Ŀ��"<<i<<"\n";
	starttime=omp_get_wtime();//��ȡ��ǰʱ��
	cout<<"����ʼ����ʱ�䣺"<<starttime<<"s\n";
	i=omp_in_parallel();//�����Ƿ��ڲ���
	cout<<"�����Ƿ��ڲ��У�"<<i<<"\n";
	i=omp_get_nested();//�Ƿ�������Ƕ��
	cout<<"�Ƿ�������Ƕ�ף�"<<i<<"\n";
	cout<<"\n����ʼ���У�\n";
	#pragma omp parallel for
	for(i=0;i<2;i++)
	{
		k=omp_in_parallel();//�����Ƿ��ڲ���
		cout<<"�����Ƿ��ڲ��У�"<<k<<"\n";
		k=omp_get_num_threads();//��ȡ�߳���Ŀ
		cout<<"�߳���Ŀ��"<<k<<"\n";		
		k=omp_get_thread_num();//��ǰ�߳�ID
		cout<<"��ǰ�߳�ID��"<<k<<"\n";
	}	
	cout<<"\n�����н�����\n";
	endtime=omp_get_wtime();//��ȡ��ǰʱ��
	cout<<"�������ʱ�䣺"<<endtime<<"s\n";
	cout<<"��������ʱ�䣺"<<endtime-starttime<<"s\n";
}