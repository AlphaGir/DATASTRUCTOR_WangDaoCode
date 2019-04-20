/*
 *暴力破解字符串匹配
 *
 *
 */
#include<stdio.h>
#include<string.h>
int match(char *t,char *p)//文本 t,要匹配的模式 p;找到文本中第一个匹配子串最左元素的下标
{
	int i,j,q;
	i=j=q=0;
	int n=strlen(t);
	int m=strlen(p);
	while(i<=n-m)
	{
		i=q;
		while(j<m&&t[i]==p[j])
		{
				i++;
				j++;
				if(j==m) return q;
		}
		j=0;
		q++;
	}
	return -1;
}
int main()
{
	char* t="abcdbcd";
	char* p="ecd";
	int ret=match(t,p);
	printf("ret:%d",ret);
}
