/*<算法设计与分析基础>103页 减治法
 *
 *
 *
 */
#include<stdio.h>
void insert(int *a,int n)
{
	int i,j,v,t;
	for(i=1;i<=n-1;i++)
	{
		v=a[i];
		j=i-1;
		while(a[j]>v&&j>=0)
		{
		a[j+1]=a[j];
		j=j-1;
		}
		a[j+1]=v;
	}
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
int main()
{
	int a[]={1,2,4,3,5,6,0};
	insert(a,7);
	print(a,7);
}

