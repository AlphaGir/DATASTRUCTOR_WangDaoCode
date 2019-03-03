#include<stdio.h>
#include"list.h"
#include<stdlib.h>
void pr(list L)
{
	
	
		if(L->next!=0)
		{
			pr(L->next);
		}
		printf("%d ",L->data);
	
}
int main()
{
   link p,q;
   create(&p,5);
   pr(&p);
}
