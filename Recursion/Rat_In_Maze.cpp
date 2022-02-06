//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
class Solution{
    bool isSafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> m)
    {
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (m[x][y]==1))
            return true;
        else
            return false;
    }
    void solve(vector<vector<int>> m,int n,vector<vector<int>> visited,int x,int y,vector<string> &ans,string path)
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        visited[x][y]=1;
        
        //Down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx,newy,n,visited,m))
        {
            path.push_back('D');
            //visited[newx][newy]=1;
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        
        //Left
        newx = x;
        newy = y-1;
        if (isSafe(newx,newy,n,visited,m))
        {
            path.push_back('L');
           // visited[newx][newy]=1;
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        //Right
        newx = x;
        newy = y+1;
        if (isSafe(newx,newy,n,visited,m))
        {
            path.push_back('R');
            //visited[newx][newy]=1;
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        // Up
        newx = x-1;
        newy = y;
        if (isSafe(newx,newy,n,visited,m))
        {
            path.push_back('U');
            //visited[newx][newy]=1;
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        
        
        visited[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0)
            return ans;
        string path = "";
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                visited[i][j]=0;
        int srcx=0,srcy=0;
        
        
        solve(m,n,visited,srcx,srcy,ans,path);
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};