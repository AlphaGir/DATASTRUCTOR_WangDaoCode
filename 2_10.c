/*
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
list dis(list a)
{
   list p,q,r,h,t;
   p=(list)malloc(sizeof(link));
   q=(list)malloc(sizeof(link));
   r=(list)malloc(sizeof(link));
   h=(list)malloc(sizeof(link));
   list b=(list)malloc(sizeof(link));
   b->next=0;
   p=a->next;
   q=a;
   r=b;
   int i=0;
   while(p)
   {
	i++;
	if(i%2==0)
	{
		t=p->next;
		q->next=t;
		r->next=p;
		r=p;
	}
	q=p;
	p=p->next;
   }
   r->next=0;
   return b;
}
int main()
{
     link p;
     link q;
     list a;
     create(&p,6);
     a=dis(&p);
     print(&p);
     print(a);
}


