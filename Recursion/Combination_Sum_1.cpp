//https://leetcode.com/problems/combination-sum/
class Solution {
    void solve(vector<int>& candidates, int target,vector<int> output,int index,vector<vector<int>> &ans)
    {
        if(index==candidates.size())
        {
            if(target==0)
            ans.push_back(output);
            return;
        }
        if(candidates[index]<=target)
        {
            output.push_back(candidates[index]);
            solve(candidates,target-candidates[index],output,index,ans);
            output.pop_back();
        }
        solve(candidates,target,output,index+1,ans);
        
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(candidates,target,output,index,ans);
        
        return ans;
    }
};