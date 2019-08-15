#include<iostream>
using namespace std;

int partition(int arr[],int left,int right)
{
	int pi = arr[right];
	int i = left-1;
	int j = left,temp;
	while ( j < right )
	{
		if ( arr[j] <= pi )
		{
			i++;
			temp = arr[j];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	i++;
	temp = arr[i];
	arr[i] = arr[right];
	arr[right] = temp;
	return i;
}

void quicksort(int arr[],int left,int right)
{
	if ( left < right )
	{
		int pi = partition(arr,left,right);
		quicksort(arr,left,pi-1);
		quicksort(arr,pi+1,right);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[10] = {56,34,76,12,22,33,44,99,88,10};

	for (int i = 0;i<10;i++)
		cout<<"\t"<<arr[i];

	quicksort(arr,0,9);

	cout<<"\n";
	for (int i = 0;i<10;i++)
		cout<<"\t"<<arr[i];

	return 0;
}
