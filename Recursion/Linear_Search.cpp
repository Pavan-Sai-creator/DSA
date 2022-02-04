#include<iostream>
using namespace std;

int search(int arr[],int n,int k)
{
    if(n==0){
        cout<<"Not Found";
        return -1;
    }
    if(arr[0]==k){
        cout<<"Found";
        return n;
    }

    return search(arr+1,--n,k);
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

    int index = search(arr,n,key);
    cout<<" at index "<<n-index;

    return 0;
}