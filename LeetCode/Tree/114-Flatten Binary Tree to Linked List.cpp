/*
1. If root is NULL, return.

2. First flatten the right subtree.

3. Then flatten the left subtree.

4. Set root->left = NULL.

5. Connect root->right to lastnode.

6. Update lastnode = root.

7. Repeat until all nodes are flattened.
*/

class Solution {
public:
    TreeNode* lastnode = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = lastnode;
        lastnode = root;
    }
};
