/*
    LeetCode #105
    Construct Binary Tree from Preorder and Inorder Traversal

    Approach:
    1. First element of preorder is the root.
    2. Find the root in inorder.
    3. Elements before the root belong to the left subtree.
    4. Elements after the root belong to the right subtree.
    5. Recursively build left and right subtrees.

    Time Complexity: O(n^2)
    Space Complexity: O(n)
*/
class Solution {
public:
    int search(vector<int>& inorder , int left , int right , int val){
        for(int i=left ; i<=right ; i++){
            if(inorder[i] == val ){
                return i;
            }
        } 
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preIdx , int left , int right){
        if(left > right){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder , left , right , preorder[preIdx]);
        preIdx++;

        root->left = helper(preorder, inorder , preIdx , left , inIdx-1);
        root->right = helper(preorder, inorder , preIdx , inIdx+1 , right);

        return root;

    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx  = 0;
        return helper(preorder ,  inorder , preIdx ,0 , inorder.size()-1);
        
    }
};
