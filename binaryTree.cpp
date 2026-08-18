#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;

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
static int idx = -1;
Node* binaryTree(vector<int>& array){
    idx++;
    if(array[idx] == -1){ return NULL; }

    Node* root = new Node(array[idx]);
    root->left = binaryTree(array);
    root->right = binaryTree(array);

    return root;
} 

void preTree(Node* root){                   //PRE ORDER TREE
    if(root == NULL){ return; }
    cout<<root->data<<" ";
    preTree(root->left);
    preTree(root->right);
}


void inTree(Node* root){                   //IN ORDER TREE
    if(root == NULL){ return; }
    inTree(root->left);
    cout<<root->data<<" ";
    inTree(root->right);
}
void postTree(Node* root){                   //IN ORDER TREE
    if(root == NULL){ return; }
    postTree(root->left);
    postTree(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){                //in  level orderwith NEW LEVEL IN NEXT LINE
    queue<Node*> q;
    q.push(root);
    // int count=0;

    while(q.size() > 0){
      int levelSize = q.size();  // FOR EACH LEVEL SIZE IN QUEUE
   

        for(int i=0;i<levelSize;i++){

            Node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";                                     
                                                                        //1
            if(curr->left != NULL){                                     //2 3
            q.push(curr->left);                                         //4 5 
            }
            if(curr->right != NULL){
            q.push(curr->right);
            }
        } 
        // count++;
        cout<<endl;   // THEN NEXT LINE
    }
    // cout<<"count : "<<count;
}

int cntHeight(Node* root){
    if(root == NULL) return 0;

    int leftheight = cntHeight(root->left);
    int rightheight = cntHeight(root->right);

    return max(leftheight,rightheight)+1;

}
int cntNode(Node* root){
    if(root == NULL) return 0;

    int leftNode = cntNode(root->left);
    int rightNode = cntNode(root->right);

    return leftNode + rightNode + 1;

}
int sumNode(Node* root){
    if(root == NULL) return 0;

    int leftNode = sumNode(root->left);
    int rightNode = sumNode(root->right);

    return leftNode + rightNode + root->data;

}
void topView(Node* root){
    if(root == NULL){return;}
    queue<pair<Node*,int>> q; //node,hds
    map<int,int> m;  //hds ,node
    q.push({root,0});

    while(q.size() > 0){
        Node* curr = q.front().first;
        int hds = q.front().second;

        q.pop();

        if(m.find(hds) == m.end()){    ///
           m[hds] = curr->data;             // only this for bottom view
        }                               ///

        if(curr->left != NULL){
            q.push({curr->left,hds-1});
        }
        if(curr->right != NULL){
            q.push({curr->right,hds+1});
        }
    }
    for( auto it : m){
        cout<<it.second<<" ";
    }
}
void kthLevel(Node* root,int k){
    if(root == NULL){ return; }

    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    kthLevel(root->left,k-1);
    kthLevel(root->right,k-1);
}


int main(){
    vector<int> preorder = {1 ,2 ,-1,-1 , 3 , 4,-1,-1,5,-1,-1};
    Node* root = binaryTree(preorder);

    // cout<<"pre order : ";
    // preTree(root);
    // cout<<endl;
    // cout<< "in order : ";
    // inTree(root);
    // cout<<endl;
    // cout<< "post order : ";
    // postTree(root);
    //  cout<<endl;
    // cout<< "levelOrder order : "<<endl;
    // levelOrder(root);
    // cout<<"height is : "<<cntHeight(root)<<endl;
    // cout<<"node is : "<<cntNode(root)<<endl;
    // cout<<"sum is : "<<sumNode(root)<<endl;
    // topView(root);
    kthLevel(root,2);


    return 0;
}