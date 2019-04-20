/*so easy 中心对称水题
 *我错了 能用链表写的 都不是好东西
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int center(list L)
{
	list t,p,q,r;
	p=(list)malloc(sizeof(link));
	q=(list)malloc(sizeof(link));
	t=(list)malloc(sizeof(link));
	r=(list)malloc(sizeof(link));
	int c=len(L);
	p=L->next;
	r->next=0;
	int ret=-2;
	int count=0;
	while(p)
	{
		q=p->next;
		count++;
		p->next=r->next;
		r->next=p;
		p=q;
		if(count==c/2)
		{
		 t=r->next;
		 if(c%2!=0)
			 p=p->next;
		  while(t)
		  {
			  printf("t=%d p=%d",t->data,p->data);
			  if(t->data!=p->data)
				  return 0;
			  t=t->next;
			  p=p->next;
		  }
		 
		}

	}
	return 1;
}
int len(list L)
{
	int ret;
	ret=0;
	list p=(list)malloc(sizeof(link));
	p=L->next;
	while(p)
	{
		ret++;
		p=p->next;
	}
	return ret;
}
int main()
{
	link p,q;
	int c=-2;
	create(&p,5);
	c=center(&p);
	if(c==1)
		printf("对称\n");
	else
		printf("不对称\n");
	//print(&p);
}

