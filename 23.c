/*删掉链表重复节点，仅保留第一次出现节点
 *13:37
 *双重循环 时间复杂度为O(N^2) 空间复杂度为O(1)
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct link
{
	int data;
	struct link *next;
}linklist,*lin;
void create(linklist *L,int m)
{
	//*L=(*L)->next;
	linklist* h=(lin)malloc(sizeof(linklist));
	linklist* r=(lin)malloc(sizeof(linklist));
	r=L;
	linklist* p;
	while(m--)
	{
		p=(lin)malloc(sizeof(linklist));
		scanf("%d",&(p->data));
		p->next=NULL;
		r->next=p;
		r=p;
	}
	//r->next=NULL;
}

void print(linklist *p)
{
	//printf("\n");
	p=p->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void delete(linklist* head,int m)
{
	int i,j;
	linklist *tem=(lin)malloc(sizeof(linklist));
	tem=head->next;
	int n=21;
	int a[n+1];
	memset(a,0,sizeof(int)*(n+1));
	
	
	linklist *p=(lin)malloc(sizeof(linklist));
	linklist *t=(lin)malloc(sizeof(linklist));
	linklist *r=(lin)malloc(sizeof(linklist));
	i=0;
	while(tem)
	{
		m=tem->data>0?tem->data:-tem->data;
		if(a[m]==0)
		{
			a[m]=1;
		}
		else
		{
			r=p->next;
			p->next=r->next;
		}
		p=tem;
		tem=tem->next;
	}
	/*
	while(tem)
	{
		if(tem->next!=NULL)
            {
		p=tem->next;
		while(p)
		{
		  if(p->data==tem->data||p->data==-(tem->data))
		  {
                    if(p==tem->next)
		    {
                       r=tem->next;
		       tem->next=r->next;
                     
		    }
		    else
		    {
		      r=t->next;
		      t->next=r->next;
		    }
		
		  }
		  
	          t=p;		  
		  p=p->next;
                  
		}
		printf("\n");
	   }
		if(tem->next!=NULL)
		{	
		tem=tem->next;
		}
		else
			break;
		
	}
	*/
	


}
int main()
{
	int m;
	m=5;
	linklist p;
	create(&p,m);
	printf("\n");
	delete(&p,m);
	print(&p);

}
