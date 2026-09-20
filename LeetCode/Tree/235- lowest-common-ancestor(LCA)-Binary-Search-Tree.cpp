// Approach: Use BST property to find the Lowest Common Ancestor (LCA)
//
// 1. If both p and q are smaller than root, move to the left subtree.
// 2. If both p and q are greater than root, move to the right subtree.
// 3. Otherwise, p and q are on different sides of root (or root is p/q).
// 4. Therefore, the current root is the Lowest Common Ancestor.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
      
        if(root->val > p->val && root->val > q->val){
          
            return lowestCommonAncestor(root->left , p ,q);
          
        }else if(root->val < p->val && root->val < q->val){
          
            return lowestCommonAncestor(root->right , p ,q);
          
        }else{
          
            return root;
          
        }
    }
};
