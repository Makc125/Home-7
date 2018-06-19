/// https://informatics.msk.ru/mod/statements/view.php?id=206
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

struct list {
    char data[100];
    struct list* next;
};

void addList(struct list** root, char s[100])
{
    if (!(*root)){
        *root = (struct list*)malloc(sizeof(struct list));
        int i = 0;
        for (char* c = &s; *c != '\0'; c++) {
            (*root)->data[i++] = *c;
        }
        (*root)->next = NULL;
        return;
    }
    struct list* q = (struct list*)malloc(sizeof(struct list));
    int i = 0;
    for (char* c = &s; *c != '\0'; c++) {
        q->data[i++] = *c;
    }
    q->next = NULL;
    struct list* p = (*root);
    while (p->next != NULL){
        p = p->next;
    }
    p->next = q;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    struct list* s9 = NULL;
    struct list* s10 = NULL;
    struct list* s11 = NULL;
    int a; char s[100];
    while (fscanf(fin, "%d%s", &a, s) != EOF) {
        if (a == 9) {
            addList(&s9, s);
        }
        else if (a == 10) {
            addList(&s10, s);
        }
        else {
            addList(&s11, s);
        }
    }
    struct list* p = s9;
    while (p != NULL){
        fprintf(fout, "%d %s\n", 9, p->data);
        p = p->next;
    }
    p = s10;
    while (p != NULL){
        fprintf(fout, "%d %s\n", 10, p->data);
        p = p->next;
    }
    p = s11;
    while (p != NULL){
        fprintf(fout, "%d %s\n", 11, p->data);
        p = p->next;
    }
}
