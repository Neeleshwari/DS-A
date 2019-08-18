#include<iostream>

using namespace std;

void swap( int *ar , int *ar1)
{
	int temp;
	 temp = *ar;
	 *ar = *ar1;
	 *ar1 = temp;
}

void max_heapify (int Arr[], int i, int N)
{
    int left = 2*i;                   //left child
    int right = 2*i +1;               //right child
	int largest=0;
    if((left<= N) && (Arr[left] > Arr[i]) )
          largest = left;
    else
         largest = i;
    if((right <= N) && (Arr[right] > Arr[largest] ))
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    } 
 }

void build_heap(int ar[], int N)
{
	for ( int i=N/2;i>=1;i--)
		max_heapify(ar,i,N);
}

void heap_sort(int ar[],int N)
{
	if ( N > 1 )
	{
		swap(ar[N],ar[1]);
		N=N-1;
		max_heapify(ar,1,N);
		heap_sort(ar,N);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//int ar[10] = {0,1,4,2,6,0,5,3};
	int ar[10] = {0,4,7,8,3,2,6,5};
	build_heap(ar,7);

	heap_sort(ar,7);

	return 0;
}
