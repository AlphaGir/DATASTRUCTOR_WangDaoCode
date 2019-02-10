#include<stdio.h>
void exchange(int *a,int n,int m)
{
	int i;
	int b[m+n];
	for(i=0;i<(n+m);i++)
	{
 		b[i]=a[(i+m)%(m+n)];
		
	}
	for(i=0;i<n+m;i++)
	{
		a[i]=b[i];
	}
	//print(b,m+n);
}
void print(int *a,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[]={1,2,3,4,-1,-2,-3};
	exchange(a,3,4);
	print(a,7);
}
