/*
 *二叉排序树 创建删除查找
 *创建：插入节点方式。
 * 创建成功以后（有序）  查找
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Binary
{
	struct Binary * left,*right;
	int value;
}Binary,*binary;
binary insert(binary B,int n);
binary create(binary B,int *a,int n)
{
	int i,j;
	B=0;
	for(i=0;i<n;i++)
	{
		B=insert(B,a[i]);
	}
	return B;
}
binary insert(binary B,int n)
{
	if(!B)
	{
		binary S;
		S=(binary)malloc(sizeof(Binary));
		S->value=n;
		S->left=0;
		S->right=0;
		B=S;
	}
	else if(n<B->value)
	{	
	       	B->left=insert(B->left,n);
	}
	else if(n>B->value)
	{
		B->right=insert(B->right,n);
	}
	return B;
}
binary delete(binary B,int n)
{
	binary p,f,q,s;
	p=(binary)malloc(sizeof(Binary));
	f=(binary)malloc(sizeof(Binary));
	q=(binary)malloc(sizeof(Binary));
	s=(binary)malloc(sizeof(Binary));
	p=B;
	f=0;
	while(p)
	{
//		f=p;
		if(p->value==n) break;
		f=p;
		if(p->value>n) 
			p=p->left;
		else
			p=p->right;
	}
	if(!p) return B;
	q=p;
	if(p->left!=0&&p->right!=0)
	{
		s=p->left;
		while(s->right)
		{
			q=s;
			s=s->right;
		}
		p->value=s->value;
		if(q!=p) q->right=s->left;
		else q->left=s->left;
		//free(s);
		return B;
	}
	else if(!p->right)
	{
		p=p->left;
	}
	else if(!p->left)
	{
		p=p->right;
	}
	if(!f) B=p;
	else if(q==f->left) f->left=p;
	else f->right=p;
	return B;
}
binary search(binary B,int key)//此处如果是int 直接search(B->left|right,key)则不能找到，改成返回值就可以 这是为什么呢。
{
	if(B)
	{
		if(B->value==key) return B;
		else if(key>B->value) return search(B->right,key);
		else return search(B->left,key);
	}
}
void print(binary B)
{
	if(B)
	{
		print(B->left);
		printf("%d ",B->value);
		print(B->right);
	}
}
int main()
{
	int a[]={45,24,53,45,12,24,90};
	binary b,s;
	s=create(b,a,7);
	print(s);
	b=delete(s,24);
	printf("\n");
	print(b);
	//printf("ret:%d\n",b->value);
}

