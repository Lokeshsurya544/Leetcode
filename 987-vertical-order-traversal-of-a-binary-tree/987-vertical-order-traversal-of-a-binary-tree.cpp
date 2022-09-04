
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
    void helper(TreeNode *root,int level,int place,map<int,map<int,vector<int>>>&mp)
    {
        if(root==NULL)
        {
            return;
        }

        mp[place][level].push_back(root->val);
        if(root->left)
        {
            helper(root->left,level+1,place-1,mp          );
            
        }
        if(root->right)
        {
            helper(root->right,level+1,place+1,mp  );
            
        }
        
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      map<int,map<int,vector<int>>>mp;
        vector<vector<int>>ans;
        helper(root,0,0,mp);
        
        for(auto itr:mp)
        {
            vector<int>v;
            for(auto itr1:itr.second)
            {
             sort(itr1.second.begin(),itr1.second.end());
                v.insert(v.end(),itr1.second.begin(),itr1.second.end());
                
            }
            ans.push_back(v);
        }
        
        return ans;

    }
};