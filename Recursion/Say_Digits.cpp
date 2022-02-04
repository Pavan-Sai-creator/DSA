#include<iostream>
#include<string>
using namespace std;

void sayDigits(string arr[],int n)
{
    if(n==0)
        return;
    int rem = n%10;
    
    n=n/10;
    sayDigits(arr,n);
    cout<<arr[rem]<<" ";

}

int main()
{
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    sayDigits(arr,n);

    return 0;
}