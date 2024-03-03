//**************************
//Using preorder and Inorder
//**************************
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    struct node* left;
    char c;
    struct node* right;
}node;

node* create(char data){
    node* temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->c=data;
    temp->right=NULL;
    return temp;
}

int search(char In[],char c,int Instart,int InEnd){
    int i;
    for( i=Instart;i<=InEnd;i++){
        if(In[i]==c) break;
    }
    return i;
}

node* create_Binary_tree(char pre[],char In[],int Instart,int InEnd){
    static int preorder=0;
    if(Instart>InEnd) return NULL;
    node* temp=create(pre[preorder++]);
    //yehi hai asli logic
    if(InEnd==Instart){
        return temp;
    }
    int Inindex=search(In,temp->c,Instart,InEnd);
    temp->left=create_Binary_tree(pre,In,Instart,Inindex-1);
    temp->right=create_Binary_tree(pre,In,Inindex+1,InEnd);
    return temp;
}

void print_pre(node* root){
    if(!root) return;
    printf("%c ",root->c);
    print_pre(root->left);
    print_pre(root->right);
}

void print_post(node* root){
    if(!root) return;
    print_post(root->left);
    print_post(root->right);
    printf("%c ",root->c);
}

int main(){
    char preorder[]={'A','B','D','H','E','C','F','I','G','J','K'};
    char inorder[]={'D','H','B','E','A','I','F','C','J','G','K'};
    int length=sizeof(inorder)/sizeof(inorder[0]);
    node* root=create_Binary_tree(preorder,inorder,0,length-1);
    printf("\npreorder  : ");
    print_pre(root);
    printf("\npostorder : ");
    print_post(root);
    return 0;
}