/*
 *一个长度为N的整形数组a【1，……n]给定整数 x 查找两两之和=x 每个元素只输出一次
 */
#include<stdio.h>
#define n 10
void find(int *a,int x)
{
	int i,j,t;
	i=0;
	j=0;
	t=0;
	for(i=0;i<n;i++)
	{
	   for(j=0;j<n;j++)
	   {
		if(a[i]>=a[i+1])
		{
		   t=a[i];
   		   a[i+1]=a[i];
		   a[i]=t;
		}
	  }
	}
	for(i=0;i<n;i++)
	{
	printf("%d ",a[i]);
	}
	printf("\n");
       	

}
int main()
{
	int a[10]={1,2,3,4,5,6,0,11,8,9};
	find(a,4);
}
