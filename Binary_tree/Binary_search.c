/* 二叉树创建 遍历
 * 前缀表达式 中缀表达式 后缀表达式 对应 先序遍历 中序遍历 后序遍历 
 * P121-123
 * ------------
 *  递归函数在递归过程中，不同层次的同名变量在赋值的时候会产生相互影响吗？是一定会，还是有可能会？ 不会。
 *  在子函数内部 malloc a
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct binode
{
	struct binode *left;
	struct binode *right;
	int data;
}binode,*bino;
bino createBi();//递归创建二叉树
void search_Mid(bino B);//中序递归遍历二叉树

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
}
int main()
{
	binode B;
	bino p;
	p=createBi();
	//printf("\n");
	printf("中序遍历为:\n");
	search_Mid(p);
	printf("\n");
}
