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
int n=0;
int head=1;
void add(int *heap,int e)//插入元素并且保证堆还是小根堆 构造小根堆 直接排序。。。。
{
	int i,t,t1,t2,key;
	n++;
	heap[n]=e;
	t=n;
	key=n;
	adjust(heap,key);
	printf("新增元素:%d\n",e);
}
void adjust1(int *heap,int s,int m)//假设heap[s+1……m]已经是堆，将heap[s……m]调整为以heap[s]为根的小根堆
{

	int t,t1,j;
	t=s;
	for(j=t*2;j<=m;j*=2)
	{
		if(j<m&&heap[j]>heap[j+1])//
		++j;
		if(heap[s]<=heap[j]) break;
		t1=heap[s];
		heap[s]=heap[j];
		heap[j]=t1;
		s=j;
	}

}
void sort1(int *heap,int n1)
{
	int i,x;
	for(i=n1;i>1;--i)
	{
		x=heap[1];
		heap[1]=heap[i];
		heap[i]=x;
		adjust1(heap,1,i-1);
	}
}

void adjust(int *heap,int key)
{
	int t,t1,i;
	t=n;
	if(n>=2)
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
				else
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
					//break;
				}
				else if(heap[key+1]<heap[key])
				{
					if(heap[key+1]>heap[i])//
					{
						key=i;
					//	break;
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
				//break;

			}
		}
    		        
	    }
		

}
int peek(int *heap)
{
	adjust1(heap,1,n);
	printf("top:%d\n",heap[1]);
	return heap[1];
}
int remove_(int *heap)
{
	int ret=heap[1];
	heap[1]=heap[n];
	heap[n]=ret;
	printf("删除的元素:%d\n",ret);
	n--;
	//head++;
	adjust1(heap,1,n);
}
void print(int *heap)
{
	int i;
	for(i=1;i<=n;i++)
	printf("%d ",heap[i]);
	printf("\n");
}
int main()
{
	int i,value,ret;
	int heap[maxsize];
	int a[8]={49,38,65,97,76,13,27,49};
	for(i=0;i<8;i++)
		add(heap,a[i]);
	printf("n=%d top:%d\n",n,heap[1]);
	//print(heap);
	add(heap,-1);
	printf("n=%d top:%d",n,heap[1]);
	remove_(heap);
	peek(heap);
	remove_(heap);
	peek(heap);
	add(heap,-2);
	add(heap,100);
	add(heap,10);
	remove_(heap);
	peek(heap);
}	
