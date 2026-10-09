// Approach: Stack-based Inorder Traversal
// 1. Push the root and all its left descendants onto the stack.
// 2. Pop the top node to get the next smallest element.
// 3. Process the popped node's right subtree by storing its left descendants.
// 4. Repeat until the stack becomes empty.

class BSTIterator {
public:
    stack<TreeNode*> s;

    void storeLeftNodes(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* ans;
        ans = s.top();
        s.pop();
        storeLeftNodes(ans->right);

        return ans->val;

    }
    
    bool hasNext() {
        return s.size() > 0;
    }
};
