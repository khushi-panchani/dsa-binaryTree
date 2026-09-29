// Approach: Inorder Traversal
// 1. Inorder traversal of a BST should produce sorted values.
// 2. Find nodes where the current value is smaller than the previous value.
// 3. Store the first incorrect node in `first` and update `sec` on each violation.
// 4. Swap the values of `first` and `sec` to restore the BST.

class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void inOrder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        inOrder(root->left);
        if(prev != NULL && root->val < prev->val){
            if(!first){
               first = prev;
            }
            sec = root;
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        int temp;
        temp = first->val ;
        first->val = sec->val;
        sec->val = temp;    
    }
};
