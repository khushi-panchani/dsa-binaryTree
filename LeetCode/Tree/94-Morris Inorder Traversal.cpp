/* Morris Inorder = Left → Root → Right

1. curr has no left
   → visit curr
   → move right

2. curr has left
   → find inorder predecessor

3. predecessor->right == NULL
   → create thread: predecessor → curr
   → move left

4. predecessor->right == curr
   → thread already exists
   → remove thread
   → visit curr
   → move right

Time  = O(n)
Space = O(1) extra */

class Solution {
public:
   
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){         //  for no left node
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* ip = curr->left;   
                while(ip->right != NULL && ip->right != curr){
                    ip = ip->right;
                }
                if(ip->right == NULL){
                    ip->right = curr;   //create connection between ip and curr node
                    curr = curr->left;
                }else{
                    ip->right = NULL;   //destroy connection if it is and move it to right side
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
