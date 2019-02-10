void insearch(int *a,int x)
{
	int low=0,mid;
	int high=n-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
			break;
		else if(a[mid]<x)
			low=mid+1;
		else
			high=mid-1;
	}
	if(a[mid]==x&&mid!=n-1)
	{
		int t=a[mid];
		a[mid]=a[mid+1];
		a[mid+1]=t;
	}
	if(low>high)
		for(i=n-1;i>high;i--)
			a[i+1]=a[i];
	a[i+1]=x;
}
