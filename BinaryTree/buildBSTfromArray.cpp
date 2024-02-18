#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class buildBST{
    public:

    node* insertIntoBSTfromArr(node* root,int val){
        if(root==NULL) return new node(val);
        if(val<root->data) root->left=insertIntoBSTfromArr(root->left,val);
        else root->right=insertIntoBSTfromArr(root->right,val);
        return root;
    }

    void preorder(node *root){
        if(root==NULL) return;
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
};


int main(){
    buildBST B1;
    int arr[]={15, 18, 6, 7, 17, 3, 4, 13, 9, 20, 2};
    node *root=NULL;
    int i=0;
    while(i<11){
        root=B1.insertIntoBSTfromArr(root,arr[i]);
        i++;
    }
    B1.preorder(root);
}