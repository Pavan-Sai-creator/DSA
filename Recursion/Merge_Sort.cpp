#include<iostream>
using namespace std;

void merge(int arr[],int s,int e)
{
    int mid = s+(e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int *leftArr = (int*)malloc(len1*sizeof(int));
    int *rightArr = (int*)malloc(len2*sizeof(int));

    int k=s;
    for(int i=0;i<len1;i++)
        leftArr[i]=arr[k++];

    k=mid+1;
    for(int i=0;i<len2;i++)
        rightArr[i]=arr[k++];

    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2<len2)
    {
        if(leftArr[index1]<rightArr[index2])
            arr[s++]=leftArr[index1++];
        else
            arr[s++]=rightArr[index2++];
    }

    while(index1<len1)
        arr[s++]=leftArr[index1++];
    while(index2<len2)
        arr[s++]=rightArr[index2++];

    delete []leftArr;
    delete []rightArr;

}

void mergeSort(int arr[],int s,int e)
{
    if(s>=e)
        return;
    int mid = s+(e-s)/2;
    //Sort left part
    mergeSort(arr,0,mid);
    //Sort right part
    mergeSort(arr,mid+1,e);
    //merge
    merge(arr,s,e);
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)    
        cout<<arr[i]<<" ";

    return 0;
}