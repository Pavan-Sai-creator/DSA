//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20



// int f(int ind,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp)
// {
//     if(ind==0)
//     {
//         if(wt[0]<=W) return val[0];
//         return 0;
//     }
    
//     if(dp[ind][W] != -1) return dp[ind][W];
//     int notake = 0 + f(ind-1,W,wt,val,dp);
//     int take = INT_MIN;
//     if(wt[ind]<=W) take=val[ind] + f(ind-1,W-wt[ind],wt,val,dp);
    
//     return dp[ind][W]=max(notake,take);
// }

// TABULATION //

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int W=wt[0];W<=maxWeight;W++) dp[0][W]=val[0];
    
    for(int ind=1;ind<n;ind++)
    {
        for(int W=0;W<=maxWeight;W++)
        {
            int notake = 0 + dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind]<=W) take=val[ind] + dp[ind-1][W-wt[ind]];
            dp[ind][W]=max(take,notake);
        }
    }
	return dp[n-1][maxWeight];
}