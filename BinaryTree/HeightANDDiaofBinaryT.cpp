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

class BinaryT{
    public:

    int Height(node *root){//O(n)

        if(root==NULL) return 0;

        int lHeight=Height(root->left);
        int rHeight=Height(root->right);

        return max(lHeight,rHeight)+1;

    }

    int Diameter(node *root){//O(n^2)
        
        if(root==NULL) return 0;

        int lHeight=Height(root->left);
        int rHeight=Height(root->right);
        int currDia=lHeight+rHeight+1;

        int lDia=Diameter(root->left);
        int rDia=Diameter(root->right);

        return max(currDia,max(lDia,rDia));

    }

    int DiameterOptimized(node *root,int *height){
        if(root==NULL) return 0;

        int lh=0,rh=0;

        int lDia=DiameterOptimized(root->left,&lh);
        int rDia=DiameterOptimized(root->right,&rh);
        *height=max(lh,rh)+1;

        int currDiameter=lh+rh+1;

        return max(currDiameter,max(lDia,rDia));
    }


};

int main(){
    BinaryT B1;

    node *root=new node(10);

    root->left=new node(6);
    root->left->left=new node(4);
    root->right=new node(15);
    root->right->right=new node(16);
    root->right->right->right=new node(17);   

    // cout<<B1.Height(root);
    cout<<B1.Diameter(root);
    int height=0;
    cout<<B1.DiameterOptimized(root,&height);
}