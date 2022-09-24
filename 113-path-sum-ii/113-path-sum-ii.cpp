/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void solve(TreeNode *root, int target, vector<int> res, vector<vector< int>> &ans)
        {
            if (!root) return;
            if (target == root->val && root->left == NULL && root->right == NULL)
            {
                res.push_back(root->val);
                ans.push_back(res);

                return;
            }
            res.push_back(root->val);
            solve(root->left, target - root->val, res, ans);

            solve(root->right, target - root->val, res, ans);
        }
    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> res;
        vector<vector < int>> ans;
        solve(root, targetSum, res, ans);
        return ans;
    }
};