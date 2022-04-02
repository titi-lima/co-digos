#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main() {
    int cont=0, a, b, aux, data, tam=0, aux2;
    char str[7];
    Node *head = NULL;
    Node *curr = NULL;
    Node *tail = NULL;
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    curr = head;
    tail = head;

    scanf("%d", &a);

    for(aux = 0; aux < a; ++aux) {
        scanf("%d", &b);
        printf("Caso %d:\n", aux+1);
        for(aux2 = 0; aux2 < b; ++aux2) {
            scanf(" %s", str);
            switch(str[0]) {
                case 'i': {
                    scanf("%d", &data);
                    ++tam;
                    curr->next = insert(curr, tail, data);
                    break;
                }
                case 'r': {
                    --tam;
                    curr->next = delete(curr);
                    break;
                }
                case 'c': {
                    scanf("%d", &data);
                    count(head, data);
                    break;
                }
                case 'p': {
                    curr = prev(curr, head);
                    break;
                }
                case 'n': {
                    curr = next(curr);
                    break;
                }
            }
        }
    }


    clear(head);
    return 0;
}