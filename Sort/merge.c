/*合并排序
 * 这个bug明天再改 看书去
 *
 *
 */
#include<stdio.h>
#define maxsize 100
int c[maxsize];
int b[maxsize];
int a1[maxsize];
void copy(int *a,int *c,int l,int n);
void merge(int *a,int *b,int *c,int n,int m);
void mergesort(int *a,int n)
{
	
	if(n>1)
	{
	copy(a,b,0,n/2);
	copy(a,c,n/2+1,n);
	mergesort(b,n/2);
	mergesort(c,n/2);
	merge(a,b,c,n/2,n/2);
	}

}
void copy(int *a,int *c,int l,int n)
{
	int i,j;
	j=0;
	for(i=l;i<n;i++)
		c[j++]=a[i];
}
void merge(int *a,int *b,int *c,int n,int m)
{
	int i,j,k;
	i=j=k=0;
	while(i<n&&j<m)
	{
		if(b[i]<c[j])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	if(i==n)
	{
		int t;
		for(t=k;t<n+m;t++)
			a[t]=b[i++];
	}
	else if(j==m)
	{
		 int t;
                for(t=k;t<n+m;t++)
                        a[t]=c[j++];
	}
			
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
int main()
{
	int a[]={8,3,2,9,7,1,5,4};
	mergesort(a,8);
	print(a,8);
}

