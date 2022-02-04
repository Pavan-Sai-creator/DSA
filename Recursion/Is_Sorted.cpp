#include<iostream>
using namespace std;

bool isSorted(int arr[],int n)
{
    if(n==0 || n==1)
        return true;
    if(arr[0]>arr[1])
        return false;
    return isSorted(arr+1,--n);
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    isSorted(arr,n)?cout<<"Sorted":cout<<"Not Sorted";

    return 0;
}