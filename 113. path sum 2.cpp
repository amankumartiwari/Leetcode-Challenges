/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void helper(TreeNode* root , int sum, vector<vector<int>>&ans,vector<int>&v){
        
        if( root->left==NULL && root->right==NULL && root->val==sum){
            ans.push_back(v);
            return ;
        }
        if( root->left==NULL && root->right==NULL && root->val!=sum){
            return ;
        }
 
        if(root->left){
              v.push_back(root->left->val);
            helper(root->left , sum -root->val , ans,v);
            v.pop_back();
        }
        if(root->right){
 v.push_back(root->right->val);
           helper(root->right , sum-root->val,ans,v);
v.pop_back();
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        vector<int> v;
        v.push_back(root->val);
        helper(root , sum,ans , v);
        return ans;
    }
};