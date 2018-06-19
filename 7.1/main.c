/// http://informatics.mccme.ru/mod/statements/view.php?id=599
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

int getHeight(struct node* root)
{
    if (root == NULL){
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
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
    printf("%d", getHeight(root));
}
