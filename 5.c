/*11:48
 *
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
	printf("\n");
}

void delete(int *a,int s,int t,int length)
{
	int i,j,t1;t1=0;
	if(s>t||length==0)
	{
		printf("erro\n");
		exit(0);
	}
	for(i=0,j=0;i<length,j<length;j++)
		if(a[j]<s||a[j]>t)
		{
			a[i++]=a[j];
			t1++;
		}
	//print(a,t1);
}//I like this code



/*
 void delete(int *a,int s,int t,int length)
{
	int t1=t;
	if(length==0||s>t||s<0||t<0||s>length||t>length) 
	{
		printf("erro\n");
		exit(0);
	}
	else
	{
		if(s!=0)
		{
			int i,j,count;
			for(i=0;i<length;i++)
			{
				if(i>=s&&i<=t)
				{
					a[i]=a[t+1];
					t++;
				}
			}
		}
	}	
	length=length-(t1-s);
	printf("length=%d",length);
	print(a,length-1);
}
*/
int main()
{
    int a[]={1,2,0,2,5,3,3};
    delete(a,2,4,5);
}
