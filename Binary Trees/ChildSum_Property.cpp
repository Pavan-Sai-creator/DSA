//https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos
//https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30

void reorder(BinaryTreeNode<int> *root)
{
    if(root==NULL) return;
    
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    if(child>=root->data) root->data = child;
    else
    {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    
    reorder(root->left);
    reorder(root->right);
    
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data = tot;
}
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root);
}  