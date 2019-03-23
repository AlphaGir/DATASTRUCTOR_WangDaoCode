/* 二叉树创建 遍历
 * 前缀表达式 中缀表达式 后缀表达式 对应 先序遍历 中序遍历 后序遍历 
 * P121-123
 * ------------
 *  递归函数在递归过程中，不同层次的同名变量在赋值的时候会产生相互影响吗？是一定会，还是有可能会？ 不会。
 *  在子函数内部 malloc 内存情况 当malloc指向的指针已经有内存的时候
 *  递归函数里两个递归语句执行顺序 第一个递归执行完 和我想的一样 是这个垃圾书有问题
 *  二叉树深度问题，递归确实可以解决很多问题，，，，除了不会写 没有毛病
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
typedef struct binode
{
	struct binode *left;
	struct binode *right;
	int data;
}binode,*bino;
typedef struct stack
{
	int top;
	bino da[maxsize];
}stack,*sta;
bino createBi();//递归创建二叉树
void search_Mid(bino B);//中序递归遍历二叉树
bino copy(bino B,bino B1)
{
	if(B)
	{
		//B1->data=B->data;
		B1=(bino)malloc(sizeof(binode));
		B1->data=B->data;
		B1->left=copy(B->left,B1->left);
                B1->right=copy(B->right,B1->right);
	}
	return B1;
}
int depth(bino B)//二叉树深度
{
	int m,n;
	 n=0;
	if(B==0) return 0;
	else
	{
		m=depth(B->left);
		n=depth(B->right);
		if(m>n) return m+1;
		else  return n+1;
	}	
}
int count(bino B)//统计二叉树结点个数
{
	int sum=0;
	if(B==0) return 0;
	else
        return count(B->left)+count(B->right)+1;
}

bino createBi()//递归创建二叉树 
{
	char ch;
	bino B;
	scanf("%d",&ch);
	if(ch==-1) B=NULL;
	else
	{
		B=(bino)malloc(sizeof(binode));//
		B->data=ch;
		B->left=createBi();
		B->right=createBi();
	}
	return B;
}
void search_Mid(bino B)//中序递归遍历二叉树
{
	if(B)
	{
		search_Mid(B->left);
		printf("%d ",B->data);
		search_Mid(B->right);
	}
        //printf("%d ",B->data);
	//printf("------------------------------\n");
}
void push(sta p,bino d)
{
	p->da[++p->top]=d;
}
bino pop(sta p,bino d)
{
	d=p->da[p->top--];
	return d;
}
void search_Mid_no(bino B)
{
	stack t;
	sta s;
	s=&t;
	t.top=-1;
	bino p,q,p1;
        p=B;
	binode b;
	q=(bino)malloc(sizeof(binode));
	while(p||s->top>-1)
	{
		if(p)
		{
			push(s,p);
			p=p->left;
		}	
		else
		{
			p1=pop(s,q);
			printf("value:%d",p1->data);
			p=p1->right;
		}
	}
}
int main()
{
	binode B;
	bino p,p2;
	p=createBi();
	//int h=depth(B);
	//prin("\n");
	//printf("中序遍历为:\n");
	//search_Mid(p);
	//printf(":\n");
	//search_Mid_no(p);
	//p2=copy(p,&B);
	//search_Mid(p2);
	int sum=count(p);
	printf("sum:%d\n",sum);
}
