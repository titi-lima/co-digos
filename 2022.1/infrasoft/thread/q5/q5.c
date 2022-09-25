#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t filosofo[5];
pthread_mutex_t garfinho[5];

void *macarraozin(void *idvoid) {
    int id = *(int *)idvoid;
    printf("\nfilosofo %d ta pensando", id);
    pthread_mutex_lock(&garfinho[id]);           // filósofo pega garfo à direita
    pthread_mutex_lock(&garfinho[(id + 1) % 5]); // filósofo pega garfo à esquerda
    printf("\nfilosofo %d ta comendo", id);      // reg crítica
    sleep(1);
    printf("\nfilosofo %d ta satisfeito", id);
    pthread_mutex_unlock(&garfinho[(id + 1) % 5]); // garfos liberados
    pthread_mutex_unlock(&garfinho[id]);
    free(idvoid);
    pthread_exit(NULL);
}

int main() {
    int i;
    for (i = 0; i <= 4; i++) {
        pthread_mutex_init(&garfinho[i], NULL);
    }
    while (1) {
        for (i = 0; i <= 4; i++) {
            int *iheap = (int *)malloc(sizeof(int));
            *iheap = i;
            pthread_create(&filosofo[i], NULL, (void *)macarraozin, (void *)iheap);
        }
        for (i = 0; i <= 4; i++) {
            pthread_join(filosofo[i], NULL);
        }
    }
    return 0;
}
// gcc q5.c -pthread -o q5 && ./q5