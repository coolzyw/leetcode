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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<struct TreeNode*> tmp;
        vector<struct TreeNode*> container;
        if (!root) return result;
        container.push_back(root);
        while(!container.empty())
        {
            vector<int> level;
            tmp.clear();
            for(int i=0; i<container.size(); i++)
            {
                level.push_back(container[i]->val);
                if(container[i]->left)
                {
                    tmp.push_back(container[i]->left);
                }
                if(container[i]->right)
                {
                    tmp.push_back(container[i]->right);
                }
            }
            result.push_back(level);
            container = tmp;
        }
        std:: reverse(result.begin(), result.end());
        return result;
    }
};