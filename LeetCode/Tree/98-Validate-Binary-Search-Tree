// Step 1: Create a helper function with min and max boundaries.
// Step 2: If root is NULL, return true (valid BST).
// Step 3: Check if root->val violates the min or max boundary.
// Step 4: If violation occurs, return false.
// Step 5: Recursively check the left subtree with updated max.
// Step 6: Recursively check the right subtree with updated min.
// Step 7: Return true only if both subtrees are valid.
// Step 8: Start validation using NULL boundaries.

 bool helper(TreeNode* root , TreeNode* min , TreeNode* max){
        if( root == NULL){
            return true;
        }
        if(min != NULL && root->val <= min->val){   //if conditin is True return False
            return false;
        }
         if(max != NULL && root->val >= max->val){   //if conditin is True return False
            return false;
        }
        return helper(root->left ,min , root) && helper(root->right , root , max);

    }

    bool isValidBST(TreeNode* root) {
      return   helper(root,NULL,NULL);
    }
