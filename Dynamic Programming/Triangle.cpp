//https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=SrP-PiLSYC0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=12

int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp)
{
    if(i==n-1)
    {
        return triangle[i][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int d = triangle[i][j] + f(i+1,j,triangle,n,dp);
    int dg = triangle[i][j] + f(i+1,j+1,triangle,n,dp);
    return dp[i][j]=min(d,dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){

    int dp[n][n];
    for(int i=n-1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=triangle[i][j];
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            int d = triangle[i][j] + dp[i+1][j];
            int dg = triangle[i][j] + dp[i+1][j+1];
            dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0];
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     return f(0,0,triangle,n,dp);
}