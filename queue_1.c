/*
 *
 *
 */
#include<stdio.h>
typedef struct queue
{
	int maxsize;
	int a[maxsize];
	int rear;
	int front;
	int tag;
}queue,*Q;
void enqueue(Q queue,int *x)//进队
{
	 
}
void dequeue(Q queue,int *x)//出队
{

}
int main()
{
	queue q;
	q.maxsize=5;
	q.rear=0;
	q.front=0;
	q.tag=0;
}

