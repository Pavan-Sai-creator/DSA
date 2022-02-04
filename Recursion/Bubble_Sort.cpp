#include<iostream>
using namespace std;

void sort(int arr[],int n)
{
    if(n==1)
        return;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    sort(arr,--n);
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    sort(arr,n);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}