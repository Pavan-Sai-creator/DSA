#include<iostream>
using namespace std;

int two_power(int n)
{
    if(n==0)
        return 1;

    return 2*two_power(n-1);
}

int main()
{
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    int ans = two_power(n);
    cout<<ans<<endl;

    return 0;
}