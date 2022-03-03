//https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1
//https://www.youtube.com/watch?v=_-QHfMDde90&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if (root == NULL)
    {
        return NULL;
    }
    if (root->data == P->data || root->data == Q->data)
    {
        return root;
    }
    TreeNode<int>* leftans = LCAinaBST(root->left,P, Q);
    TreeNode<int>* rightans = LCAinaBST(root->right, P, Q);
    if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }
    else if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    else if (leftans == NULL && rightans == NULL)
    {
        return NULL;
    }
    return root;
}