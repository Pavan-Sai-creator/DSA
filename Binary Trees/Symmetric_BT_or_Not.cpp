//https://www.codingninjas.com/codestudio/problems/tree-symmetricity_630426?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1
bool isSymmetricHelp(BinaryTreeNode<int>* p,BinaryTreeNode<int>* q)
{
    if(p==NULL || q==NULL) return p==q;
    if(p->data!=q->data) return false;
    return isSymmetricHelp(p->left,q->right) && isSymmetricHelp(p->right,q->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{ 
    return root==NULL || isSymmetricHelp(root->left,root->right);   
}