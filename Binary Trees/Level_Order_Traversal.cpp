//https://www.codingninjas.com/codestudio/problems/796002?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
//https://www.youtube.com/watch?v=EoAsWbO7sqg&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=9

void f(BinaryTreeNode<int> *root,vector<int> &ans)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int> *node = q.front();
        ans.push_back(node->val);
        q.pop();
        if(node->left!=NULL) q.push(node->left);
        if(node->right!=NULL) q.push(node->right);
    }
}
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    
    vector<int> ans;
    if(root==NULL) return ans;
    f(root,ans);
    return ans;
}