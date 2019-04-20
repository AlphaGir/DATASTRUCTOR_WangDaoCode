#ifndef _LIST_H
#define _LIST_H
typedef struct link
{
        int data;
        struct link *next;
}link,*list;
extern void create(list a,int m);
extern void print(list a);
#endif
