/*
 *顺序查找
 *
 */
#include<stdio.h>
int search(int *a,int n,int k)
{
	int i,j;
	a[n]=k;
	i=0;
	while(a[i]!=k)
	i++;
	if(i>=n) return -1;
	else return i;
}
int main()
{
	int a[7]={2,3,0,1,-2,4};
	int ret=search(a,6,1);
	printf("ret:%d",ret);
}
