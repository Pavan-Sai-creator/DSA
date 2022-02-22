//https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// https://www.youtube.com/watch?v=7win3dcgo3k&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=16

bool f(int ind,int target,vector<int> &arr, vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(ind==0) return arr[ind]==target;
    
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notake = f(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target) take = f(ind-1,target-arr[ind],arr,dp);
    
    return dp[ind][target]=take|notake;
}

bool canPartition(vector<int> &arr, int n)
{
    int totSum=0;
	for(int i=0;i<n;i++)
    {
        totSum+=arr[i];
    }
    if(totSum%2!=0) return false;
    int target = totSum/2;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,target,arr,dp);
    
}
