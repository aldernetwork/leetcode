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
    bool getMax(TreeNode* root, long long& vmin, long long& vmax) {
        bool res;
        if (NULL == root)
        {
            vmin = LLONG_MAX;
            vmax = LLONG_MIN;
            return true;
        }

        if (NULL == root->left && NULL == root->right)
        {
            vmin = root->val;
            vmax = root->val;
            return true;
        }


        bool lres, rres;  
        long long lmax, rmax, lmin, rmin, val;
        
        lres = getMax(root->left, lmin, lmax);      
        rres = getMax(root->right, rmin, rmax); 
        val = root->val;   
        vmin = (lmin<val)?lmin:val;
        vmax = (rmax>val)?rmax:val;
        
        res = lres && rres && lmax < val && val < rmin;
        return res;
        
    }
    bool isValidBST(TreeNode* root) {
        long long mmin, mmax;
        return getMax(root, mmin, mmax);
    }
};