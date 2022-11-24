#include <iostream>
#include <pthread.h>
#include <unistd.h>

using std::cin;
using std::cout;

pthread_cond_t haPassageiros = PTHREAD_COND_INITIALIZER;
pthread_mutex_t tremMutex = PTHREAD_MUTEX_INITIALIZER;
int contador_estacao = 0;

void *trens(void *arg) {
    int contador_trem = 0;
    while (1) {
        while (contador_trem < 20) {
            pthread_mutex_lock(&tremMutex);
            while (contador_estacao == 0) pthread_cond_wait(&haPassageiros, &tremMutex);
            cout << "No trem " << *(int *)arg << " embarcou um passageiro\n";
            contador_trem++;
            contador_estacao--;
            // sleep(1);
            cout << contador_estacao << " passageiros na estação\n";
            pthread_mutex_unlock(&tremMutex);
        }
        contador_trem = 0;
        cout << "Trem " << *(int *)arg << " foi simbora \n";
    }
}

void estacao() {
    pthread_t trem[5];
    for (int i = 0; i < 5; i++) {
        int *iheap = new int(i);
        pthread_create(&trem[i], NULL, &trens, (void *)iheap);
    }
    while (1) {
        if (contador_estacao < 5) {
            pthread_mutex_lock(&tremMutex);
            cout << "Passageiro entrou na estação\n";
            contador_estacao += 1;
            pthread_mutex_unlock(&tremMutex);
            pthread_cond_signal(&haPassageiros);
        }
    }
}

int main() {
    estacao();
    return 0;
}