#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(int *a,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",a[i]);
	}
}
void move_left(int *a,int length,int p)
{
    int i,j,t;
    int x=p;
    int f=0;
    t=0;
    int *p1=(int*)malloc(sizeof(int)*p);
    int *p2=(int*)malloc(sizeof(int)*(length-p));
    memset(p1,0,sizeof(int)*p);
    memset(p2,0,sizeof(int)*(length-p));
    j=0;
    for(i=length-p;i<length;i++)
    {
	     
	     p1[j++]=a[i];
	    
    }
    for(i=0;i<length-p;i++)
    {
	    p2[t++]=a[i];
    }
    //printf("i=%d j=%d\n",i,j);
    //print(p1,p);
    //printf("\n");
    //print(p2,length-p);
    //printf("\n");
    j=0;
    for(i=0;i<length;i++)
    {       
	    if(i<p)
	    {
		    a[i]=p1[f++];
	    }
	    else
	    {
		    a[i]=p2[j++];
	    }
	    
    }
    //print(a,length);
}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	move_left(a,7,4);
}
