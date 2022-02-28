//https://www.youtube.com/watch?v=ySp2epYvgTE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=14

class Solution {
public:
    vector<vector<int>> postorderTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> pre,in,post;
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            if(it.second==1)
            {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left!=NULL) st.push({it.first->left,1});
            }
            else if(it.second==2)
            {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->right!=NULL) st.push({it.first->right,1});
            }
            else(it.second==3)
            {
                post.push_back(it.first->val);
            }
        }
        ans.push_back(pre);
        ans.push_back(in);
        ans.push_back(post);
};