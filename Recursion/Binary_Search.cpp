#include<iostream>
using namespace std;

int search(int arr[],int low,int high,int k)
{
    if(low>high)
        return -1;
    int mid = low + (high-low)/2;
    if(arr[mid]==k)
        return mid;
    if(k>arr[mid])
        return search(arr,mid+1,high,k);
    else
        return search(arr,low,mid-1,k);
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array values: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int key;
    cout<<"Enter key to search: ";
    cin>>key;

    int index = search(arr,0,n-1,key);
    if(index!=-1)
        cout<<"Found at index "<<index;
    else
        cout<<"Not Found";

    return 0;
}