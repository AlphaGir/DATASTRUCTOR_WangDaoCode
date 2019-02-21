/*有两个循环单链表 链表头指针分别为h1,h2
 * 编写一个函数将链表h2链接到h1后面，
 * 要求链接后的链表仍然保持循环链表形式
 * 13:37
 * 
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct link
{
	int data;
	struct link *next;
}link,*list;
void create(list L,int m)
{
     list h=(list)malloc(sizeof(link));
     h=L->next;
     list r=(list)malloc(sizeof(link));
     r=L;
     list p;
     while(m--)
     {
	     p=(list)malloc(sizeof(link));
	     scanf("%d",&(p->data));
	     p->next=0;
	     r->next=p;
	     r=p;
     }
     p->next=L;    

}
void print(list L)
{
	list t=(list)malloc(sizeof(link));
	t=L->next;
	while(t!=L)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("\n");
}
void print1(list L,list h2)
{
        list t=(list)malloc(sizeof(link));
        t=L->next;
        while(t!=L)
        {
		if(t==h2)
		{
			t=t->next;
			continue;
		}
		
                printf("%d ",t->data);
                t=t->next;
        }
        printf("\n");
}

void connect(list h1,list h2)
{
     list t,t1,t2;
     t=(list)malloc(sizeof(link));
     t1=(list)malloc(sizeof(link));
     t=h1->next;
     t1=h2->next;
    /* while(t1!=h2)
	     t1=t1->next;
     t1->next=h1;*/
     while(t)
     {		
	     //printf("%d ",t->data);
	     if(t->next==h1)
	     {
		     t->next=h2;
	     }
	     else if(t->next==h2)
	     {
		     t->next=h1;
		     break;
	     }
	     t=t->next;
     }
      
    



     	
}
int main()
{
  link p,q;
  create(&p,5);
  print(&p);
  create(&q,5);
  print(&q);
  connect(&p,&q);
  print1(&p,&q);

}
