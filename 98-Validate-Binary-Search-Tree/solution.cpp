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
    bool getMax(TreeNode* root, int& vmin, int& vmax) {
        bool res;
        if (NULL == root)
        {
            vmin = INT_MAX;
            vmax = INT_MIN;
            return true;
        }

        if (NULL == root->left && NULL == root->right)
        {
            vmin = root->val;
            vmax = root->val;
            return true;
        }


        bool lres, rres;  
        long long lmax, rmax, lmin, rmin;
        
        lres = getMax(root->left, lmin, lmax);      
        rres = getMax(root->right, rmin, rmax); 
            
        vmin = min(lmin, root->val);
        vmax = max(rmax, root->val);
        
        res = lres && rres && lmax < root->val && root->val < rmin;
        return res;
        
    }
    bool isValidBST(TreeNode* root) {
        int mmin, mmax;
        return getMax(root, mmin, mmax);
    }
};