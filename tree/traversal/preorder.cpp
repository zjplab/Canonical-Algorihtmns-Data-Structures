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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
private: 
    void preorder(TreeNode *root, vector<int> &res){
        if(!root) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};


//Non-recursive version 
// Use a stack to emulate recursion
 /* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        TreeNode *p=root;
        stack<TreeNode *> s;
        while(p || !s.empty())
        {
           if(p){
               s.push(p);
               res.push_back(p->val);
               p=p->left;
           } 
            
            else {
                p=s.top(); s.pop();
                p=p->right;
            }
        }
        return res;
    }
    

};
