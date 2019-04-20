/*17:25
 *两个整数序列A B已经存入两个单链表中 判断序列B是不是序列A的连续子序列
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
  list p;
  L->next=0;
  while(m--)
  {
	  p=(list)malloc(sizeof(link));
	  scanf("%d",&(p->data));
	  p->next=L->next;
	  L->next=p;
  }
}
void print(list L)
{
	list h=(list)malloc(sizeof(link));
	h=L->next;
	while(h)
	{
		printf("%d ",h->data);
		h=h->next;
        }
	printf("\n");
}
void judege(list A,list B)
{
	list t=(list)malloc(sizeof(link));
	list t1=(list)malloc(sizeof(link));
	list m=(list)malloc(sizeof(link));
	m=0;
	t=A->next;
	t1=B->next;
	int flag=-1;
	while(t)
	{
		if(t->data==t1->data)
		{
			
			while(t1)
			{
				if(t1->data==t->data)
				{
						t=t->next;
					        t1=t1->next;
					flag=1;
					if(t==0||t1==0)
						break;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		else
		{	
			m=t;
			t=t->next;
		}
		if(flag==0)
		{

		t1=B->next;
		t=m->next;
		}
		else if(flag==1)
		{
			printf("yes\n");
			exit(0);
		
		}
	}
	printf("no\n");
}
int main()
{
  link p,q;
  create(&p,5);
  print(&p);
  create(&q,3);
  print(&q);
  judege(&p,&q);
}
