/*查找倒数第k个位置的节点 输出data值 返回1 否则返回0
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linklist
{
	int data;
	struct linklist *link;
}linklist,*lin;
void create(lin L,int m)
{
  lin r,p;
  r=(lin)malloc(sizeof(linklist));
  //p=(lin)malloc(sizeof(linklist));
  r=L;
  while(m--)
  {
	p=(lin)malloc(sizeof(linklist));
	scanf("%d",&(p->data));
	p->link=NULL;
	r->link=p;
	r=p;
  }	
}
int find(lin L,int k)//方便理解但是比较弱智
{
    int t=0;
    int length=len(L);
    if(k>length)
	    return 0;
    else
    {
	    lin h=(lin)malloc(sizeof(linklist));
	    h=L->link;
	    t=length-k;
	    while(t--)
	    {
		if(h->link!=NULL)    
		h=h->link;
	    }
	    printf("%d",h->data);
    }
    printf("\n");
    return 1;
}
int find_new(lin L,int k)//答案解法 双指针 一趟遍历 采用补充方法
{
	lin p,q,h;
	p=(lin)malloc(sizeof(linklist));
	q=(lin)malloc(sizeof(linklist));
	p=L->link;
	q=L->link;
	int count=0;
	while(p)
	{
	  if(count<k) count++;
	  else q=q->link;
	  p=p->link;
	}
	if(count<k)
		return 0;
	else
		printf("%d",q->data);
	return 1;
}
int len(lin L)
{
    int length=0;
    lin h=(lin)malloc(sizeof(linklist));
    h=L->link;
    while(h)
    {
	    //printf("%d ",h->data);
	    h=h->link;
	    length++;
    }
    printf("\n");
    return length;
}
int main()
{
  linklist h;
  create(&h,8);
  /*
   * printf("len=%d",len(&h));
  find(&h,4);
  find(&h,8);*/
  printf("ret=%d\n",find_new(&h,6));


}
