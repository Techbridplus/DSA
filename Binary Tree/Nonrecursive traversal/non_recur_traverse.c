#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    struct node* left;
    int data;
    struct node* right;
}node;
int top=-1;
node* stack[100];
void push(node* data){
    stack[++top]=data;
}
node* pop(){
    return stack[top--];
}
bool isEmpty(){
    return top==-1;
}
node* create_tree(){
    int n,data;
    printf("\ndo you want to create node(0 for no and 1 for yes) : ");
    scanf("%d",&n);
    if(!n) return NULL;
    node* root=(node*)malloc(sizeof(node));
    printf("\nenter data : ");
    scanf("%d",&data);
    root->data=data;
    printf("\nleft child of %d",root->data);
    root->left=create_tree();
    printf("\nright child of %d",root->data);
    root->right=create_tree();
    return root;
}

//this function is used to traverse using non recursive approach
void preorder_nonrecursive(node* root){
        push(root);
        while(top!=-1){
            node* ptr=pop();
            printf("%d ",ptr->data);
            if(ptr->right){
                push(ptr->right);
            }
            if(ptr->left){
                push(ptr->left);
            }
        }
}

void inorder_nonrecursive(node* root){
    node* ptr=root;
    while(1){
    while(ptr->left){
        push(ptr);
        ptr=ptr->left;
    }
    while(!ptr->right){
        printf("%d ",ptr->data);
        if(isEmpty()){
            return;
        }
        ptr=pop();
    }
    printf("%d ",ptr->data);
    ptr=ptr->right;
}
}
int main(){
    node* root=create_tree();
    printf("\npreorder : ");
    preorder_nonrecursive(root);
    printf("\nInorder : ");
    inorder_nonrecursive(root);
    return 0;
}