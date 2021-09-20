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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> res;
        TreeNode* p(root);
        stack<TreeNode*> s;
        while(p!=nullptr || s.size()){
            if(p!=nullptr){
                res.emplace_back(p->val);
                if(p->right!=nullptr ) s.push(p->right);
                p=p->left;
            }
            else{
                p=s.top(); s.pop();
                res.emplace_back(p->val);
                if(p->right!=nullptr ) s.push(p->right);
                p=p->left;
            }
        }
        return res;
    }
};

//Version 2


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
