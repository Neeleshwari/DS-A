
#include<iostream>
using namespace std;


void merge(int arr[],int start,int mid,int end)
{
	int n = (end - start)+1;
	int *a = new int[n];
	int i,j,k;
	i = start;
	j = mid+1;
	k = 0;

	while ((i<=mid) && (j<=end ))
	{
		if( arr[i] < arr[j] )
		{
			a[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			a[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i<=mid )
	{
		a[k] = arr[i];
		k++;
		i++;
	}
	while ( j<=end)
	{
		a[k] = arr[j];
		k++;
		j++;
	}
	k=0;
	while ( k < n )
	{
		arr[start+k] = a[k];
		k++;
	}
	delete[]a;
}

int mergesort(int arr[],int start,int end)
{
	if ( start == end )
		return 0;
	else
	{
		int mid = start + ((end-start)/2);
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int arr[10] = {56,34,76,12,22,33,44,99,88,10};
	int arr[10] = {3,3,3,3,3,3,3};

	for (int i = 0;i<10;i++)
		cout<<"\t"<<arr[i];

	mergesort(arr,0,6);

	cout<<"\n";
	for (int i = 0;i<10;i++)
		cout<<"\t"<<arr[i];

	return 0;
}
