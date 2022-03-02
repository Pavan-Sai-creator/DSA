//https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
    int maxHeight(TreeNode *node,int &maxi)
    {
        if(node==NULL) return 0;
        
        int left = maxHeight(node->left,maxi);
        int right = maxHeight(node->right,maxi);
        maxi = max(maxi,left+right);
        
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* node) {
        int maxi=INT_MIN;
        int height = maxHeight(node,maxi);
        return maxi;
        
    }
};