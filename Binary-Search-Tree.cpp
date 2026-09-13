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
