/*
 *
 *
 */
#include<stdio.h>
#include"list.h"
#include<stdlib.h>
list dis(list hc)
{
	list p,q,ra,t,t1,t2,a,b;
	p=(list)malloc(sizeof(link));
	q=(list)malloc(sizeof(link));
	b=(list)malloc(sizeof(link));
	ra=(list)malloc(sizeof(link));
	p=hc->next;
	ra=hc;
	b->next=0;
	while(p)
	{
		ra->next=p;
		ra=p;
		p=p->next;
		q=p->next;
		p->next=b->next;
		b->next=p;
		p=q;
	}
	ra->next=0;

	return b;
}
int main()
{
	link p;
	list a;
	create(&p,6);
	a=dis(&p);
	//print(&p);
	print(a);
}
