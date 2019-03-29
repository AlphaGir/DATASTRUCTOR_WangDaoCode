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
binary delete1(binary B,int n)
{
	binary p,q,l,r,h;
	p=(binary)malloc(sizeof(Binary));
	p=B;
	q=(binary)malloc(sizeof(Binary));
	q=p;
	l=(binary)malloc(sizeof(Binary));
	r=(binary)malloc(sizeof(Binary));
	h=(binary)malloc(sizeof(Binary));
	while(p)
	{

		if(p->value==n) break;
		q=p;
		if(p->value>n) p=p->left;
		else p=p->right;
	}
	if(!p) 
	{
		printf("没有找到\n");
		return B;
	}
	if(p->left==0&&p->right!=0)
	{
		                        printf("\n删除的是右边叶子节点\n");
		//p->value=p->right->value;
		if(p==q->left)
		{
		p=p->right;
		q->left=p;
		}
		else
		{
			p=p->right;
			q->right=p;
		}
		
	}
	else if(p->right==0&&p->left!=0)
	{
		                        printf("\n删除的是左边叶子节点\n");
//		p=p->left;
		if(p==q->left)
                {
              p=p->left;
                q->left=p;
                }
                else
                {
                        p=p->left;
                        q->right=p;
                }

	}
	else if(p->left==0&&p->right==0)
	{
		                        printf("\n删除的是叶子节点\n");
					if(p==q->left)
                {
                p=0;
                q->left=p;
                }
                else
                {
                        p=0;
                        q->right=p;
                }

		//p=0;
	}
	else if(p==B)//根节点 既可以选择左子树最大的节点或者右子树最小节点）删除根节点就是修改了根节点值 删掉左子树最大节点
	{
		printf("\n删除的是根节点\n");
		l=p->left;
		if(l->right!=0)
		{
		while(l->right)
		{	
			q=l;
			l=l->right;
		}
		p->value=l->value;
		q->right=0;
		//l=0;
		}
		else
		{
			r=B->right;
			B=l;
			B->right=r;
		}
	}
	else //非根节点
	{
		if(p==q->left)//删掉的是左子树
		{
			printf("\n删除的是左子树\n");
			q=p;
		//printf("only left\n");
			l=p->right;
			while(l->right)
			{	
				q=l;
				l=l->right;
			}
			p->value=l->value;
			q->right=NULL;
			//free(l);
			return B;
		}
		else if(p==q->right)
		{	
			                        printf("\n删除的是右子树\n");
			q=p;
			r=p->left;
			while(r->left)
			{
				q=r;
				r=r->left;
			}
			p->value=r->value;
			q->left=0;
		}
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
	int a[]={45,24,53,52,45,12,0,1,3,25,24,90};
	binary b,s;
	s=create(b,a,12);
	print(s);
	b=delete1(s,53);
	printf("\n");
	print(b);
	//printf("ret:%d\n",b->value);
}

