#include<iostream>
using namespace std;

int partition(int arr[],int s,int e)
{
    int pivot = arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<pivot)
            count++;
    }
    int pivotIndex = s+count;
    swap(arr[s],arr[pivotIndex]);

    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
    }

    return pivotIndex;
}

void QuickSort(int arr[],int s, int e)
{
    if(s>=e)
        return;
    
    int pivotIndex = partition(arr,s,e);
    QuickSort(arr,s,pivotIndex-1);
    QuickSort(arr,pivotIndex+1,e);
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    QuickSort(arr,0,n-1);

    cout<<"Soreted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

        return 0;
}