/*
 *求两个序列的中位数
 * 两个序列是升序
 * 思路 先排序把两个等长序列变成一个序列然后 直接通过下标找到中间那个
 * 22:03-22:33
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mid(int *a,int *b,int length)
{
	int c,i,j,t;
	i=j=t=0;
	int *p=(int*)malloc(sizeof(int)*length*2);
	memset(p,0,sizeof(int)*2*length);
	while(i<length&&j<length)
	{
		if(a[i]<b[j])
		{
			p[t]=a[i];
			i++;
			t++;
		}
		else
		{
			p[t]=b[j];
			t++;
			j++;
		}
	}
	printf("i=%d j=%d\n",i,j);
	if(i<length)
	{
		for(;i<length;i++)
		{
			p[t++]=a[i];
		}
	}
	if(j<length)
	{
		for(;j<length;j++)
		{
			p[t++]=b[j];
		}
	}
	for(i=0;i<length*2;i++)
	{
		printf("%d ",p[i]);
	}
	return p[length];
}
	
int main()
{
	int a[]={11,13,15,17,19};
	int b[]={2,4,6,8,20};
	int ret=mid(a,b,5);
	printf("ret=%d\n",ret);
}
