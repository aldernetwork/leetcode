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
    bool helper(TreeNode* root, long long vmin, long long vmax) {
        long long val;
        
        if (NULL == root)
        {
            return true;
        }

        val = root->val;
        
        if (val <= vmin || root->val >= vmax)
            return false;
            
        if (root->left)
        {
            if (!helper(root->left, vmin, val))
                return false;
        }

        if (root->right)
        {
            if (!helper(root->right, val, vmax))
                return false;
        }

        return true;
        
    }
    bool isValidBST(TreeNode* root) {

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};