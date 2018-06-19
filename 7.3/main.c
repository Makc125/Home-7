/// http://informatics.mccme.ru/mod/statements/view3.php?id=599&chapterid=759
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void addNode(struct node** root, int num)
{
    if (!(*root)){
        *root = (struct node*)malloc(sizeof(struct node));
        (*root)->data = num;
        (*root)->left = (*root)->right = NULL;
        return;
    }
    if (num < (*root)->data){
        addNode(&((*root)->left), num);
    }
    else if (num > (*root)->data){
        addNode(&((*root)->right), num);
    }
}

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int getSecond(struct node* root)
{
    struct node* tree = root;
    struct node* prev = NULL;
    if (!root) return -1;
    while (root->right != NULL) {
        prev = root;
        root = root->right;
    }
    if (tree != root){
        if (root->left != NULL) return root->left->data;
        return prev->data;
    }
    else {
        if (root->left != NULL) {
            root = root->left;
            while (root->right != NULL) {
                root = root->right;
            }
            return root->data;
        }
        return root->data;
    }
}

int main()
{
    struct node* root = NULL;
    int a;
    scanf("%d", &a);
    while (a != 0){
        addNode(&root, a);
        scanf("%d", &a);
    }
    printf("%d", getSecond(root));
}
