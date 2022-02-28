//https://leetcode.com/problems/binary-tree-preorder-traversal/
//https://www.youtube.com/watch?v=Bfqd8BsPVuw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=10

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        if(root==NULL) return ans;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node!=NULL)
            {
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }
        }
        return ans;
    }
};