//File :FindMaxNum.cpp
#include"stdafx.h"
#include<omp.h>
#include<iostream>
using namespace std;
void FindMaxNum()
{
	int numbers[10]={5,7,8,2,4,5,6,7,9,7};
	int i,j,max=0;
	#pragma omp parallel for
	for(i=0;i<10;i++)
	{
		if(max<numbers[i])
		{	
			j=omp_get_num_threads();//��ȡ�߳���Ŀ
			cout<<"�߳���Ŀ��"<<j<<"\n";
			j=omp_get_thread_num();//��ǰ�߳�ID
			cout<<"��ǰ�߳�ID��"<<j<<"\n";
			max=numbers[i];
		}			
	}
	cout<<"���ֵΪ��"<<max;
}