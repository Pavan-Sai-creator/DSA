//https://leetcode.com/problems/maximum-depth-of-binary-tree/


class Solution {
    
public:
    int maxDepth(TreeNode* node) {
        if(node==NULL)
            return 0;
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        
        return 1+max(left,right);
    }
};