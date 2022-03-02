//https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
void addRight(TreeNode<int> *root,vector<int> &ans)
{
    TreeNode<int> *cur = root->right;
    vector<int> temp;
    while(cur)
    {
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        ans.push_back(temp[i]);
    }
}

void addLeaves(TreeNode<int> *node,vector<int> &ans)
{
    if(node==NULL)
    {
        return;
    }
    addLeaves(node->left,ans);
    if(isLeaf(node)) ans.push_back(node->data);
    addLeaves(node->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    
    addLeft(root,ans);
    addLeaves(root,ans);
    addRight(root,ans);
       
    return ans;
    
}