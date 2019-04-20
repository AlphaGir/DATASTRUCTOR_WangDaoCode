/*
 *一个长度为N的整形数组a【1，……n]给定整数 x 查找两两之和=x 每个元素只输出一次
 */
#include<stdio.h>
#define n 11
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
		if(a[j]>a[j+1])
		{
		   t=a[j];
   		   a[j]=a[j+1];
		   a[j+1]=t;
		}
	  }
	}
	for(i=0;i<n;i++)
	{
	printf("%d ",a[i]);
	}
	printf("\n");
 	for(i=0;i<n;)
	{
	for(j=n;j>0;)
	{
		if(a[i]+a[j]>x)
			j--;
		else
			i++;
		//if(i>j) break;
		if(a[i]+a[j]==x)
		{
			printf("%d %d\n",a[i],a[j]);
		}
	}

	}
}

int main()
{
	int a[11]={1,2,3,4,5,6,0,11,8,9};
	find(a,11);
}
