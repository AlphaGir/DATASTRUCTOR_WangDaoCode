/*
 * 堆排序
 * 
 * 这里的堆是一种数据结构。。。。。。
 *
 * 这里堆一般是指二叉堆 然后二叉堆一般是用完全二叉树结构，所以用数组结构
 *
 * 堆排序用的堆一般是大根堆（堆顶记录的关键字最大）也可以用小根堆，小根堆据说是用来构造优先队列的。。。。。
 * 
 * 堆排序:创建大根堆 对堆进行排序（堆排序的过程其实就是每次把堆顶和最后一个元素交换，然后再创建大根堆，继续交换，直到没有元素可以交换为止）
 * 堆创建：1，要把一个无序序列调整为堆 ，必须将完全二叉树中每个节点为根的子树都调整为堆，只有一个节点的树必然是根，所以叶子节点必然是堆，不需要调整。完全二叉树里 叶子节点是序号大于n/2的。调整（节点与它左右节点值比较，如果大于左右节点，则不管，小于左右节点与最大交换，然后检查调整后其子树是不是也符合）
 *
 */
#include<stdio.h>
void adjust(int *a,int i,int n)//调整堆 如果已经是堆则不需要调整否则调整为堆，然后检查堆的子树是不是构成堆。
{
	int j,key,t;
	key=i;
	for(j=2*i;j<=n;j*=2)
	{
		if(j<n&&a[j]<a[j+1]) ++j;//选出子树里较大的一个
		if(a[i]>=a[j]) break;//如果本身就大于子树则不用比较 跳出循环
		t=a[i];
		a[i]=a[j];
		a[j]=t;//如果小于 则交换
		i=j;//交换后 检查子树
	}
		
}
void create(int *a,int n)
{
	int i;
	for(i=n/2;i>0;--i)
		adjust(a,i,n);
}
void print(int *a,int n)
{
	int i;
	for(i=1;i<n;i++)
		printf("%d ",a[i]);
}
void sort(int *a,int n)
{
	int i,x;
	for(i=n;i>1;--i)
	{
		x=a[1];
		a[1]=a[i];
		a[i]=x;
		adjust(a,1,i-1);
	}
}
int main()
{
	int a[9]={0,49,38,65,97,76,13,27,49};
	create(a,8);
	print(a,9);
	sort(a,8);
	printf("\n");
	print(a,9);
}
