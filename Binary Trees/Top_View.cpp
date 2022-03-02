//https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
#include<map>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    queue<pair<TreeNode<int> *,int>> q;
    map<int,int> nodes;
    vector<int> ans;
    if(root==NULL) return ans;
    q.push({root,0});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode<int> *node = p.first;
        int line=p.second;
        if(nodes.find(line)==nodes.end()) nodes[line]=node->val;
        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }
    for(auto it : nodes)
    {
        ans.push_back(it.second);
    }
    return ans;
}