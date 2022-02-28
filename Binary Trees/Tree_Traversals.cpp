//https://www.codingninjas.com/codestudio/problems/tree-traversal_981269?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
//https://www.youtube.com/watch?v=jmy0LaGET1I&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=5

void inOrder(BinaryTreeNode<int> *node,vector<int> &in)
{
    if(node==NULL) return;
    inOrder(node->left,in);
    in.push_back(node->data);
    inOrder(node->right,in);
}
void preOrder(BinaryTreeNode<int> *node,vector<int> &pre)
{
    if(node==NULL) return;
    
    pre.push_back(node->data);
    preOrder(node->left,pre);
    preOrder(node->right,pre);
}
void postOrder(BinaryTreeNode<int> *node,vector<int> &post)
{
    if(node==NULL) return;
    
    postOrder(node->left,post);
    postOrder(node->right,post);
    post.push_back(node->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> in;
    vector<int> pre;
    vector<int> pos;
    vector<vector<int>> ans;
    
    inOrder(root,in);
    preOrder(root,pre);
    postOrder(root,pos);
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(pos);
    
    return ans;
}
