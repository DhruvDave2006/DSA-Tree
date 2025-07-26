#include <stdio.h>
#include <stdlib.h>

struct TreeNode {

    int info;
    struct TreeNode *lptr;
    struct TreeNode *rptr;
};

struct TreeNode *insertTree(struct TreeNode *root){

    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    printf("Enter a value : ");
    int x;
    scanf("%d", &x);

    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if(root == NULL){
        return newNode;
    }

    struct TreeNode *save;
    struct TreeNode *pred;

    save = root , pred = NULL;

    while(save != NULL){
        pred = save;
        if(x < save->info){
            save = save->lptr;
        }
        else if(x > save->info){
            save = save->rptr;
        }
        else{
            free(newNode);
            return root;
        }
    }

    if(x < pred->info){
        pred->lptr = newNode;
    }
    else if(x > pred->info){
        pred->rptr = newNode;
    }

    return root;
    
}

void RinOrder(struct TreeNode *root){

    if(root == NULL){
        return;
    }

    RinOrder(root->lptr);
    printf("%d ", root->info);
    RinOrder(root->rptr);
}
int main(){

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root = NULL;

    while(1){
        printf("Enter 1 for insert value / Enter 0 for Exit : ");
        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            root = insertTree(root);
        }
        else if(choice == 0){
            break;
        }
    }
    printf("Output with In-Order Traversal : ");
    RinOrder(root);
    return 0;
}