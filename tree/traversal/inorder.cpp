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
