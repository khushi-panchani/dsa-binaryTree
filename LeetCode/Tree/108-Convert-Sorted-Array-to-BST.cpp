/*
  1. Find the middle element of the sorted array.

2. Create a new tree node using the middle element.

3. Recursively build the left subtree using the left half.

4. Recursively build the right subtree using the right half.

5. If start > end, return NULL.

6. Return the root node of the balanced BST.
  */

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st , int end){
        if(st > end){
            return NULL;
        }
        int mid = st + (end-st)/2;
        TreeNode* root =  new TreeNode(nums[mid]);
        root->left = helper(nums , st , mid-1);
        root->right = helper(nums , mid+1 , end); 
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = helper(nums , 0 , nums.size()-1);
        return root;
    }
};
