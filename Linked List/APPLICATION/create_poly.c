#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int coeff;
    int expo;
    struct node*next;
}*head=NULL,*tail=NULL;
//...//...
// This function id used to insert data in shorted form
void insert(){
    int coeff;
    int expo;
    static int i=2;
    printf("\nenter coefficient of term %d : ",i);
    scanf("%d",&coeff);
    printf("\nenter exponent for term %d : ",i);
    scanf("%d",&expo);
    struct node*temp=NULL;
    struct node*newp=malloc(sizeof(struct node));
    newp->coeff=coeff;
    newp->expo=expo;
    newp->next=NULL;

    int key=expo;
    if(head==NULL||key>head->expo){
        newp->next=head;
        head=newp;
    }else{
        temp=head;
        while(temp->next!=NULL&&temp->next->expo>key)
            temp=temp->next;
            newp->next=temp->next;
            temp->next=newp;   
    }

}
//...
void creat_poly()
{   int n;
    printf("\nenter number of terms : ");
    scanf("%d",&n);
    if(n==0){
        printf("\nPolynomial is : 0");
        return;
    }
    int coeff;
    int expo;
 head=malloc(sizeof(struct node));
 printf("\nenter coefficient of 1 term : ");
 scanf("%d",&coeff);
 printf("\nenter exponent : ");
 scanf("%d",&expo);
 head->coeff=coeff;
 head->expo=expo;
 head->next=NULL;
 for(int i=2;i<=n;i++){
    insert();
 }

    printf("\n\n\tPOLYNOMIAL IS CREATED ...\n\n");
}


void print(){
    struct node* ptr=head;
    printf("\n");
    while(ptr){
        printf("%d",ptr->coeff);
        if(ptr->expo!=0){
            printf("x^%d",ptr->expo);
        }else{
            printf("%d",ptr->expo);
        }
        if(ptr->next!=NULL){
            printf(" + ");
        }
        ptr=ptr->next;
    }
}
int main(){
    char ch;
    printf("\nLETS MAKE POLYNOMIAL...");
    printf("\n\tpress M : ");
    scanf("%c",&ch);
    if(ch=='M'){
    creat_poly();
    }else{
        printf("\nINVALID INPUT");
        return 1;
    }
    print();
    return 0;
}