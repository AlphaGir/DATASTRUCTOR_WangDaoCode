/*
 *利用栈实现递归函数的非递归计算
 *
 * 
 *
 */
#include<stdio.h>
#include<string.h>
#define maxsize 100
int caculate (int n,int p,int x)
{
}
double p(int n,double x)
{
	struct stack{
		int no;
		double val;
	}st[maxsize];
	int top=-1,i;
	double fvl=1,fv2=2*x;
	for(i=n;i>=2;i--)
	{
		top++;
		st[top].no=i;
	}
	while(top>=0)
	{
		st[top].val=2*x*fv2-2*(st[top].no-1)*fvl;
		fv1=fv2;
		fv2=st[top].val;
		top--;
	}
	if(n==0)
	{
		return fv1;
	}
	return fv2;
}

int main()
{
}
