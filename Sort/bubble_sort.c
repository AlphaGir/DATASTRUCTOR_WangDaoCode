/*冒泡排序
 *
 *
 */
#include<stdio.h>
void bubble(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
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
	int a[]={0,3,-2,11,4,6,5};
	bubble(a,7);
	print(a,7);
}
