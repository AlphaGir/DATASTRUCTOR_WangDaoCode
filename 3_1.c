/*判断进栈 出栈序列是不是合法
 * 出栈的个数要小于=前面进站的，最后出栈 进栈 要持平
 *
 */
#include<stdio.h>
#define n 10
int judege(char *a)
{
	int in,out,i,j;
	in=0;
	out=0;
	for(i=0;i<n;i++)
	{
		if(a[i]=='I')
		{
			in++;
		}
		else if(a[i]=='O')
			out++;
		printf("in=%d out=%d i=%d\n",in,out,i);
		if(i>1&&out>in)
			return 0;
		if(i==n-1&&in!=out)
			return 0;
	}
	return 1;
}
int main()
{
	int i,j;
	
	char a[10];
	scanf("%s",a);
	printf("%s\n",a);
	j=judege(a);
	printf("%d\n",j);
}
