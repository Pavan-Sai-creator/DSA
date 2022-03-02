//https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
    int maxHeight(TreeNode *node,int &maxi)
    {
        if(node==NULL) return 0;
        int left = max(0,maxHeight(node->left,maxi));
        int right = max(0,maxHeight(node->right,maxi));
        maxi = max(maxi,node->val+left+right);
        return node->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int height = maxHeight(root,maxi);
        return maxi;
    }
};