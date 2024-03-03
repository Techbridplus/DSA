#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
typedef struct link{
    struct link* left;
    int data;
    struct link* right;
}link;

    static int scount=0;
link* create_tree(){
    int count=scount;
    int n,data;
    printf("\ndo you want to create node(0 for no and 1 for yes) : ");
    scanf("%d",&n);
    if(!n) return NULL;
    link* root=(link*)malloc(sizeof(link));
    printf("\nenter data : ");
    scanf("%d",&data);
    root->data=data;
    printf("\nleft child of %d node",data);
    scount++;
    root->left=create_tree();
    printf("\nright child of %dnode",data);
    root->right=create_tree();
    return root;
}
// preorder traverse
/*matlab pehle root ka data print hoga fir left child ka data and last mai right child*/
void preorder_traverse(link*root){
    if(!root) return;
    printf("%d ",root->data);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

//inorder traverse
/*isme pehle left child ka data print hoga fir root ka and last mai right child*/
void inorder_traverse(link*root){
    if(!root) return;
    inorder_traverse(root->left);
    printf("%d ",root->data);
    inorder_traverse(root->right);
}

//postorder traverse
/*isme pehle left child ka data print hoga fir root ka and last mai right child*/
void postorder_traverse(link*root){
    if(!root) return;
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%d ",root->data);
}
bool isSameTree(link* p, link* q) {
    bool left_check;
    bool right_check;
    if(!p&&!q) return true;
    else if(p&&q){
        if((p->data)!=(q->data)) return false;
        left_check=isSameTree(p->left,q->left);
        right_check=isSameTree(p->right,q->right);
    }
    else return false;
    if(!left_check||!right_check) return false;
    return true;  
}

bool isSubtree(link* root, link* subRoot) {
    bool check_left;
    bool check_right;
    if(!root&&!subRoot) return true;
    else if(root&&subRoot){
        if(root->data==subRoot->data&&isSameTree(root,subRoot)==true){
            return true;
            }
            else{
            check_left=isSubtree(root->left,subRoot);
            check_right=isSubtree(root->right,subRoot);   
        }
        }
        else return false;
    if(!check_left&&!check_right) return false;
    return true;
}
    
	
	
	
int main(){
    link* root=create_tree();
    //scount=0;
   /* link* subroot=create_tree();
    if(isSubtree(root,subroot)){
        printf("\ntrue");
    }else{
        printf("\nfalse");
    }
    */
   printf("\nInorder : ");
   inorder_traverse(root);
   printf("\npreorder : ");
   preorder_traverse(root);
   printf("\npostorder : ");
   postorder_traverse(root);
    return 0;
}