/*
 *设计一个递归算法 删除不带头节点的单链表L中所有值为x的结点
 *
 */
#include<stdio.h>
#include<stdlib.h>
//#include"list.h"
typedef struct link
{
        int data;
        struct link *next;
}link,*list;
void delete(list L,int x)
{
        list p=(list)malloc(sizeof(link));
	if(L==0)
		return ;
	if(L->data==x)
	{
		p=L;
		L=L->next;
		free(p);
		delete(L,x);
	}
	else
        delete(L->next,x);
}
void create(list a,int m)
{

   list t=(list)malloc(sizeof(link));
   t=a;
   list p;
   while(m--)
   {
        p=(list)malloc(sizeof(link));
        scanf("%d",&(p->data));
        p->next=0;
        t->next=p;
        t=p;
   }
}
void print(list a)
{

        list h=(list)malloc(sizeof(link));
        h=a->next;
        while(h)
        {
                printf("%d ",h->data);
                        h=h->next;
        }
        printf("\n");

}



int main()
{
	link p;
	create(&p,3);
	delete(&p,3);
	print(&p);
}
