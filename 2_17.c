/*判断带头结点的循环双链表是否对称
 * 14:58
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct link
{
	int data;
	struct link *pre;
	struct link *next;
}link,*list;
void create(list L,int m)
{
   list t=(list)malloc(sizeof(link));
   t=L;
   list p;
   while(m--)
   {
	p=(list)malloc(sizeof(link));
	scanf("%d",&(p->data));
	p->next=0;
	p->pre=t;
	t->next=p;
	t=p;
   }
   p->next=L;
   L->pre=p;

}
void judege(list L)
{
   list p=(list)malloc(sizeof(link));
   list q=(list)malloc(sizeof(link));
   p=L->next;
   q=L->pre;
   while(p&&q)
   {
	   if(p==L) break;
	   if(q==L) break;
	   if(p->data!=q->data)
	   {
		   printf("该链表不对称\n");
		   exit(0);
		   break;
	   }
	   p=p->pre;
	   q=q->next;
   }
   printf("该链表是对称的\n");

}
void print(list L)
{
  list t=(list)malloc(sizeof(link));
  t=L->pre;
  while(t!=L)
  {
	  printf("%d ",t->data);
	  t=t->pre;
  }
  printf("\n");
}
int main()
{
   link p;
   create(&p,4);
   print(&p);
   judege(&p);
}
