#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct link{
    struct link* left;
    int data;
    struct link* right;
}link;
// this function create a binary tree and return the root
link* create_tree(){
        int n,data;
        printf("\ndo you want to create node(0 for no 1 for yes) : ");
        scanf("%d",&n);
        if(n==0){
            return NULL;
        }
        link*root=(link*)malloc(sizeof(link));
        printf("\nenter data : ");
        scanf("%d",&data);
        root->data=data;
        printf("\nleft node having data %d...",data);
        root->left=create_tree();
        printf("\nright node having data %d...",data);
        root->right=create_tree();
        return root;
    }

    //this function check it is full binary tree or not
    bool check_full_binary(link* root){
        bool left_check;
        bool right_check;
        if(!root->left&&!root->right) return true;
        else if(root->left&&root->right){
            left_check=check_full_binary(root->left);
            right_check=check_full_binary(root->right);
        }else{
        return false;
        }
       return left_check&&right_check;
    }
    //this function is used to count nodes

    int count_nodes(link* root){
        int left_count,right_count;
        if(!root) return 0;
        else if(!root->left && !root->right) return 1;
        else{
            left_count=count_nodes(root->left);
            right_count=count_nodes(root->right);
        }
        return 1+left_count+right_count;
    }

    //this function is used to check the given binary tree is complete BT or not 
bool isComplete_BT(link* root,int i,int count){
    if(!root) return true;
    if(i>=count) return false;
    bool left=isComplete_BT(root->left,2*i+1,count);
    bool right=isComplete_BT(root->right,2*i+2,count);

    return left&&right;

}

int main(){
    link* root=create_tree();

    /*if(check_full_binary(root)){
        printf("\nit is full binary tree");
    }else{
        printf("\nNO! it is note full biary tree");
    }*/
    int count=count_nodes(root);
    int index=0;
    if(isComplete_BT(root,index,count)){
        printf("\nthe given tree is complete binary tree");
    }else{
        printf("\nthe given tree is not complete binary tree");
    }
    return 0;
}