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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* x=nullptr;
        TreeNode* y=nullptr;
        TreeNode* pred=nullptr;
        while(!st.empty() || root!=nullptr){
            while(root!=nullptr){
                st.push(root);
                root=root->left;
            }
            root=st.top(); st.pop();
            if(pred!=nullptr && pred->val>root->val){
                y=root;
                if(x==nullptr) x=pred;
                else break;
            }
            pred=root;
            root=root->right;
        }
        std::swap(x->val, y->val);
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *p=root;
        stack<TreeNode*> s;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p=p->left;
            }
            p=s.top(); s.pop();
            res.push_back(p->val);
            p=p->right;
        }
        return res;
    }
    

};

//recursive version 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }
    
private:
    void inorder(vector<int> &res, TreeNode *root){
    if(root==nullptr) return;
    inorder(res, root->left);
    res.push_back(root->val);
    inorder(res, root->right);
}
};
