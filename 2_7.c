#include<stdio.h>
#include"list.h"
#include<stdlib.h>
void delete(list L,int m1,int m2)
{
	list p,pre;
	p=(list)malloc(sizeof(link));
	pre=(list)malloc(sizeof(link));
	p=L->next;
	pre=L;
	while(p)
	{	
		if(p->data>=m1&&p->data<=m2)
		{
			
			pre->next=p->next;
			free(p);
		}
		else
			pre=p;
			p=p->next;
	}
}//2_7
void sort(list L)
{
	list p,q,t,t1,t2;
	p=(list)malloc(sizeof(link));
	q=(list)malloc(sizeof(link));
	t=(list)malloc(sizeof(link));
	t1=(list)malloc(sizeof(link));
	t2=(list)malloc(sizeof(link));
	p=L->next;
	t=L;
	q=L->next;
	int m=0;
	//printf("%d\n",m);
	while(p)
	{
		while(q)
		{

		}
	}
}
int main()
{
	link p;
	create(&p,5);
	print(&p);
	//delete(&p,3,5);
	sort(&p);
	//print(&p);
}
