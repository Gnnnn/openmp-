//File :OrderedTest.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void OrderedTest()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int i,j,b;
	#pragma omp parallel for private(b) ordered
	for(i=0;i<10;i++)
	{
		b=a[i];
		#pragma omp ordered
		cout<<"�߳���Ŀ��"<<omp_get_num_threads()<<"  ��ǰ�߳�ID��"<<omp_get_thread_num()<<"\n";
		a[i]=a[i]+b;
	}
	cout<<"\n������Ϊ��\n";
	for(i=0;i<10;i++)
	{
		cout<<"a["<<i<<"]:"<<a[i]<<"\n";
	}
}