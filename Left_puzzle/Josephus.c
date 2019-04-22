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
// create 创建一个循环链表  
// delete 删除一个节点
// jose 主函数循环
int nodesum;
void create(link* head,int n)
{
	link h,r,t,p;
	int m=n;
	int i=1;
	if(*head==0)
		*head=(link)malloc(sizeof(node));
	r=(link)malloc(sizeof(node));
	r=*head;
	(*head)->data=1;
	(*head)->value=1;
	for(i=2;i<=n;i++)
	{
		p=(link)malloc(sizeof(node));//
		p->data=0;
		p->value=i;
		r->next=p;
		r=r->next;
	}
	p->next=*head;
}
void delete_(link *head,link v)//
{
	link n=(link)malloc(sizeof(node));
	link q=(link)malloc(sizeof(node));
	link t=(link)malloc(sizeof(node));
	link temp=(link)malloc(sizeof(node));
	
	if(v==*head)
  {
		for(n=*head;n->next!=*head;n=n->next);
		temp=*head;
		*head=(*head)->next;
		n->next=*head;
		free(temp);
  }
	else
  {
	n=*head;
	while(n->next!=*head)
	{
		q=n;
		if(n->next==v)
		{
		   t=n->next;
		   n->next=t->next;
		   free(t);
		   break;
		}
		n=n->next;
	}
   }

}

int Jose(link *head,int m)
{
	link t=(link)malloc(sizeof(node));
	link q=(link)malloc(sizeof(node));
	t=*head;
	q=t;
	while(nodesum>1)
	{
		//printf("v:%d %d\n",t->value,t->data);
		q=t;
		if(t->data==m)
		{
			
			t->next->data=1;
			printf("kill:%d\n",t->value);
			delete_(head,t);
			nodesum--;
		}
		else
		{
			t->next->data=t->data+1;
		}
		//printf("-------------------\n");
		t=t->next;
	}
	return (*head)->value;
}
void print(link head)
{
	link t=(link)malloc(sizeof(node));
	t=head;
	while(t->next!=head)
	{
		printf("%d %d\n",t->value,t->data);
		t=t->next;
	}
	printf("\n");
}
int main()
{
	link h=0;
	node head;
	//h=&head;
	int n,m;
	scanf("%d %d",&n,&m);
	create(&h,n);
	nodesum=n;
	print(h);
	//delete_(&h,1);
	//print(h);
	//delete_(&h,6);
	//print(h);
	int ret=Jose(&h,m);
	printf("\nleft:%d",ret);
	//link p=h->next;
	//free(h);
	//h=p;
	//print(h);
	
}
