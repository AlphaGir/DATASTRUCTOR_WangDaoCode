/*线性表a中的元素递增有序 在最短时间内找到值为x的元素，如果找到就将该元素与后一交换，否则将其插入表中使表元素扔递增有序
 *17:16 -17:31 使用二分法 查找该元素
 *
 */
#include<stdio.h>
int find_a(int *a,int left,int right,int x)
{
	if(a[left]==x)
	{
		int tem;
		tem=a[left];
		a[left]=a[left+1];
		a[left+1]=tem;
		return 1;
	}
	if(a[right]==x)
		return 1;
	if(a[left]>x)
	{
		int i;
		a[right+1]=a[right];
		for(i=right-1;i>0;i++)
		{
			a[i+1]=a[i];
			//if(i==0)
			//{
			//	int j=a[i];
			//	a[i]=x;
			//}
		}
		a[0]=x;
			
		return 0;
	}
	if(a[right]<x)
	{
		a[right+1]=x;
		return 0;
	}
	if(a[(left+right)/2]==x)
	{	
		int tem;
                int t1=(left+right)/2;
                tem=a[t1];
                a[t1]=a[t1+1];
                a[t1+1]=tem;
		return 1;
	}
	else if(a[(left+right)/2]!=x)
	{
		if(a[(left+right)/2]>x)
		{
			right=(left+right)/2;
			find_a(a,left,right,x);
		}
		else
		{
			left=(left+right)/2;
			find_a(a,left,right,x);
		}
	}

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
     int a[]={-1,0,1,2,3,4,5};
     int ret=-2;
     /*ret=find_a(a,0,6,0);
     printf("ret=%d\n",ret);
     if(ret==1)
     {
     print(a,7);
     }*/
     ret=find_a(a,0,6,-2);
     printf("\n");
     print(a,8);
     printf("\n");
     
     printf("ret=%d\n",ret);
}
