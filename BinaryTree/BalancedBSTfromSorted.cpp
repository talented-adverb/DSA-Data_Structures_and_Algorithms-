#include<iostream>
using namespace std;

class node{
    
    public:
    
    int data;
    node* left;
    node *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

class BST{
    public:

    node* BSTfromSorted(int arr[],int start,int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        node *root=new node(arr[mid]);
        root->left=BSTfromSorted(arr,start,mid-1);
        root->right=BSTfromSorted(arr,mid+1,end);
        return root;
    }

    void preorder(node *root){
        if(root==NULL) return;
        cout<<root->data<<"->";
        preorder(root->left);
        preorder(root->right);
    }

};


int main(){
    int arr[]={10,20,30,40,50};
    BST B1;
    node *root=B1.BSTfromSorted(arr,0,4);
    B1.preorder(root);
}