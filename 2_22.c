/* 12年统考题
 * 20年数据结构考研复习22题
 * 
 * 找两个单词链表相同后缀的起始位置 
 *
 * 比如 loading being 相同后缀 ing 找到i的节点    位置
 *
 * 1.从2个链表尾端开始寻找相同后缀 往前寻找 直到 找不到相同为止
 *
 * 这个思路太天真了，这是一个单链表，不是双向链表 所以说明结构重要性
 *
 * 链表的字符串匹配模式 
 * 11:30 
 * 我讨厌缓冲  去™的行缓冲 
 * 写完思考：左值右值容易写错 还有尾插为什么是带头节点 
 *           scanf 输入问题 行缓冲
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linklist
{
	char data;
	struct linklist *next;
}linklist,*link;
void create(link L,int n)
{
     link h,p,r;
     h=(link)malloc(sizeof(linklist));
     r=(link)malloc(sizeof(linklist));
     //L->next=NULL;
     r=L;
     //L->next=NULL;
     char c;
     while(n--)
     {
        p=(link)malloc(sizeof(linklist));
	//scanf("%c",&(p->data));
	c=getchar();
	p->data=c;
	p->next=NULL;
	r->next=p;
	r=p;
     }
}
void print(link L)
{
   link h=(link)malloc(sizeof(linklist));
   h=L->next;
   while(h)
   {
	   printf("%c",h->data);
	   h=h->next;
   }
   printf("\n");
}
link find(link str1,link str2)
{
    link tem=(link)malloc(sizeof(linklist));
    link tem1=(link)malloc(sizeof(linklist));
    link p=(link)malloc(sizeof(linklist));
    link p1=(link)malloc(sizeof(linklist));
    link p2=(link)malloc(sizeof(linklist));
    tem=str1->next;
    tem1=str2->next;
    char c;
    int i,j;
    i=j=0;
    p=NULL;
    p2=NULL;
    while(tem)
    {
	    p1=tem;
	    while(tem1)
	    {
	    if(tem->data==tem1->data)
              {
		  p=tem1;
		//  c=tem->data;
		  break;
	      }
	    else 
		{
			if((tem1->next)!=NULL)
			tem1=tem1->next;
			else
			{
				tem1=str2->next;	
				tem=p1;
				break;
			}
			//p=NULL;
			//tem=p1;

		}

	    }
	    if(p==tem1)
	    {
		    if(tem->next!=NULL&&tem1->next!=NULL)
		    {
		    tem=tem->next;
		    tem1=tem1->next;
		    }
		    else
		    {	    p=p2->next;	
			    break;
		    }	    
	    }
	    else
	    {	  
	    p2=tem;	    
	    tem=tem->next;
	    }
	    
    }
    return p;
    
}
void main()
{
   linklist str1,str2;
   create(&str1,11);
   print(&str1);
   getchar();
   create(&str2,5);
   print(&str2);
   link s=(link)malloc(sizeof(linklist));
   s=find(&str1,&str2);
   printf("pointer:%c",s->data);
}
