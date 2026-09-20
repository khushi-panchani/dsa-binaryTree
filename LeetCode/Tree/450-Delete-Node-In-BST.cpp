// Approach: Delete a Node from a Binary Search Tree (BST)
//
// 1. Search for the node using the BST property:
//    - If key is smaller, move to the left subtree.
//    - If key is larger, move to the right subtree.
//
// 2. When the node is found, handle 3 cases:
//    - No left child → replace node with its right child.
//    - No right child → replace node with its left child.
//    - Both children exist → find the inorder successor.
//
// 3. The inorder successor is the smallest node in the right subtree.
//
// 4. Copy the successor's value into the current node.
//
// 5. Delete the successor from the right subtree.
//
// 6. Return the updated root.

class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root){
        while(root != NULL && root->left != NULL){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val > key){
            root->left = deleteNode(root->left , key);
        }else if(root->val < key){
             root->right = deleteNode(root->right , key);
        }else{
            
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else{
                TreeNode* is = findSuccessor( root->right);
                root->val = is->val;
                root->right = deleteNode(root->right , is->val);
            }
        }
        return root;
    }
};
