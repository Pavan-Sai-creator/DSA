//https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16
void solve(string str,string output,vector<string> &ans,int index)
{
    if(index>str.length()-1)
    {
        if(output.length()>0)
        ans.push_back(output);
        return;
    }
    solve(str,output,ans,index+1);
    char ele = str[index];
    output.push_back(ele);
    solve(str,output,ans,index+1);
}

vector<string> subsequences(string str){
	string output="";
    vector<string> ans;
    int index=0;
    solve(str,output,ans,index);
    
    return ans;
}
