#include<stdio.h>
#include<stdlib.h>
struct avlnode;
typedef struct avlnode *position;
typedef struct avlnode *avltree;
avltree insert(int x,avltree t);
struct avlnode
{
	int e;
	avltree left;
	avltree right;
	int height;
};
int Height(position p)
{
	if(p==0)
		return -1;
	else
		return p->height;
}
int max(int a,int b)
{
	return a>b?a:b;
}
position SingleRotateWithLeft(position k2)
{
	position k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=max(Height(k2->left),Height(k2->right))+1;
	k1->height=max(Height(k1->left),k2->height)+1;
	return k1;
}
position SingleRotateWithRight(position k5)
{	
	position k6;
	k6=k5->right;
	k5->right=k6->left;
	k6->left=k5;
	k5->height=max(Height(k5->left),Height(k5->right))+1;
	k6->height=max(Height(k6->right),k5->height)+1;
	return k6;
}
position DoubleRotateWithLeft(position k3)
{
	k3->left=SingleRotateWithRight(k3->left);
	return SingleRotateWithLeft(k3);
}
position DoubleRotateWithRight(position k4)
{
	k4->right=SingleRotateWithLeft(k4->right);
	return SingleRotateWithRight(k4);
}
avltree insert(int x,avltree t)
{
	if(t==0)
	{
		t=malloc(sizeof(struct avlnode));
		if(t==0)
			printf("out of space!");
		else
		{
			t->e=x;
			t->height=0;
			t->left=t->right=0;
		}
	}
	else if(x<t->e)
	{
		t->left=insert(x,t->left);
		if(Height(t->left)-Height(t->right)==2)
			if(x<t->left->e)
				t=SingleRotateWithLeft(t);
			else
				t=DoubleRotateWithLeft(t);
	}
	else if(x>t->e)
	{
		t->right=insert(x,t->right);
		if(Height(t->right)-Height(t->left)==2)
			if(x>t->right->e)
				t=SingleRotateWithRight(t);
			else
				t=DoubleRotateWithRight(t);
	}
	t->height=max(Height(t->left),Height(t->right))+1;
	return t;
}
avltree create(int *a,int n,avltree b)
{
	b=0;
	int i;
	for(i=0;i<n;i++)
	{
		b=insert(a[i],b);
	}
	return b;
}
void print(avltree t)
{
	if(t)
	{
		//print(t->left);
		printf("value:%d height:%d \n",t->e,t->height);
		print(t->left);
		print(t->right);
	}
}
		
int main()
{
	int a[]={13,24,37,90,53};
	int i;
	avltree t,p;
	p=create(a,5,t);
	print(p);
}
