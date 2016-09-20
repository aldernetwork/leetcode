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
    vector<vector<int>> levelOrder(TreeNode* root) {
        list<TreeNode*> level;
        vector<vector<int> > res;
        TreeNode* p;
        vector<int> level_res;
        
        level.push_back(root);
        level.push_back(NULL);
        
        while (!level.empty())
        {
            p = level.front();
            level.pop_front();
            if (p)
            {
                level_res.push_back(p->val);
                if (p->left)
                    level.push_back(p->left);
                if (p->right)
                    level.push_back(p->right);
            }
            else
            {
                if (!level_res.empty())
                {
                    res.push_back(level_res);
                    level.push_back(p);
                    level_res.clear();
                }
            }
        }
        return res; 
    }
};