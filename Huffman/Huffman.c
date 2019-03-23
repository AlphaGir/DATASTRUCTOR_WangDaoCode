/*终于要写哈夫曼树啦
 *1.哈夫曼树创建
 *n个叶子节点的哈夫曼树总共会有2n-1个节点
 *一切按照数据结构书上写的：
 * select函数不好写，它要求出第一小 第二小的东西，然后求完以后还要去除掉，还是下标，下标,还在不断变化，，，，，，，
 * 1.找到最小的第一个 找到最小的第二个，然后
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct huff
{
	int parent,lc,rc;
	int wight;
}huff,*huffman;
void select1(huff *h,int n,int *s1,int *s2);
char** huff_code(huff *h,int n)//还真的得用回溯，，，
{
    int i,j,c,f;
    char **s1=(char**)malloc(sizeof(n));

    for(i=0;i<n;i++)
    {
	char *s=(char *)malloc(sizeof(n));//怎么确定呢；    
	c=i;
	f=h[i].parent;
	int start=n-1;
	s[n-1]='\0';
	while(f!=0)
	{
		--start;
		if(h[f].lc==c) 
			s[start]='0';
		else
			s[start]='1';
		c=f;f=h[f].parent;
	}
	s1[i]=(char*)malloc(sizeof(n-start));
	strcpy(s1[i],s[start]);
    }
    return s1;
}


void huff_create(huff *h,int n)//有n个带权节点需要构成一棵哈夫曼树
{
	int m;
	int x[100];
	int s1,s2;
	m=2*n-1;
	h=(huff*)malloc(sizeof(huff)*m);
	int i,j,t;
	for(i=0;i<m;i++)
	{
		h[i].parent=-1;
		h[i].lc=0;
		h[i].rc=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&h[i].wight);
		x[i]=h[i].wight;
	}
	for(i=n;i<m;++i)
	{
		t=i-1;
		select1(h,t,&s1,&s2);
   	        h[s1].parent=i;
                h[s2].parent=i;

		h[i].wight=h[s1].wight+h[s2].wight;
		h[i].lc=s1;
		h[i].rc=s2;
		//a++;
		//b++;
	}
	for(j=0;j<m;j++)
	{
		printf("id=%d wight:%d \n",j,h[j].wight);
	}
	//return h;
}

void sort(int *x,int n)
{
	int i,j;
	int a;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(x[j]>x[j+1])
			{
				a=x[j];
				x[j]=x[j+1];
				x[j+1]=a;
			}
		}
	}
}
void select1(huff *h,int n,int *s1,int *s2)//可以更简略 但是 总是写得很混乱 所以将就看看
{
	int x=100;
        int min=1000;
	int i;
	int a,b;
        for(i=0;i<=n;i++)
        {
	//	printf("--------------------\n");
	//	printf("id=%d %d %d\n",i,h[i].wight,h[i].parent);
		if(h[i].parent!=-1) continue;
		if(h[i].parent==-1)
		{
                if(h[i].wight<x)
                {
                        min=x;
                        x=h[i].wight;
                }
                else
                {
                        if(h[i].wight<min)
			{
			    	min=h[i].wight;
			}
                }
		}
        }
	for(i=0;i<=n;i++)
	{
		if(h[i].wight==x&&h[i].parent==-1)
		{
			a=i;
			break;
		}
	}
	for(i=0;i<=n;i++)
		if(h[i].wight==min&&h[i].parent==-1&&i!=a)
			b=i;
	
	*s1=a;
	*s2=b;
	//printf("%d %d\n",*s1,*s2);
	
}
int main()
{
	huff h;
	huff_create(&h,8);
	//printf("test:%d",);
	//char **s1=huff_code(&h,8);
}
