/*
 * 小根堆构造优先队列
 * 提供：
 *     add 方法往优先队列插入元素
 *     peek 获取首元素 就是权值最小的元素
 *     remove 获取并删除首元素
 *
 *     数组动态增长：1.用链表串联起来 2申请更大的内存 复制原有内容到新内存，，，返回新申请空间
 *     构造函数重载实现：
 *     可变参数实现：
 *     0.malloc实现
 *     1.
 *
 *
 */
#include<stdio.h>
#define maxsize 20//堆容量
int n=1;
int head=1;
void add(int *heap,int e)//插入元素并且保证堆还是小根堆 构造小根堆 直接排序。。。。
{
	int i,t,t1,t2,key;
	heap[n]=e;
	t=n;
	key=n;
	if(n>=2)
	{
	for(i=t/2;i>0;i/=2)
	{
		if(heap[i]>heap[key])//根节点大于子节点值
		{
			if(key+1<=n)//如果存在另一个子节点 找到最小的元素 然后交换元素值 交换位置
			{
				if(heap[key]<heap[key+1])//min的是key
				{
					t1=heap[key];
					heap[key]=heap[i];
					heap[i]=t1;
					key=i;
				}
				else//
				{
					t1=heap[key+1];
					heap[key+1]=heap[i];
					heap[i]=t1;
					key=i;
				}
			}
			else//不存在另一个子节点
			{
				t1=heap[key];
				heap[key]=heap[i];
				heap[i]=t1;
				key=i;
			}

			
		}
			else// 根节点小于子节点值
		{
			if(key+1<=n)//当key+1也存在 根节点应该小于两个子节点值
			{
				if(heap[key+1]>heap[i]||heap[key+1]>heap[key])//
				{
					key=i;
					break;
				}
				else if(heap[key+1]<heap[key])
				{
					if(heap[key+1]>heap[i])//
					{
						key=i;
						break;
					}
					else
					{
						t1=heap[key+1];
						heap[key+1]=heap[i];
						heap[i]=t1;
						key=i;
					}
				}
			}
			else//key+1子节点不存在
			{
				key=i;
				break;

			}
		}
    		        
	    }	
	}
}
void adjust(int *heap,int key)
{

}
int peek(int *heap)
{
	printf("堆顶元素值为:%d",heap[head]);
	return heap[head];
}
int remove_(int *heap)//直接排序 后移 头部偏移指针
{
	int ret=heap[head];
	printf("ret:%d",heap[head]);
	head++;
}
void print(int *heap)
{
	int i;
	for(i=1;i<n;i++)
	printf("%d ",heap[i]);
}
int main()
{
	int i,value;
	int heap[maxsize];
	int a[8]={49,38,65,97,76,13,27,49};
	for(i=0;i<8;i++)
	{
		add(heap,a[i]);
		n++;
		//print(heap);
		//printf("\n");
	}
	peek(heap);

}
