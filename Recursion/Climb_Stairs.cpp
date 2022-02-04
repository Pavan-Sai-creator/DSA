#include<iostream>
using namespace std;

int findWays(int n)
{
    if(n==0 || n==1)
        return 1;
    
    return findWays(n-1)+findWays(n-2);
    
}

int main()
{
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    int ans = findWays(n);
    cout<<ans<<endl;

    return 0;
}