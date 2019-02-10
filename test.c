#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int *a,int n)
{
    int i;
    int t=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>=t)
        {
            t=a[i];
        }
    }
    return t;
}
int w(int len,int *nums,int numsSize)
{
    int t,i,j;
     int *p=(int *)malloc(sizeof(int)*(len+1));
    memset(p,0,sizeof(int)*(len+1));
    for(i=0;i<len+1;i++)
    {
           for(j=0;j<numsSize;j++)
	   {
		  if(i==nums[j])
		  {
			 p[i]++;
		  } 
	   }
    }
    for(i=0;i<len+1;i++)
    {
        printf("%d ",p[i]);
    }
    int x=numsSize/2;
    for(i=0;i<len+1;i++)
    {
        if(p[i]>=x)
            t=i;
    }
    return t-1;
}
int majorityElement(int* nums, int numsSize) {
    int i,t;
    if(numsSize==1)
        return nums[0];
    
    int len=find(nums,numsSize);
    printf("len=%d\n",len);
    if(len>numsSize)
    {
      t=w(len,nums,numsSize);
    }
    else
    {
        t=w(numsSize,nums,numsSize);
    }
    return t;
}
int main()
{
	int a[]={3,3,4};
	int r;
	r=majorityElement(a,3);
	printf("r=%d\n",r);
}
