//https://leetcode.com/problems/palindrome-partitioning/
#include<string>
#include<algorithm>
class Solution {
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void fun(int index,string s,vector<vector<string>> &ans,vector<string> &output)
    {
        if(index==s.size())
        {
            ans.push_back(output);
            return;
        }
        for(int i=index;i<s.size();++i)
        {
            if(isPalindrome(s,index,i))
            {
                output.push_back(s.substr(index,i-index+1));
                fun(i+1,s,ans,output);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        int index=0;
        fun(0,s,ans,output);
        
        return ans;
    }
};