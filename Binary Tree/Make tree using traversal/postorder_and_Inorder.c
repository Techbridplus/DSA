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
node* create_Binary_tree(char post[],char In[],int Instart,int InEnd,int* postIndex){
    if(Instart>InEnd) return NULL;
    node* temp=create(post[(*postIndex)--]);
    if(Instart==InEnd) return temp;
    int InIndex=search(In,temp->c,Instart,InEnd);

    // humne yaha par pehle right ko banaya kyuki postorder mai last se dekhe to pehle node fir node->right and last mai node->left milta hai
    temp->right=create_Binary_tree(post,In,InIndex+1,InEnd,postIndex);
    temp->left=create_Binary_tree(post,In,Instart,InIndex-1,postIndex);
    return temp;
    
}

void print_post(node* root){
    if(!root) return;
    print_post(root->left);
    print_post(root->right);
    printf("%c ",root->c);
}

int main(){
    char postorder[]={'H','D','E','B','I','F','J','K','G','C','A'};
    char inorder[]={'D','H','B','E','A','I','F','C','J','G','K'};
    int length=sizeof(inorder)/sizeof(inorder[0]);
    int postIndex=length-1;
    node* root=create_Binary_tree(postorder,inorder,0,length-1,&postIndex);
    printf("\npostorder : ");
    print_post(root);
    return 0;
}