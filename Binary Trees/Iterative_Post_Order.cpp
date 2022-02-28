//https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/
//https://www.youtube.com/watch?v=NzIGLLwZBS8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=13

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while(cur!=NULL || !st.empty())
        {
            if(cur!=NULL)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if(temp!=NULL) cur=temp;
                else
                {
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right)
                    {
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
            }
        }
        return ans;
    }
};