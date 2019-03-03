/*排序 从小到大
 * /
 */
#include<stdio.h>
#include"list.h"
#include<stdlib.h>
void sort(list L)
{
	list p,q;
	int t;
	p=(list)malloc(sizeof(link));
	q=(list)malloc(sizeof(link));
	p=L->next;
	q=L->next;
	while(p)
	{
		while(q)
		{
			if(q->next!=0)
			{
			if(q->data>=q->next->data)
			{
				t=q->next->data;
				q->next->data=q->data;
				q->data=t;
			}
			}
			q=q->next;
		}
		q=L->next;
		p=p->next;
	}
}
int main()
{
	link p;
	create(&p,4);
	sort(&p);
	print(&p);
}
