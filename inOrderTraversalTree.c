#include <stdio.h>
#include <stdlib.h>

struct node {

    int info;
    struct node *lptr;
    struct node *rptr;
};

void RpostOrderT(struct node* root){
   
    if(root == NULL){
        return;
    }

    RpostOrderT(root->lptr);

    printf("%d ", root->info);

    RpostOrderT(root->rptr);

}
int main(){

    struct node *newNode1 = (struct node*)malloc(sizeof(struct node));
    struct node *newNode2 = (struct node*)malloc(sizeof(struct node));
    struct node *newNode3 = (struct node*)malloc(sizeof(struct node));
    struct node *newNode4 = (struct node*)malloc(sizeof(struct node));
    struct node *newNode5 = (struct node*)malloc(sizeof(struct node));

    newNode1->info = 2;
    newNode1->lptr = NULL;
    newNode1->rptr = NULL;

    newNode2->info = 1;
    newNode2->lptr = NULL;
    newNode2->rptr = NULL;

    newNode1->lptr = newNode2;

    newNode3->info = 6;
    newNode3->lptr = NULL;
    newNode3->rptr = NULL;

    newNode2->lptr = newNode3;

    newNode4->info = 7;
    newNode4->lptr = NULL;
    newNode4->rptr = NULL;

    newNode2->rptr = newNode4;

    newNode5->info = 5;
    newNode5->lptr = NULL;
    newNode5->rptr = NULL;

    newNode1->rptr=newNode5;

    printf("In-Order Traversal : \n");
    RpostOrderT(newNode1);
    printf("\n");

    free(newNode1);
    free(newNode2);
    free(newNode3);
    free(newNode4);
    free(newNode5);

    return 0;


}