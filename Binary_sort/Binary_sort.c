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
}

