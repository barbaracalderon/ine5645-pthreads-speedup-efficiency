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
