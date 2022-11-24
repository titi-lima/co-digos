#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define TOTAL 300;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cheio = PTHREAD_COND_INITIALIZER;
pthread_cond_t vazio = PTHREAD_COND_INITIALIZER;
int gasolina = 50; // região critica

void *produtor() {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (gasolina == 300) {
            pthread_cond_wait(&cheio, &mutex);
        }
        gasolina += 5;
        if (gasolina >= 10) {
            printf("mande consumir");
            pthread_cond_signal(&vazio);
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumidor() {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (gasolina <= 0) {
            pthread_cond_wait(&vazio, &mutex);
            // unlock(&mutex)
            // wait(&vazio)
            // lock(&mutex)
        }
        gasolina -= 5;
        if (gasolina <= 0) {
            printf("mande produzir");
            pthread_cond_signal(&cheio);
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t cons;
    pthread_t prod;

    pthread_create(&cons, NULL, &consumidor, NULL);
    pthread_create(&prod, NULL, &produtor, NULL);

    pthread_join(cons, NULL);
    pthread_join(cons, NULL);

    return 0;
}