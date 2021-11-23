#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define NUM_THREADS 32      // Change this to as many as you want

char *texto;                // text
char *chute;                // guess
int tamanho;                // size
int intervalo;              // gap
                            // palavra = word

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

    printf("-- Thread %ld começou", *rank);                 // thread %ld started
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
    
    printf("-- Thread %ld terminou\n", *rank);          // thread %ld finished
    pthread_exit(NULL);
}


int main (int argc, char *argv[]) {
    pthread_t t[NUM_THREADS];
    unsigned long tam;
    long *ids[NUM_THREADS];
    long i;

    if (argc != 2) {
    printf("Favor informar o tamanho da palavra. Por exemplo:\n");      // Please type the size of the word. Example: \n
    printf("./reproduz_texto_paralelo 100\n");
    return 0;
    }

    sscanf(argv[1], "%lu", &tam);
    texto = malloc(sizeof(char)*tam);
    chute = malloc(sizeof(char)*tam);
    cria_palavra_secreta(texto, tam);

    tamanho = tam;
    intervalo =  tam/NUM_THREADS;

    // ABERTURA DAS THREADS     (OPENING THREADS)
    printf("==> NUM_THREADS: %d.\n", NUM_THREADS);
    for (i = 0; i < NUM_THREADS; i++) {
        ids[i] = malloc(sizeof(long));
        *ids[i] = i;
        pthread_create(&t[i], NULL, t_function, (void*)ids[i]);  // último NULL argumento
    };
    
    // FECHAMENTO DAS THREADS       (CLOSING THREADS)
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(t[i], NULL);
    };
    printf("==> Todas as threads acabaram.\n");
    exit(EXIT_SUCCESS);
    
    return 0;
};
