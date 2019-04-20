/*排序 从小到大
 * /
 */
#include<stdio.h>
#include"list.h"
#include<stdlib.h>
void sort(list L)
{
	list p,q,k,m;
	int t;
	k=(list)malloc(sizeof(link));
	p=(list)malloc(sizeof(link));
	q=(list)malloc(sizeof(link));
	m=(list)malloc(sizeof(link));
	p=L->next;
	q=L->next;
	t=q->data;

		while(q)
		{
			
			
			if(q->data<=t)
			{
				k=q;//要删掉的节点
				m=p;//之前节点
				//q->next->data=q->data;
				t=q->data;
			}
			p=q;
			q=q->next;
		}
		if(k==L->next)
		{
			L->next=k->next;
			free(k);
		}
		else
		{
		m->next=k->next;
		free(k);
		}
		
}
int main()
{
	link p;
	create(&p,4);
	sort(&p);
	print(&p);
}
