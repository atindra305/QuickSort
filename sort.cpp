#include<stdio.h>
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}



// Partition
int partition (int arr[], int l, int r)
{
    int pivot = arr[r];    
    int i = (l - 1);  
 
    for (int j = l; j <= r- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}
 


// QuickSort
void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}