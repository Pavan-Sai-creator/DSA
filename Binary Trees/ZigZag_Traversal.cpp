//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode *> q;
        bool flag=true;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> output(size);
            
            for(int i=0;i<size;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                int index;
                if(flag) index=i;
                else index = (size-1-i);
                output[index] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            
            ans.push_back(output);
            flag=!flag;
        }
        return ans;
    }
};