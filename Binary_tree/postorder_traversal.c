/*后序遍历二叉树
 *非递归
 *2019 4 5 11:20
 *
 */
#include<stdio.h>
#include<stdlib.h>
#define maxsize 7
typedef struct bt
{
	int data;
	struct bt *left,*right;
}bt,*btnode;
typedef struct stack 
{
	int top;
	bt bt[maxsize];
}stack,*sta;
void push(sta s,bt d)
{
	s->bt[++s->top]=d;
}
void pop(sta s,bt d)//
{
	s->bt[s->top--];
}
btnode create(int* a,int n)
{
	btnode t;
	//static int i=0;
	if(a[n]==-1) t=0;
	if(t==0)
	{
		t=(btnode)malloc(sizeof(bt));
		t->data=a[n];
		t->left=create(a,n++);
		t->right=create(a,n++);
	}
	return t;

}
void print1(btnode t)
{
	if(t)
	{
		printf("%d ",t->data);
		print1(t->left);
		print1(t->right);
	}
}
/*btnode createtree(int *a,int n,btnode t)
{
	int i;
	//printf("erro\n");
	for(i=0;i<n;i++)
	{
		t=create(a[i],t);
		printf("value:%d",t->data);
	}
	return t;
}*/
void print(btnode t,sta s)//借助栈实现遍历
{

}
int main()
{
	int a[17]={1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
	int i,j;
	btnode t,p;
	p=create(a,0);
	print1(p);
}
