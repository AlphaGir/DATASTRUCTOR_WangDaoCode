/*16:53 带头结点的单链表就地逆转
 * 头插法
 *
 */
#include<stdio.h>
#include"list.h"
#include<stdlib.h>
void reverse(list L)
{

	list p,q,t;
	p=(list)malloc(sizeof(link));
	t=(list)malloc(sizeof(link));
	p=L->next;
	
	L->next=0;
	while(p)
	{
		//printf("p:%d",p->data);
		//L->data=p->data;
		//p->next=L->next;
		//L->next=p;
		//p=p->next;
		t=p->next;
		p->next=L->next;
		L->next=p;
		p=t;
	}
	printf("\n");
}
int main()
{
	link p;
	create(&p,5);
	reverse(&p);
	print(&p);
}
