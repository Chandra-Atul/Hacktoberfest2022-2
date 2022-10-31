#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* BuildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of data: "<<data<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter data for inserting in right of data: "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){

    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();

        q.pop();

        cout<<temp->data<<" ";

        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

void inorder(node* root){
    //LNR
    //base case
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    //NLR
    //base case:
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(node* root){
    //LRN
    //base case
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root = NULL;
    //creating a tree

    root = BuildTree(root);

    //1 3  7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order traversal

    cout<<"\nPrinting level order traversal output: "<<endl;
    levelOrderTraversal(root);

    cout<<"\nPrinting  inorder traversal output: "<<endl;
    inorder(root);

    cout<<"\nPrinting  preorder traversal output: "<<endl;
    preorder(root);

    cout<<"\nPrinting  postorder traversal output: "<<endl;
    postorder(root);

    return 0;
}
