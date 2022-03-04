//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/
//https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=31


class Solution {
    void mapParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &pmap)
{
    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(node->left)
        {
            pmap[node->left] = node;
            q.push(node->left);
        }
        if(node->right)
        {
            pmap[node->right] = node;
            q.push(node->right);
        }
    }
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
    if(root==NULL) return ans;
    unordered_map<TreeNode* ,TreeNode* > pmap;
    mapParents(root,pmap);
    unordered_map<TreeNode *,bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int cur_lvl = 0;
    while(!q.empty())
    {
        int size = q.size();
        if(cur_lvl++ == k) break;
        for(int i=0;i<size;i++)
        {
            TreeNode * node = q.front();
            q.pop();
            if(node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right]=true;
            }
            if(pmap[node] && !visited[pmap[node]])
            {
                q.push(pmap[node]);
                visited[pmap[node]]=true;
            }
        }
    }
    while(!q.empty())
    {
        TreeNode * node = q.front();
        q.pop();
        ans.push_back(node->val);
    }
    return ans;
    }
};