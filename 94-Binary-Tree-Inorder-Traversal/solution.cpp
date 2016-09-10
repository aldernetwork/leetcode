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

    
    vector<int> inorderTraversal(TreeNode* root) {
        list<TreeNode *> stack;
        vector<int> res;
        stack.push_back(root);
        while (!stack.empty())
        {
            TreeNode *p = stack.back();
            stack.pop_back();
            if (p->left == NULL && p->right == NULL)
            {
                res.push_back(p->val);
            }
            else 
            {
                TreeNode *left = p->left, *right = p->right; 
                if (right)
                {
                    stack.push_back(right);
                }
                
                p->left = p->right = NULL;
                stack.push_back(p);
                if (left)
                {
                    stack.push_back(left);
                }
            }
        }
        return res;
    }
};