//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=ZHyb-A2Mte4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=18

int f(int ind,int tar,vector<int> &num,vector<vector<int>> &dp)
{
    if(tar==0) return 1;
    if(ind==0) return num[0]==tar;
    
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int notake = f(ind-1,tar,num,dp);
    int take = 0;
    if(num[ind]<=tar) take += f(ind-1,tar-num[ind],num,dp);
    
    return dp[ind][tar]=notake+take;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
}