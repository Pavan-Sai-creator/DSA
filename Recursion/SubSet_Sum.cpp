#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsetSum(vector<int> arr,vector<int> &ans,int index,vector<int> output)
{
    if(index>=arr.size())
    {
        int sum=0;
        for(int i=0;i<output.size();i++)
            sum+=output[i];
        ans.push_back(sum);
        return;
    }

    subsetSum(arr,ans,index+1,output);
    int ele = arr[index];
    output.push_back(ele);
    subsetSum(arr,ans,index+1,output);
}

int main()
{
    int n=3;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<int> ans;
    vector<int> output;
    int index=0;
    subsetSum(arr,ans,index,output);
    sort(ans.begin(),ans.end());
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}