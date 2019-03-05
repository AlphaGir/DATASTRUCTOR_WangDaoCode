#include<stdio.h>
#include"list.h"
#include<stdlib.h>
void norepeat(list head)
{
	list p,q,r,t;
	p=(list)malloc(sizeof(link));
	q=(list)malloc(sizeof(link));
	t=(list)malloc(sizeof(link));
	p=head->next;
	head->next=0;
	t=head;
	while(p->next)
	{
		if(p->data!=p->next->data)
		{
			q=p;
			t->next=q;
			t=q;
		}
		p=p->next;
	}
	t->next=p;
}
int main()
{
	link p;
	create(&p,10);
	norepeat(&p);
	print(&p);
}
