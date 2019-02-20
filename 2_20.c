/*
 *  带表头节点的非循环双向链表 头指针为L,
 *  
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct doublelink
{
	int data;
	struct doublelink *pred;
	struct doublelink *next;
	int freq;
}double_link,*link;
void create(link L,int m)
{
     link p,r;
     r=(link)malloc(sizeof(double_link));
     r=L;
     while(m--)
     {
	     p=(link)malloc(sizeof(double_link));
	     scanf("%d",&(p->data));
	     p->freq=0;
	     r->next=p;
	     p->pred=r;
	     p->next=NULL;
	     r=p;
     }
}
void print(link L)
{
     link h=(link)malloc(sizeof(double_link));
     h=L->next;
     while(h)
     {	
	     printf("%d ",h->data);
	     h=h->next;
     }
	  printf("\n");   
}
link Locate(link L,int x)//省题 ！！！！！！！ 找到某个结点 然后拿出来寻找位置 再插入 双向链表插入 
{
	link h=(link)malloc(sizeof(double_link));
	link p=(link)malloc(sizeof(double_link));
	p=NULL;
	h=L->next;
	while(h&&h->data!=x)
		h=h->next;
	if(!h)
		printf("不存在值为x的结点\n");
	else
	{
		h->freq++;
		h->next->pred=h->pred;
		h->pred->next=h->next;
		p=h->pred;
		while(p!=L&&p->freq<=h->freq)
			p=p->pred;
		//printf("p:%d\n",p->next->data);
		h->next=p->next;
		p->next->pred=h;
		h->pred=p;
		p->next=h;
	}
	return p;	
}
/*void sort(link L,link h)//好好的链表排什么序
{
	link t=(link)malloc(sizeof(double_link));
	t=L->next;
	link t1=(link)malloc(sizeof(double_link));
	link t2=(link)malloc(sizeof(double_link));
	while(t&&t->data!=x)
	{
		
}*/


int main()
{
	double_link p;
	create(&p,5);
	//print(&p);
	Locate(&p,4);
	print(&p);
	Locate(&p,3);
	print(&p);
}
