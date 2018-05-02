//File :FindMaxNumLock.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void FindMaxNumLock()
{
	omp_lock_t lock;
	int numbers[10]={5,7,8,2,4,5,6,7,9,7};
	int i,j,max=0;
	omp_init_lock(&lock);//��ʼ��lock
	#pragma omp parallel for
	for(i=0;i<10;i++)
	{		
		omp_set_lock(&lock);//����lock
		if(max<numbers[i])
		{	
			j=omp_get_num_threads();//��ȡ�߳���Ŀ
			cout<<"�߳���Ŀ��"<<j<<"\n";
			j=omp_get_thread_num();//��ǰ�߳�ID
			cout<<"��ǰ�߳�ID��"<<j<<"\n";	
			max=numbers[i];			
		}		
		omp_unset_lock(&lock);//��ԭlock
	}
	omp_destroy_lock(&lock);//�ͷ�lock
	cout<<"���ֵΪ��"<<max<<"\n";
}