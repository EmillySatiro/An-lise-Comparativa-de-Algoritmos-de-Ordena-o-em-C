#include "cocktail_shaker_sort.h"


void swap(int *primeiro, int *segundo) {
    int temp = *primeiro;
    *primeiro = *segundo;
    *segundo = temp;
}

void cocktail_shaker_sort(int vetor[], int tamanho){

    int esquerda = 0; // começa no início do vetor
    int direita = tamanho - 1;//cmeça no final do vetor
    
    // Enquanto os limites n se cruzarem
    while (esquerda < direita) {
        // ESQUERDA para DIREITA
        for (int i = esquerda; i < direita; i++) {
            if (vetor[i] > vetor[i + 1]) {
                swap(&vetor[i], &vetor[i + 1]);
            }
        }
        // O maior elemento já ta na direita então diminui  o limite
        direita--;

        // DIREITA para ESQUERDA
        for (int i = direita; i > esquerda; i--) {
            if (vetor[i] < vetor[i - 1]) {
                swap(&vetor[i], &vetor[i - 1]);
            }
        }
        // O menor elemento já ta na esquerda então aumenta o limite
        esquerda++;
    }
}