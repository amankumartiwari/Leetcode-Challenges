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
    TreeNode* helper(vector<int>& preorder , int i , int e){
        if(i>e)return NULL;
        if(i==e){
            TreeNode* x = new TreeNode(preorder[i]);
            return x;
        }
        
          TreeNode* root = new TreeNode(preorder[i]);
        
        int par=i+1;
        while(par<=e  && preorder[par]< preorder[i] )par++;
        
        TreeNode *lft = helper(preorder , i+1 , par-1);
        TreeNode* rght = helper(preorder , par, e);
        
        root->left = lft;
        root->right = rght;
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder , 0 , preorder.size()-1);
    }
};