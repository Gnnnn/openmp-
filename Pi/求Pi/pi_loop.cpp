#include "stdafx.h"
#include <omp.h>
#include<iostream>
static long num_steps = 100000000;
double step;
int main1 ()
{
	  int i,j;
	  double x, pi, sum = 0.0;
	  double start_time, run_time;

	  step = 1.0/(double) num_steps;
	 for (j=1;j<=4;j++){
          sum = 0.0;
          omp_set_num_threads(j);
	  start_time = omp_get_wtime();
#pragma omp parallel  
{
#pragma omp single
	  printf(" num_threads = %d\n",omp_get_num_threads());

#pragma omp for reduction(+:sum)
	  for (i=1;i<= num_steps; i++){
		  x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }
}
	  pi = step * sum;
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi is %f in %f seconds and %d threads\n",pi,run_time,i);

	
}  std::cin>>pi;
	 return 0;
}	  





