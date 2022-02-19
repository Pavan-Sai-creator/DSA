//https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11

int f(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
{
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int up = grid[i][j]+f(i-1,j,dp,grid);
    int left = grid[i][j]+f(i,j-1,dp,grid);
    
    return dp[i][j]=min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,dp,grid);
}