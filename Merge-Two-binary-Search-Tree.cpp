// Approach:
// 1. Convert both BSTs into sorted arrays using inorder traversal.
// 2. Merge the two sorted arrays using two pointers.
// 3. Build a balanced BST from the merged sorted array.

#include<iostream>
#include<vector>
using namespace std;

// Creates a new BST node with the given value and initializes its children as NULL.
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
// Inserts a value into the BST using the BST property: smaller values go left and larger values go right.
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
// Builds a BST by inserting every value from the given array.
Node* buildBst(vector<int> arr){
    Node* root = NULL;
    for( int val : arr){
        root  = insertNode(root , val);
    }
    return root;
}
// Performs inorder traversal (Left → Root → Right) to store BST values in sorted order.
void inorder(Node* root , vector<int>& temp){
    if(root == NULL){
        return;
    }
    inorder(root->left ,temp);
    temp.push_back(root->data);
    inorder(root->right,temp);
}
// Builds a balanced BST from a sorted array by choosing the middle element as the root.
Node* buildBstFromSorted( vector<int>& arr , int st , int end){
    if(st > end){
        return NULL;
    }
    int mid  = st + (end - st)/2;
    Node* root = new Node(arr[mid]);
    root->left = buildBstFromSorted(arr , st , mid-1);
    root->right = buildBstFromSorted(arr , mid+1 , end);

    return root;
}
// Merges two BSTs by converting them to sorted arrays, merging the arrays, and building a balanced BST.
Node* mergeBST(Node* root1, Node* root2){
    vector<int> arr1 , arr2 ;
    inorder(root1 ,arr1);
    inorder(root2 ,arr2);

    vector<int> ans;
    int i=0 ,j=0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i++]);
        }else{
            ans.push_back(arr2[j++]);
        }
    }
    while(i < arr1.size() ){
        ans.push_back(arr1[i++]);
    }
    while(j < arr2.size() ){
        ans.push_back(arr2[j++]);
    }
    return buildBstFromSorted(ans , 0 ,ans.size()-1);
    
}
int main(){
    vector<int> arr1 = {8,2,1,10};
    vector<int> arr2 = {5,3,0};

    Node* root1 = buildBst(arr1);
    Node* root2 = buildBst(arr2);

    Node* root = mergeBST(root1, root2);

    vector<int> seq;
    inorder(root,seq);
    for(int v : seq){
        cout<<v<<" ";
    }
    cout<<endl;
}
