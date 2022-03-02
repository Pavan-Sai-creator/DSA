//https://leetcode.com/problems/balanced-binary-tree/ 
class Solution {
    int maxHeight(TreeNode *node)
    {
        if(node==NULL)
            return 0;
        int left = maxHeight(node->left);
        if(left==-1) return -1;
        int right = maxHeight(node->right);
        if(right==-1) return -1;
        
        if(abs(left-right)>1) return -1;
        return 1+max(left,right);
        
    }
public:
    bool isBalanced(TreeNode *root) {
        int height = maxHeight(root);
        if(height!=-1) return true;
        else
            return false;
    }
};