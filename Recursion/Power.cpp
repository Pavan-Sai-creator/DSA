#include<iostream>
using namespace std;

int power(int m,int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return m;
     int m_power_n_dividedBy_2 = power(m,n/2);
     if(n%2==0)
        return m_power_n_dividedBy_2*m_power_n_dividedBy_2;
    else
        return m*m_power_n_dividedBy_2*m_power_n_dividedBy_2;
}

int main()
{
    int m,n;
    cout<<"Enter m,n values to calculate m^n: ";
    cin>>m>>n;
    cout<<power(m,n);

    return 0;
}