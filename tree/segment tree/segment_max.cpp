/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        // write your code here
        return build(A, 0, A.size()-1);
    }
    
private: 
    SegmentTreeNode* build(vector<int> &A, int start, int end){
        if(start> end) return nullptr;
        auto root=new SegmentTreeNode(start, end, A[start]);
        if(start<end){
            root->left=build(A, start, (start+end)/2);
            root->right=build(A, (start+end)/2+1, end);
            root->max= max(root->left->max, root->right->max);
        }
        return root;
    }
};
