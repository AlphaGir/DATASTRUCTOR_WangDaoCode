/*
 *15:22寻找主元素 15:47   16:06 写完初步
 *思路：1.找到数组里有连续相同元素的子序列（相同下标连续且个数大于2，查看最后一个相同序列下标是不是>n/2;
 * 如果找得到输出主元素，否则输出-1
 * 首先找到子序列们，然后查看有没有下标符合的
 * 这个题目出的不严谨，主元素可不可能有两个？？？算了姑且当一个来
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * int judege(int e,int *a,int length)
{
	int i,r,x;
	x=0;
	for(i=0;i<length;i++)
	{
		if(a[i]==e&&a[i+1]==e||a[i]==e&&a[i-1]==e)
		{
			r=i;
			if(r>length/2)
			{
				x=1;
				break;
			}
		}
	}
	
	
	return x;
}
int findmain(int *a,int length)
{
  int i,j,t,t1;
  t=0;
  int *p=(int*)malloc(sizeof(int*)*length);
  memset(p,0,sizeof(int)*length);
  for(i=0;i<length;i++)
  {
	 
		 p[a[i]]++;
	 
  }
  for(i=0;i<length;i++)
  {
	  printf("%d ",p[i]);
  }
  printf("\n");
  int flag=0;
  for(i=0;i<length;i++)
  {

	  if(p[i]>=2)
	  {
		  printf("元素：%d\n",p[i]);
		int x=judege(i,a,length);
		if(x>0)
		{      
			flag=1;
			return i;
		}
	  }
  }
	  if(flag!=1)
		  return -1;
  

}*/
/*int findmain(int *a,int length)
{
	int i,c,count;
	count=1;
	c=a[0];
	int ret=-1;
	int n=length/2;
	for(i=1;i<length;i++)
	{
		if(a[i]==c)
		{
			count++;
			if(i>=n)
			{ 
				printf("i=%d c=%d ,count=%d\n",i,c,count);
				ret=a[i];
				return a[i];
			}
		}
		else
		{
			count--;
			if(count<=0)
			{
				c=a[i];
				count=1;
			}
		}
	}
	return ret;
	printf("c=%d,count=%d\n",c,count);
}*/
int findMainElem(int R[],int n)
{
    int i,c,count=1;//count为计数工具，记录候选主元素出现的次数
    c=R[0];
    for(i=1;i<n;i++)
    {
	printf("a:i=%d count=%d,c=%d\n",i,count,c);
        if(R[i]==c)
            count++;
        else
            if(count>0)
                count--;
            else
            {
                c=R[i];
                count=1;
            }
	        printf("b:i=%d count=%d,c=%d\n",i,count,c);

    }
            //printf("------------------------i=%d count=%d,c=%d\n",i,count,c);

    if(count>0)
        for(i=count=0;i<n;i++)//统计候选主元素实际出现的次数
            if(R[i]==c)
                count++;
    if(count>n/2)
        return c;
    else return -1;
}










int main()
{
	int a[]={5,5,5,3,5,7,5,5};
	int b[]={0,5,5,3,5,1,5,7};
	int ret;
	ret=findMainElem(a,8);
	printf("ret=%d\n",ret);
	ret=findMainElem(b,8);
	printf("ret=%d\n",ret);
}
