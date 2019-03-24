/*终于要写哈夫曼树啦
 *1.哈夫曼树创建
 *n个叶子节点的哈夫曼树总共会有2n-1个节点
 *一切按照数据结构书上写的：
 * select函数不好写，它要求出第一小 第二小的东西，然后求完以后还要去除掉，还是下标，下标,还在不断变化，，，，，，，
 * 1.找到最小的第一个 找到最小的第二个，然后
 * 哈夫曼树 小demo 仅仅测试一句话英文， 压缩前 压缩后 还原。
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct huff
{
	int parent,lc,rc;
	int wight;
	char s[100];
	int len;
	char code;
}huff,*huffman;
typedef struct wordnum
{
	int num;
	char c;
}wordnum,*word;
void select1(huff *h,int n,int *s1,int *s2);
void huff_code(huff *h,int n)//还真的得用回溯，，，
{
    int i,j,c,f;
    for(i=0;i<n;i++)
    {
	char t[100];
	int l=0;
	c=i;
	f=h[i].parent;
	while(f!=0)
	{
		//l++;
		if(h[f].lc==c) 
			t[l]='0';
		else
			t[l]='1';
		c=f;f=h[f].parent;
		l++;
	}
        t[l]='\0';
	printf("t:%s\n",t);
	for(j=l-2;j>=0;j--)
	{
		h[i].s[h[i].len]=t[j];
		h[i].len++;
	}
    }
    
}


void huff_create(huff *h,int n)//有n个带权节点需要构成一棵哈夫曼树
{
	int m;
	int x[100];
	int s1,s2;
	m=2*n-1;
	//h=(huff*)malloc(sizeof(huff)*m);
	int i,j,t;
	for(i=0;i<m;i++)
	{
		h[i].parent=-1;
		h[i].lc=0;
		h[i].rc=0;
		h[i].len=0;
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
	/*for(j=0;j<m;j++)
	{
		printf("id=%d wight:%d \n",j,h[j].wight);
	}*/
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
void press(char *origin,huff *h,char *new)//origin为原来的未压缩的，new为压缩的
{
	
}
void print(huff *h,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("id=%d wight=%d code:%s\n",i,h[i].wight,h[i].s);
	}
}
void count(wordnum *w,char *s)//计算一句话字符出现次数
{
	int i,j,t;
	t=0;
	for(i=0;i<strlen(s);i++)
	{
		wordnum[i].c=s[i];
		wordnum[i].num++;
		if(s[i]
		
int main()
{
	char sentence[100];
	printf("测试的英文语句:\n");
	scanf("%s",sentence);
	int length;
	length=strlen(sentence);
	wordnum w[length];
	count(w,sentence);
	huff h[100];
	huff_create(h,8);
	//printf("test:%d",h[0].wight);
	huff_code(h,8);
	print(h,8);
}
