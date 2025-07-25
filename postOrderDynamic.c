#include <stdio.h>
#include <stdlib.h>

struct node {

    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *insertTree(struct node *root){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter a value :");
    int x;
    scanf("%d", &x);
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if(root == NULL){
        return newNode;
    }

    struct node *save = (struct node *)malloc(sizeof(struct node));
    struct node *pred = (struct node *)malloc(sizeof(struct node));

    save = root; pred = root;

    while(save != NULL){
    printf("Enter 1 for insert at left / Enter 2 for insert at right :\n");
    int dir;
    scanf("%d", &dir);
    pred = save;


        if(dir == 1){
            save = save -> lptr;
        }

        else{

            save = save -> rptr;
        }
    }

    printf("Enter 1 to insert at Left / Enter 2 to insert at right : \n");
    int dir;
    scanf("%d", &dir);

    if(dir == 1){
        pred->lptr = newNode;
    }
    else{
        pred->rptr = newNode;
    }

    return root;

}

void RpreOrder(struct node *root){

    if(root == NULL){

        return;
    }

    RpreOrder(root->lptr);
    RpreOrder(root->rptr);
    printf("%d ", root->info);
}

int main(){

    struct node *root = (struct node *)malloc(sizeof(struct node ));
    root = NULL;
while(1){
    printf("Enter 1 to Insert Value / Enter 0 for exit : \n");
    int b;
    scanf("%d", &b);

    if(b == 1){

        root = insertTree(root);
    }
    else{
        break;
    }
}
RpreOrder(root);
    return 0;

}