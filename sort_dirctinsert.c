/*
 *直接插入排序
 *21:57
 *插入排序：一个序列【1,2，……】假设第一个元素是有序的 从第二个元素开始和其后一个元素进行比较，依次在当前排好序列的元素里面寻找位置，边找位置边移动 插入
 */
#include<stdio.h>
void insertsort(int *a,int n)
{

	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i;j>0&&a[j-1]>t;j--)
			a[j]=a[j-1];
		a[j]=t;
	}




}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int a[8]={49,38,65,97,76,13,27,49};
	insertsort(a,8);
	print(a,8);
}
