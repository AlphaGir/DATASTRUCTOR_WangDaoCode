/*
 *
 *
 */
#include"list.h"
#include<stdio.h>
#include<stdlib.h>
void delete(list L,int x)
{
	list p=(list)malloc(sizeof(link));
	list r=(list)malloc(sizeof(link));
	list q=(list)malloc(sizeof(link));
	p=L->next;
	q=p;
	while(p)
	{	
		
		if(p->data==x)
		{
			r=p;
			q->next=p->next;
			free(r);
		}
		else
		{
			q=p;
			p=p->next;
		}
	}
}
int main()
{
	link p;
	create(&p,5);
	delete(&p,3);
	print(&p);
}
