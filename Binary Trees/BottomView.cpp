//https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=1
#include<map>
vector<int> bottomView(BinaryTreeNode<int> * root){

    queue<pair<BinaryTreeNode<int> *,int>> q;
    map<int,int> nodes;
    vector<int> ans;
    if(root==NULL) return ans;
    q.push({root,0});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        BinaryTreeNode<int> *node = p.first;
        int line=p.second;
        nodes[line]=node->data;
        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }
    for(auto it : nodes)
    {
        ans.push_back(it.second);
    }
    return ans;
    
}