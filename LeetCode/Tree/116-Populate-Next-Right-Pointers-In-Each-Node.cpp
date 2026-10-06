// Approach: BFS / Level Order Traversal using Queue
// 1. Use NULL as a separator to identify the end of each level.
// 2. Use `prev` to keep track of the previous node in the current level.
// 3. Connect the previous node to the current node using `prev->next = curr`.
// 4. Add the current node's children to the queue for the next level.
// 5. Reset `prev` to NULL after each level so different levels are not connected.

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        Node* prev = NULL;

        while(q.size() > 0){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){
                if(q.size() == 0){
                    break;
                }
                q.push(NULL);
            }else{
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                if(prev != NULL){
                    prev->next = curr;
                }
            }
            prev = curr;
        }

        return root;
    }
};
