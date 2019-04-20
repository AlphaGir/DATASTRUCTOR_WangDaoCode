#include"list.h"
#include<stdio.h>
#include<stdlib.h>
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
//        p->pre=t;
        t->next=p;
        t=p;
   }
  // p->next=L;
  // L->pre=p;


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
