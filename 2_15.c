/*
 *链表 a 链表 b 分别表示两个集合 ，元素递增，求 a b 交集并存放在a中
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
	list t;
	L->next=0;
	while(m--)
	{
		t=(list)malloc(sizeof(link));
		scanf("%d",&(t->data));
		t->next=L->next;
		L->next=t;
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
/*void merge(list a,list b)我去你TMD 链表 循环变量都不好取
{
	list h=(list)malloc(sizeof(link));
	h=a->next;
	list t=(list)malloc(sizeof(link));
	t=b->next;
	list p=(list)malloc(sizeof(link));
	list q=(list)malloc(sizeof(link));
	list m=(list)malloc(sizeof(link));
	list n=(list)malloc(sizeof(link));
	list t1=(list)malloc(sizeof(link));
	int flag=0;
	 m=0;
	 int i=2;
	while(h)
	{
		//printf("%d %d\n",h->data,t->data);
		if(flag==0)
		{
		while(t)
		{
			if(t->data==h->data)
			{
				t1=h;
				m=t1;
				if(h->next!=0)
				{
				n=h->next;
				q=h->next;
				p->data=h->data;
				p->next=q;
				h->next=p;
		//		t=t->next;
				flag=1;
				break;
				}
				else
				{
				q->data=h->data;
				q->next=0;
				h->next=q;
				flag=2;
				}
			}
			else
					t=t->next;

		}
		}
		if(flag==2)
			break;
		if(h->next==0)
			break;
		if(t==0&&h->next!=0)
			t=b->next;
		h=h->next;
		if(h==n)
		{
			flag=0;
			if(t->next!=0)
			t=t->next;
			else break;
			
		}

	}
}*/
void merge(list c,list a,list b)
{
	//printf("%p %p",*a,*c);
	list p,h,h1,t;
	h=(list)malloc(sizeof(link));
	h1=(list)malloc(sizeof(link));
	h=a->next;
	h1=b->next;
	t=(list)malloc(sizeof(link));
	t=c;
	int f=0;
    while(h)
    {
	p=(list)malloc(sizeof(link));
	p->data=h->data;
	p->next=0;
	t->next=p;
	t=p;
	while(h1)
	{
		if(h->data==h1->data)
		{
			p=(list)malloc(sizeof(link));
			p->data=h->data;
			p->next=0;
			t->next=p;
			t=p;
			f=1;
			break;
		}
		else
			h1=h1->next;
	}
	if(h1==0&&h!=0)
		h1=b->next;
	if(f==1)
		h1=h1->next;
	h=h->next;
    }
    printf("%p %p\n",a,c);
    /*list a1=(list)malloc(sizeof(link));
    a1=c;
    a=a1;
    printf("%p %p %p\n",a1,a,c);
    //*a1=&c;
    //a=*a1;
    */
    *a=*c;

    
    
}
int main()
{
	link p,q,c;
	//printf("%p %p %p\n",p,q,c);
	create(&p,5);
	print(&p);
	
	create(&q,3);
	print(&q);
	merge(&c,&p,&q);
	//p=c;
	//printf("%p %p %p\n",p,q,c);
	print(&p);
	
}
