#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node*left;
    Node*right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void levelOrder(Node* root){
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front==NULL){
            //in this case print the number and also the new line
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

Node* insert(Node* root, int val){
    if(root==NULL){
        Node* n= new Node(val);
        return n;
    }

    //but if normal case then check which part to insert
    if(val<root->data){
        Node* leftsubtree=insert(root->left,val);
        root->left=leftsubtree;
    }
    else{
        Node* rightsubtree=insert(root->right,val);
        root->right=rightsubtree;
    }   
    return root;
}

void helper(Node* root){
    int data;
    cout<<"Enter the data to be inserted in the BST"<<endl;
    cin>>data;

    while(data!=-1){
        root=insert(root,data);
        cout<<"Enter the data to be inserted in the BST"<<endl;
        cin>>data;
    }
}


//now over here we will create a function to insert a node in the BST

int main(){
    Node* root=NULL;

    //creatng the first node of this tree
    helper(root);
}