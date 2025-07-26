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
    int val;
    scanf("%d", &val);

    newNode->info = val;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if(root == NULL){
        return newNode;
    }

    struct TreeNode *save;
    struct TreeNode *pred;

    save = root, pred = NULL;

    while(save != NULL){
        pred = save;
        if(val < save->info){
            save = save->lptr;
        }
        else if(val > save->info){
            save = save->rptr;
        }
        else{

            free(newNode);
            return root;
        }
    }

    if(val < pred->info){
        pred->lptr = newNode;
    }
    else if(val > pred->info){
        pred->rptr = newNode;
    }

    return root;
}

void RpreOrder(struct TreeNode *root){

    if(root == NULL){
        return;
    }

    printf("%d ", root->info);
    RpreOrder(root->lptr);
    RpreOrder(root->rptr);
}
int main(){

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root = NULL;

    while(1){
        printf("Enter 1 for Insert / Enter 0 for Exit : ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            root = insertTree(root);
        }
        else if(choice == 0){
            break;
        }
    }
    printf("Output with Pre-Order Traversal : ");
    RpreOrder(root);
    return 0;

}