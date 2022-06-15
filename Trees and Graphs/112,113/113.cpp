/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        
        // root is null
        if(!root)
            return ans;
        
        dfs(root, targetSum, path, ans);
        return ans;
        
        
    }
    
    void dfs(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& ans)
    {
        sum = sum - node->val;
        path.push_back(node->val);
        
        if(node->left == NULL && node->right == NULL)
        {
            if(sum == 0)
                ans.push_back(path);
            return;
        }
        
        if(node->left != NULL)
        {
            dfs(node->left, sum, path, ans);
            path.pop_back();
        }
        
        if(node->right != NULL)
        {
            dfs(node->right, sum, path, ans);
            path.pop_back();
        }
    }
};
