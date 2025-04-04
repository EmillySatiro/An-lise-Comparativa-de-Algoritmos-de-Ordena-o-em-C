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


void cocktail_shaker_sort_v2(int vetor[], int tamanho) {
    int esquerda = 0;  // começa no início do vetor
    int direita = tamanho - 1;  // Começa no final do vetor
    int trocou;  // verifica se houve troca

    while (esquerda < direita) {
        trocou = 0;  

        // ESQUERDA para DIREITA
        for (int i = esquerda; i < direita; i++) {
            if (vetor[i] > vetor[i + 1]) {
                swap(&vetor[i], &vetor[i + 1]);
                trocou = 1;  // marca que houve troca
            }
        }
        if (!trocou) break;  // se não houve trocas, já está ordenado

        // O maior elemento já está na direita
        direita--;  

        trocou = 0;  // reseta antes da segunda passagem

        // DIREITA para ESQUERDA
        for (int i = direita; i > esquerda; i--) {
            if (vetor[i] < vetor[i - 1]) {
                swap(&vetor[i], &vetor[i - 1]);
                trocou = 1;  // marca que houve troca
            }
        }
        if (!trocou) break;

        // O menor elemento já está na esquerda
        esquerda++;  
    }
}