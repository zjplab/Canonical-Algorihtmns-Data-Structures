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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
private:
    void postorder(TreeNode *root, vector<int> &res){
        if(!root) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};


//Non-recursive version 
// Use a stack to emulate the function call stack 
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        TreeNode *head=root;
        stack<TreeNode *> s{{root}};
        while(!s.empty()){
            TreeNode *t=s.top();
            if( (!t->left and !t->right)||t->left==head || t->right==head){
                res.push_back(t->val);
                s.pop();
                head=t;
            }
            else
            {
                if(t->right) s.push(t->right);
                if(t->left)  s.push(t->left);
            }
        }
        return res;
    }
    

};

//reverse
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            auto cur = stk.top();
            result.push_back(cur->val);
            stk.pop();
            if(cur->left) stk.push(cur->left);
            if(cur->right) stk.push(cur->right);
        }
        reverse(result.begin(), result.end());
        return result;
   
//STL List
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        list<int> l;
        if (!root) return v;
        
        stack<TreeNode *> s;
        s.push(root);
        
        TreeNode *p = NULL;
        while(!s.empty()) {
            p = s.top();
            s.pop();
            // inserting to the front of a list is fast
            l.push_front(p->val);
            //v.insert(v.begin(), p->val);
            if (p->left) s.push(p->left);
            if (p->right) s.push(p->right);
        }
        // convert list to vector (copy)
        v = vector<int>(std::begin(l), std::end(l));
        return v;
    }
};    
   

