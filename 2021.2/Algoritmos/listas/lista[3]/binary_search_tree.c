#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    int key;
    int element;
    struct BSTNode *l;
    struct BSTNode *r;
};

typedef struct BSTNode BSTNode;

typedef struct {
    BSTNode *root;
    int cont;
}BST;

BST* create_bst() {
    BST *bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;
    bst->cont = 0;
    return bst;
}

BSTNode* create_bstnode(int key) {
    BSTNode *n = (BSTNode*)malloc(sizeof(BSTNode));
    n->key = key;
    n->r = NULL; // talvez de segfault
    n->l = NULL;
    return n;
}

BSTNode* inserthelp(BSTNode *rt, int key) {
    if(rt == NULL) return create_bstnode(key);
    if(rt->key > key) rt->l = inserthelp(rt->l, key);
    else rt->r = inserthelp(rt->r, key);
    return rt;
}

void insert(BST *bst, int key) {
    bst->root = inserthelp(bst->root, key);
    bst->cont++;
}

void posorder(BSTNode *rt) {
    if(rt!=NULL) {
        posorder(rt->l);
        posorder(rt->r);
        printf("%d\n", rt->key);
    }
}

int main() {
    int key;
    BST *bst = NULL;
    bst = create_bst();
    while(scanf("%d", &key) != EOF) insert(bst, key);
    posorder(bst->root);
    free(bst); // sim ta errado como soube
    return 0;
}