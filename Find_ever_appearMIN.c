/*
 *给定一个含有n个整数的数组，找到数组中未出现的最小正整数。
 * 譬如 数组-5 3 2 3最小正整数：1
 *      数组 1 2 3  最小正整数：4
 *
 *
 *      数组 -1 -2 -3 最小正整数：1
 *--------------------
 * author:Alpha
 * time:16:30 begin
 *      16:56 不想写 
 *      18:30写完了，，，我TMD写了2小时
 *       写得丑死了代码
 * 思路：正整数关系就是1的关系，
 * 1.给数组排序
 * 2.然后根据min max 值判断来找到数组中未出现的最小正整数
 *  直接根据最小值 +1 如果<0继续加 如果与下一个数相等继续加 不等下一个数且>=0
 * 首先找到数组最小值如果为1那就再找最大值 最大值+1   即可 ，如果min小于0那就找第二小的如果还是小于1继续找直到>0 就-1 如果+1 如果最小值<1
 */
#include<stdio.h>
void sort(int *a,int length)
{
	int i,j,t;
	for(i=0;i<length-1;i++)
	{
		for(j=0;j<length-i-1;j++)
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
void print(int *a,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int judege(int *a,int t,int length)
{
	int i,r;
	r=1;
	for(i=0;i<length;i++)
	{
		if(t==a[i])
			r=0;
	}
	printf("r=%d\n",r);
	return r;
}
int find(int *a,int length)
{
	int ret=-100;
	sort(a,length);
	print(a,length);
	int i,t,t1;
	if(a[0]<=0)
	{	t=a[0]+1;
	        int len=a[length-1]-a[0];
	for(i=0;i<len+1;i++)
	{
		printf("t=%d\n",t);
		   int n=judege(a,t,length); 
	  if(t>0&&n>0)
	  {	
		  printf("t=%d\n",t);
		  ret=t;
	  }
	  else

		t++;
	}
	}
	else
	{
		t1=a[0];
			int len=a[length-1]-a[0];
		
		for(i=0;i<len+2;i++)
		{
		                printf("t1=%d\n",t1);

			int n=judege(a,t1,length);
			if(n>0)
			{
				ret=t1;
			}
			else 
			
			t1++;
			
		}
	}
	return ret;
}


int another(int *a,int length)
{
	int i,*n;
	int ret=-1;
	n=(int *)malloc(sizeof(int*)*length);
	memset(n,0,sizeof(int)*length);
	for(i=0;i<length;i++)
	{
		if(a[i]>0&&a[i]<=length)
		{
			n[a[i]]++;
		}
	}
	for(i=0;i<length;i++)
	{
		if(n[i]==0)
 			{
				ret=i;
				break;
			}
	}
	if(ret==-1)
		ret=length+1;
	return ret;
}
	

		

int main()
{
	int a[]={1,2};
        //sort(a,4);
	//print(a,4);
	int ret=find(a,2);
	printf("ret=%d",ret);
}
