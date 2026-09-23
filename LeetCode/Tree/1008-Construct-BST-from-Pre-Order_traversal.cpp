// Approach: Construct BST from Preorder using a boundary
// 1. Use preorder order (Root → Left → Right) to create nodes.
// 2. Use `i` to track the current element in the preorder array.
// 3. Use `bound` to define the maximum value allowed in the current subtree.
// 4. Create the left subtree with `root->val` as the new bound.
// 5. Create the right subtree using the previous bound.
// 6. Return NULL when the current value exceeds the allowed bound.

class Solution {
public:
    TreeNode* helper(vector<int>& preorder , int& i , int bound){
        if(i >= preorder.size() || preorder[i] > bound){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder , i , root->val);
        root->right = helper(preorder , i , bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        TreeNode* root = helper(preorder , i , INT_MAX);
        return root;
    }
};
