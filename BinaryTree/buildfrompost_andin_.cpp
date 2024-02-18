#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class BuildABinaryTree{
    public:

    int search(int inorder[],int start,int end,int curr){
        for(int i=start;i<=end;i++){
            if(inorder[i]==curr) return i;
        }
        return -1;
    }

    node *buildTree(int postorder[],int inorder[],int start,int end){
        static int idx=4;

        if(start>end) return NULL;
        
        int curr=postorder[idx];
        idx--;
        node *nN=new node(curr);
        
        if(start==end) return nN;

        int pos=search(inorder,start,end,curr);
        nN->right=buildTree(postorder,inorder,pos+1,end);
        nN->left=buildTree(postorder,inorder,start,pos-1);

        return nN;
    }

    void inorder(node *root){
        if(root==NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

};

int main(){
    BuildABinaryTree B1;
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    node *root1=B1.buildTree(postorder,inorder,0,4);
    B1.inorder(root1);
}
