// Approach: Inorder Traversal of BST
//
// 1. Inorder traversal of a BST gives values in sorted order.
// 2. Use prevOrder to count the visited nodes.
// 3. First traverse the left subtree.
// 4. Check if the current node is the kth visited node.
// 5. If not, increase the counter and traverse the right subtree.
// 6. Return the node value when kth smallest element is found.

class Solution {
public:

    int prevOrder = 0;

    int kthSmallest(TreeNode* root, int k) {

        if(root == NULL){
            return -1;
        }

        if(root->left != NULL){
            int leftAns = kthSmallest(root->left, k);

            if(leftAns != -1){
                return leftAns;
            }
        }

        if(prevOrder + 1 == k){
            return root->val;
        }

        prevOrder += 1;

        if(root->right != NULL){
            int rightAns = kthSmallest(root->right, k);

            if(rightAns != -1){
                return rightAns;
            }
        }

        return -1;
    }
};
