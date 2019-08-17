void partition(int arr[],int left,int right,int &le,int &re )
{
	int pi = arr[right];
	int i = left-1;
	int j = left,temp;

	while ( j < right )
	{
		if ( arr[j] <= pi )
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	
	i++;
	temp = arr[i];
	arr[i] = arr[right];
	arr[right] = temp;

	re = i;
	i--;
	int k = i;
	while( k>=left)
	{
		if(arr[k]==pi)
		{
			temp=arr[k];
			arr[k]=arr[i];
			arr[i]=temp;
			i--;
		}
		k--;
	}
	le=i+1;
}

void quicksort(int arr[],int left,int right)
{
	int le,re;
	le = re = -1;
	if ( left < right )
	{
		partition(arr,left,right,le,re);
		quicksort(arr,left,le-1);
		quicksort(arr,re+1,right);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//int arr[10] = {56,34,76,12,22,33,44,99,88,10};
	//int arr[19] = {1,4,2,4,2,4,1,2,4,1,2,2,2,2,4,1,4,4,4};
	//int arr[] = {4,9,4,4,1,9,4,4,9,4,4,1,4};
	//int arr[] = {4, 39, 54, 14, 31, 89, 44, 34, 59, 64, 64, 11, 41}; 
	//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int arr[] = {91, 82, 73, 64, 55, 46, 37, 28, 19, 10}; 
	int arr[] = {4, 9, 4, 4, 9, 1, 1, 1}; 

	for (int i = 0;i<8;i++)
		cout<<"\t"<<arr[i];

	quicksort(arr,0,7);

	cout<<"\n";
	for (int i = 0;i<8;i++)
		cout<<"\t"<<arr[i];

	return 0;
}
