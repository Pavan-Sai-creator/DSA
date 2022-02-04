#include<iostream>
using namespace std;

void printNumbersReverse(int n)
{
    if(n==0)
        return;

    cout<<n<<" ";
    printNumbersReverse(n-1);
}
void printNumbers(int n)
{
    if(n==0)
        return;

    printNumbers(n-1);
    cout<<n<<" ";
}

int main()
{
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    printNumbers(n);
    cout<<endl;
    printNumbersReverse(n);

    return 0;
}