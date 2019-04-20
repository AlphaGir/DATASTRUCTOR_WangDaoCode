/*
 *Binary search
 *非递归
 */
#include<stdio.h>
int mid_search(int *a,int v,int len)
{
	int right=len-1;
	int left=0;
	int mid=(right+left)/2;
	while(left<len&&right>=0)
	{
		if(v>a[mid])
		{
			left=mid+1;
			mid=(left+right)/2;
		}
		else if(v==a[mid])
		{
			printf("find! value at:%d",mid);
			return 1;
		}
		else
		{
			right=mid-1;
			mid=(left+right)/2;
		}
	}
	return 0;
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8};
	int ret=mid_search(a,1,8);
	printf("\n%d\n",ret);
}

