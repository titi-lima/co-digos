#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    long long int key;
    int h;
    struct BSTNode *l;
    struct BSTNode *r;
    int ln;
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

BSTNode* create_bstnode(long long int key) {
    BSTNode *n = (BSTNode*)malloc(sizeof(BSTNode));
    n->key = key;
    n->r = NULL;
    n->l = NULL;
    n->h = 0;
    n->ln = 0;
    return n;
}

int max(int x, int y) {
    if(x>y) return x;
    else return y;
}

int h(BSTNode* rt) {
    if(rt == NULL) return -1;
    else return rt->h;
}

int getBalance(BSTNode* rt) {
    if(rt == NULL) return 0;
    else return h(rt->l) - h(rt->r);
}

BSTNode* rightRotation(BSTNode *rt) {
    rt->ln-=(rt->l->ln+1);
    BSTNode *l = rt->l;
    BSTNode *lr = l->r;
    l->r = rt;
    rt->l = lr;
    rt->h = 1+max(h(rt->l), h(rt->r));
    l->h = 1+max(h(l->l), h(l->r));
    return l;
}

BSTNode* leftRotation(BSTNode *rt) {
    //left rotation aumenta o numero de nodes a esquerda do novo root em 1
    static int cont = 0;
    ++cont;
    //printf("cont:%d, key: %lld, %p\n", cont, rt->key, rt->r);
    BSTNode *r = rt->r;
    BSTNode *rl = r->l;
    r->l = rt;
    rt->r = rl;
    rt->h = 1+max(h(rt->l), h(rt->r));
    r->h = 1+max(h(r->l), h(r->r));
    //printf("%lld ganhou um node a esquerda!!\n", r->key);
    r->ln++;
    r->ln+=r->l->ln;
    return r;
}

int findhelp(BST* bst, BSTNode* rt, long long int key, int i) {
    if(rt == NULL) return -1;
    if(rt->key > key) return findhelp(bst, rt->l, key, i);
    else if(rt->key == key) {
        printf("%d\n", i+rt->ln+1); // AQUI COLOCA A FUNCAO
        return 1;
    }
    else {
        i+=rt->ln+1;
        //printf("passou por %lld, q tem %d nodes à esquerda\n", rt->key, rt->ln);
        return findhelp(bst, rt->r, key, i);
    }
}

int find(BST *bst, long long int key) {
    return findhelp(bst, bst->root, key, 0);
}

BSTNode* inserthelp(BSTNode *rt, long long int key) {
    if(rt == NULL) {
        return create_bstnode(key);
    }
    if(rt->key > key) {
        //printf("%lld ganhou um node a esquerda!\n", rt->key);
        rt->ln++;
        rt->l = inserthelp(rt->l, key);
    }
    else {
        rt->r = inserthelp(rt->r, key);
    }

    rt->h = 1+max(h(rt->l), h(rt->r));
    int balance = getBalance(rt);
    //printf("rodou5 %d %p %p\n", balance, rt->r, rt->l);
    if(balance < -1 && rt->r != NULL && key >= rt->r->key) return leftRotation(rt);
    if(balance > 1 && rt->l != NULL && key < rt->l->key) return rightRotation(rt);
    if(balance > 1 && rt->l != NULL && key >= rt->l->key) {
        //printf("cont2:%d, %lld, %p, balance %d\n", cont, key, rt->r, balance);
        rt->l = leftRotation(rt->l);
        return rightRotation(rt);
    }
    if(balance<-1 && rt->r != NULL && key >= rt->r->key) {
        rt->r = rightRotation(rt->r);
        return leftRotation(rt);
    }
    return rt;
}

void insert(BST *bst, long long int key) {
    bst->root = inserthelp(bst->root, key);
    bst->cont++;
}

void clear(BST* bst, BSTNode* rt) {
    if(rt!=NULL) {
        clear(bst, rt->l);
        clear(bst, rt->r);
        free(rt);
    }
}

int main() {
    int com, qtd, check, cont=0;
    BST *bst = create_bst();
    long long int key;
    scanf("%d", &qtd);
    while (qtd--) {
        cont++;
        scanf("%d %lld", &com, &key);
        switch(com) {
            case 1: {
                insert(bst, key);
                break;   
            }
            case 2: {
                check = find(bst, key);
                if(check == -1) printf("Data tidak ada\n");
                break;   
            }
        }
    }
    clear(bst, bst->root);
    free(bst);
    return 0;
}
