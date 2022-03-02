//https://www.interviewbit.com/old/problems/path-to-given-node/
 bool f(TreeNode *node,int k,vector<int> &ans)
 {
     if(node==NULL) return false;
     ans.push_back(node->val);
     if(node->val==k) return true;
     if(f(node->left,k,ans)||f(node->right,k,ans)) return true;
     ans.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL) return ans;
    f(A,B,ans);
    return ans;
}