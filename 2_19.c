/* 找到循环单链表中结点值最小的结点 并输出，然后删掉 直到链表为空最后删掉表头结点
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct link
{
	int data;
	struct link * next;
}link,*linklist;
void create(linklist L,int m)
{
	linklist t=(linklist)malloc(sizeof(link));
	L->next=0;
	t=L;
	linklist p;
	while(m--)
	{
		p=(linklist)malloc(sizeof(link));
		scanf("%d",&(p->data));
		t->next=p;
		p->next=0;
		t=p;
		
	}
	p->next=L;

}
void delete(linklist L)
{
	linklist t=(linklist)malloc(sizeof(link));
	t=L->next;
	linklist t1=(linklist)malloc(sizeof(link));
	t1=L;
	int k=t1->next->data;
	linklist p=(linklist)malloc(sizeof(link));
	p=NULL;
	linklist m=(linklist)malloc(sizeof(link));
	linklist m1=(linklist)malloc(sizeof(link));
	while(t&&t!=L)
	{
		k=10;
		while(t1->next!=L)
		{
			//printf("k:%d\n",k);
			if(t1->next->data<=k)
			{
				k=t1->next->data;
				p=t1;
			}
	//		m
			t1=t1->next;

		}
		printf("value of min:%d\n",k);
		m1=p->next;
		p->next=m1->next;
		//k=10;
		t1=L;
		//print(L);
		t=t->next;
		//else
		//	break;
	}
	free(L);//释放头结点 会段错误
}	
void print(linklist L)
{
   linklist h=(linklist)malloc(sizeof(link));
   h=L->next;
   //printf("%d",h->next->data);
   while(h!=L)
   {
	   printf("%d ",h->data);
	   h=h->next;
   }
   printf("\n");
   //printf("%d",h->next->data);
}
int main()
{
   link p;
   create(&p,5);
   print(&p);
   delete(&p);


}
