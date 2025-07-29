#include <stdio.h>
#include <stdlib.h>

//AVL Tree Implement with In Order Traversal

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

    save = root , pred = NULL;

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

void RinOrder(struct TreeNode *root){

    if(root == NULL){
        return;
    }

    RinOrder(root->lptr);
    printf("%d ", root->info);
    RinOrder(root->rptr);
}

void storeToArray(struct TreeNode *root, int arr[], int *idx){

    if(root == NULL){
        return;
    }

    storeToArray(root->lptr, arr, idx);
    arr[*idx] = root->info;
    (*idx)++;
    storeToArray(root->rptr,arr, idx);
}

struct TreeNode *AVLimplement(int arr[], int l, int h){

        if( l > h ){

            return NULL;
        }

        int mid = (l + h) / 2;
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

        newNode->info = arr[mid];
        newNode->lptr = NULL;
        newNode->rptr = NULL;

        newNode->lptr = AVLimplement(arr, l , mid - 1);
        newNode->rptr = AVLimplement(arr, mid + 1, h);

        return newNode;

}

int main(){

    struct TreeNode *root_old = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root_old = NULL;

    while(1){
        printf("Enter 1 for insert value / Enter 0 for Exit : ");
        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            root_old = insertTree(root_old);
        }
        else if(choice == 0){
            break;
        }
    }
    printf("Output with In-Order Traversal : ");
    RinOrder(root_old);
    printf("\n");

    int sortedArray[1000];
    int idx = 0;
    storeToArray(root_old, sortedArray, &idx);

    struct TreeNode *root_new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root_new = NULL;

    if(idx > 0){
        root_new = AVLimplement(sortedArray, 0 , idx - 1);
        printf("Balanced BST By In Order Traversal : ");
        RinOrder(root_new);
        printf("\n");
    }

    return 0;
}