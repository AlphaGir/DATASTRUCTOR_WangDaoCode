/*
 *约瑟夫问题
 *         N个人围成一圈，从第一个开始报数，第M个将被杀掉，最后剩下一个，其余人都将被杀掉。例如N=6，M=5，被杀掉的顺序是：5，4，6，2，3，1
 *         模拟被杀掉的顺序 输出最后一个编号
 *   
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int data;//循环记录下标 要删掉的
	int value;//数值
	struct node *next;
}node,*link;
// create 创建一个循环链表  我讨厌链表创建 讨厌链表头插法 尾插法
// delete 删除一个节点
// jose 主函数循环
void create(link head,int n)
{
	link h,r,t,p;
	int m=n;
	int i=1;
	r=(link)malloc(sizeof(node));
	r=head;
	head->data=1;
	head->value=1;
	for(i=2;i<=n+1;i++)
	{
		p=(link)malloc(sizeof(node));//
		p->data=0;
		p->value=i;
		r->next=p;
		r=r->next;
	}
	r->next=head;
}
void delete_(link head,int v)//
{
	link n=(link)malloc(sizeof(node));
	link q=(link)malloc(sizeof(node));
	link t=(link)malloc(sizeof(node));
	n=head;
	if(v==1)
	{
		q=n->next;
		//free(head);
		printf("%p %p",head,q);
		free(head);
		head=q;
	}
	else
	{
	while(n->next!=head)
	{
		q=n;
		if(n->next->value==v)
		{
		   t=n->next;
		   n->next=t;
		   break;
		}
		n=n->next;
	}
	}
}

/*int Jose(int n,int m)
{
	node j[n+1];
	int i,j1,q,p;
	for(i=1;i<n;i++)
	{
		j[i].data=1;
		j[i].pos=1;
		j[i].value=i;
	}
	q=1;
	p=n+1;
	int count=1;
	for(i=q;count<p;i++)
	{
	
		if(j[i].data==m)
		{
			j[i].pos=0;
			j[i+1].data=1;
			count++;
		}
		else
			j[i+1].data=j[i].data+1;
	}
}*/
void print(link head)
{
	link t=(link)malloc(sizeof(node));
	t=head;
	while(t->next!=head)
	{
		printf("%d ",t->value);
		t=t->next;
	}
	printf("\n");
}
int main()
{
	link h;
	node head;
	h=&head;
	int n,m;
	scanf("%d",&n);
	create(h,n);
	print(h);
	delete_(h,1);
	//print(&head);
}
