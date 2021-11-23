#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define NUM_THREADS 32

char *texto;
char *chute;
int tamanho;
int intervalo;

int cria_palavra_secreta (char *palavra, int tam) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < tam-1; i++)
    palavra[i] = 32 + rand() % 94;
    palavra[tam-1] = '\0';
};

void *t_function (void *arg) {
    int j, k;
    long *rank;
    rank = (long *)arg;

    printf("-- Thread %ld começou", *rank);
    printf("\n");

        // Última thread
        if (*rank == (NUM_THREADS-1)) {
            printf("Última thread...\n");                       // last thread
            for (j = (NUM_THREADS-1)*intervalo; j < tamanho; j++) {
                for (k = 0; k < 255; k++) {
                    chute[j] = k;
                    if (chute[j] == texto[j]) {
                        j=0;
                        break;
                    };
                };
                        break;
            };
        }
        // Outras threads
        else {
            printf("Thread...\n");
            for (j = (*rank)*intervalo; j < ((*rank)+1)*intervalo; j++) {
                for (k = 0; k < 255; k++) {
                    chute[j] = k;
                    if (chute[j] == texto[j]) {
                        j=0;
                        break;
                    };
                };
                        break;
            };
        };
    
    printf("-- Thread %ld terminou\n", *rank);
    pthread_exit(NULL);
}
