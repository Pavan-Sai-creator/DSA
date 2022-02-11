//https://www.codingninjas.com/codestudio/problems/758958?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
void solve(string &s,vector<string> &ans,int index)
{
    if(index>=s.size())
    {
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        swap(s[index],s[i]);
        solve(s,ans,index+1);
        swap(s[index],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    int index=0;
    solve(s,ans,index);
    
    return ans;
}