#include<stdio.h>
void print(int *a,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",a[i]);
	}
}
void delete(int *a,int length)
{
     int i,j;
     int count=0;
     //int c[length];
     //int t[length];
     for(i=0,j=1;j<length;j++)
     {
	     if(a[i]!=a[j])
	     {
		     a[++i]=a[j];
		     count++;
	     }
     }
     length=length+1;
     
     print(a,count+1);
}
int main()
{
   int a[]={1,1,2,2,2,2,3,4};
   delete(a,8);
}
