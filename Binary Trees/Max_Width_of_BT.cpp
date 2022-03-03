//https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/
//https://www.youtube.com/watch?v=ZbybYvcVLks&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=29

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
    queue<pair<TreeNode *,int>> q;
    q.push({root,1});
    int ans=0;
    while(!q.empty())
    {
        int size=q.size();
        //if(ans<size) ans=size;
        int mini = q.front().second;
        int first,last;
        for(int i=0;i<size;i++)
        {
            int cur_id = q.front().second-mini+1;
            TreeNode *node = q.front().first;
            q.pop();
            if(i==0) first = cur_id;
            if(i==size-1) last=cur_id;
            if(node->left) q.push({node->left,2LL*cur_id});
            if(node->right) q.push({node->right,2LL*cur_id+1});
        }
        ans=max(ans,last-first+1);
    }
    return ans;
    }
};