//File :AtomicTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void AtomicTest()
{	
	int i,j,total=0,N;
	cout<<"����������N��"<<"\n";
	cin>>N;
	#pragma omp parallel for
	for(i=0;i<=N;i++)
	{		
		j=omp_get_num_threads();//��ȡ�߳���Ŀ
		cout<<"�߳���Ŀ��"<<j<<"\n";
		j=omp_get_thread_num();//��ǰ�߳�ID
		cout<<"��ǰ�߳�ID��"<<j<<"\n";
		#pragma omp atomic
		total+=i;	
	}
	cout<<"�ۼƺ�Ϊ��"<<total<<"\n";
}