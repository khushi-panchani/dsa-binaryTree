/*
1. Build BST by inserting each array element.
2. Insert smaller values to the left and larger values to the right.
3. Inorder traversal prints BST values in sorted order.
4. Search compares the key with the current node and moves left or right.
5. Delete a leaf node by removing it and returning NULL.
6. Delete a node with one child by returning its child.
7. Delete a node with two children using the inorder successor.
8. Always return root after insertion and deletion.
*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
Node* insertNode(Node* root ,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(root->data > val){
      root->left =  insertNode( root->left , val); 
    }else{
        root->right =  insertNode( root->right , val);
    }
    return root;

}
bool search(Node* root , int key){
    if(root == NULL){ return false; }
    if(root->data == key ){
        return true;
    }
    else if(root->data > key){
        return search(root->left , key);
    }else{
        return search(root->right , key);
    }
}
Node* buildBst(vector<int> arr){
    Node* root = NULL;
    for( int val : arr){
        root  = insertNode(root , val);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* findSuccessor(Node* root){
    while(root != NULL && root->left != NULL ){
        root = root->left ; 
    }
    return root;
}
Node* delNode(Node* root , int key){ // key => val to delete
    if(root == NULL){
        return NULL;
    }
    if(root->data > key ){
        root->left = delNode(root->left , key); 
    }else if(root->data < key ){
        root->right = delNode(root->right , key); 
    }else{
        // key == root
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
            Node* is = findSuccessor(root->right);
            root->data = is->data;
            root->right = delNode(root->right , is->data);
        }
    }
    return root;
}
int main(){
    vector<int> arr ={3,6,7,2,4,1,5};
    Node* root = buildBst(arr);
    inorder(root);
    cout<<search(3)<<endl;
    
    root = delNode(root , 1);
    cout<<"after"<<endl;
    inorder(root);

return 0;
}
