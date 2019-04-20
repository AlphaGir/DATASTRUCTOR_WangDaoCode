/* 2019 2 25
 * 两个单链表元素值依次递增排列 ，
 *
 * 将两个单链表归并为一个按照元素值递减排列的单链表
 *  
 * 并要求利用原来两个单链表节点存放归并后的单链表
 *
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"
void merge(list a,list b)
{

	list p=(list)malloc(sizeof(link));
	list q=(list)malloc(sizeof(link));
	list t=(list)malloc(sizeof(link));
	list t1=(list)malloc(sizeof(link));
	list tem=(list)malloc(sizeof(link));
	list tem1=(list)malloc(sizeof(link));
	p=a->next;
	q=b->next;
	//元素递减 

	while(p&&q)
	{
		t=p;
		t1=q;
		if(p->data>q->data)
		{
			//tem=p->next;
			if(q->next)
			{
			tem1=q->next;
			q->next=p;
			q->next->next=tem1;
			}
			else
				q->next=p;
		}
		else
		{
			//tem=q->next;
			//tem1=p->next;
			if(q!=b->next)
			{
			t1->next=p;
			p->next=q;
			}
			else
			{
			b->next=tem;

			b->next=p;
			p->next=tem;
			}
		}

		//t=p;
		//t1=q;
		p=p->next;
		q=q->next;
	
	
	}
	if(q)
	{
		p->next=q;
	}
}
int main()
{
	link a,b;
	create(&a,5);
	print(&a);
	create(&b,3);
	merge(&a,&b);
	print(&a);
}
