/*
 *12:57
 *
 */
#include<stdio.h>
#include<stdlib.h>
void print(int *a,int length)
{
        int i;
        for(i=0;i<length;i++)
        {
                printf("%d ",a[i]);
        }
}
/*
 void delete(int *a,int length,int x)
{
	int i,j;
	for(i=0,j=0;j<length;j++)
	{
		if(a[j]!=x)
			a[i++]=a[j];
	}
	length=i;
	print(a,length);
}
*/
/*
void reverse(int *a,int length)
{
	int i,j;
	for(i=0;i<length/2;i++)
	{
		j=a[i];
		a[i]=a[length-1-i];
		a[length-1-i]=j;
	}
	print(a,7);
}*/
int deletemin(int *a,int length)
{
	if(length==0)
	{
		printf("errro:\n");
		exit(0);
	}
	int i,j;
	j=a[0];
	int item;
	for(i=0;i<length;i++)
	{
		if(a[i]<=j)
		{
		   j=a[i];
		   item=i;
		}
	}
	a[item]=a[length-1];
	length=length-1;
	print(a,length);
	return j;
}


int main()
{
     int a[]={1,2,3,4,5,6,7};
     //delete(a,9,2);
     int ret=deletemin(a,7);
     printf("\n");
     printf("ret=%d",ret);
}
