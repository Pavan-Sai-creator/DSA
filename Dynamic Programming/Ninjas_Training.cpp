//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//https://www.youtube.com/watch?v=AE39gJYuRog&t=1949s

int f(int day,int last,vector<vector<int>> &points,int dp[][4])
{
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last)
            {
                maxi=max(maxi,points[day][task]);
            }
        }
        return maxi;
    }
    
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point = points[day][task] + f(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int dp[n-1][4];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[i][j]=-1;
        }
    }
    return f(n-1,3,points,dp);
}