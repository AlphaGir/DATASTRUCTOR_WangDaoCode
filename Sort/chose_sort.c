/*选择排序
 *每次选择最小的 与第一个第二个依次交换。
 *
 */
#include<stdio.h>
void selection_sort(int *a,int n)
{
	int i,j,min,t,v;
	t=0;
	for(i=0;i<n;i++)
	{
		min=i;
	         for(j=i+1;j<=n-1;j++)
		 {
			 if(a[j]<a[min])
			 {
				 min=j;
			 }
		 }
		 
		 v=a[i];
		 a[i]=a[min];
		 a[min]=v;
	}
}
void print(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
		 	 
int main()
{
	int a[]={1,3,5,12,-4,0,6};
	selection_sort(a,7);
	print(a,7);
}
