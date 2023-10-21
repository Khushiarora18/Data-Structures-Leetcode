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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root) return ans;

        allNodes(root,ans,to_string(root->val));
        return ans;
    }
    void  allNodes(TreeNode* root,vector<string>&ans,string t){
        if(root->left==NULL && root->right==NULL){             //if we got leaf node
            ans.push_back(t);

        }
        if(root->left!=NULL)
            allNodes(root->left, ans, t + "->" + to_string(root->left->val));
        if(root->right!=NULL)
            allNodes(root->right, ans, t + "->" + to_string(root->right->val));
    }
};