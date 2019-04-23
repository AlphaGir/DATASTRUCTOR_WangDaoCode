/*Lomuto划分
 *quick_selection快速选择第n大的元素
 *
 */
#include<stdio.h>
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}
int lomutoPartion(int *a,int r,int l)
{
	int p=a[l];
	int s=l;
	int i,t;
	for(i=l+1;i<r;i++)
	{
		if(a[i]<p)
		{
			s=s+1;
			swap(&a[s],&a[i]);
		}
	}
	swap(&a[s],&a[l]);
	        return s;
}
int quickselect(int *a,int l,int r,int k)
{
	int s=lomutoPartion(a,r,l);
	if(s==l+k-1) return a[s];
	else if(s>l+k-1) quickselect(a,l,s-1,k);
	else quickselect(a,s+1,r,l+k-1-s);
}
void print(int*a,int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int a[]={12,13,11,14,15,10};
	int ret=quickselect(a,0,6,2);
	printf("%d\n",ret);
	print(a,6);
}



