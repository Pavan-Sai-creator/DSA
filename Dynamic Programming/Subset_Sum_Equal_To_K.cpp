//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0
// https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15

bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(ind==0) return arr[ind]==target;
    
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notake = f(ind-1,target,arr,dp);
    bool take = false;
    if(arr[ind]<=target) take = f(ind-1,target-arr[ind],arr,dp);
    
    return dp[ind][target]= take|notake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}