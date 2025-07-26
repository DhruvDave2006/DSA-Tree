#include<stdio.h>
#include<stdlib.h>

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

    save = root;
    pred = NULL;

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

void RPostOrder(struct TreeNode *root){

    if(root == NULL){
        return;
    }

    RPostOrder(root->lptr);
    RPostOrder(root->rptr);
    printf("%d ", root->info);

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
    printf("Output with Post-Order Traversal : ");
    RPostOrder(root);
    return 0;

}
