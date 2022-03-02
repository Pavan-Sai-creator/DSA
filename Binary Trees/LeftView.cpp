//https://www.codingninjas.com/codestudio/problems/left-view-of-binary-tree_625707?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=1
void preOrder(BinaryTreeNode<int> *node,vector<int> &ans,int level)
{
    if(node==NULL) return;
    if(level==ans.size()) ans.push_back(node->data);
    
    preOrder(node->left,ans,level+1);
    preOrder(node->right,ans,level+1);
}
void printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    preOrder(root,ans,0);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}