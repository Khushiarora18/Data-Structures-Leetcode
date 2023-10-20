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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return{};
         vector<TreeNode*> list;
         if(n==1) list.push_back(new TreeNode(0));
         else{
             for(int i=1; i<=n-1; i+=2){
                  vector<TreeNode*> leftTree = allPossibleFBT(i);
                   vector<TreeNode*>rightTree= allPossibleFBT(n-i-1);
                   for(TreeNode* lt : leftTree){
                       for(TreeNode*rt: rightTree){
                           list.push_back(new TreeNode(0,lt,rt));
                       }
                   }
             }
         }
         return list;
        
        
    }
};