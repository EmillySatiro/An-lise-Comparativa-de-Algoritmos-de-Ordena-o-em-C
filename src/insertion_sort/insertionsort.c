
#include "insertionsort.h"

/**
 * Função: insertion_sort
 * ----------------------
 * Ordena um vetor de inteiros em ordem crescente utilizando o algoritmo
 * Insertion Sort (ordenação por inserção).
 *
 * Parâmetros:
 *  - int array[]: vetor de inteiros a ser ordenado.
 *  - int n: número de elementos no vetor.
 *
 * Funcionamento:
 *  - Percorre o vetor a partir do segundo elemento (índice 1).
 *  - Em cada iteração, "insere" o elemento atual (chave) na posição correta
 *    do subvetor à esquerda, que já está ordenado.
 *  - Desloca os elementos maiores que a chave uma posição à frente.
 *
 * Vantagens:
 *  - Simples de implementar.
 *  - Eficiente para vetores pequenos ou parcialmente ordenados.
 *
 * Complexidade:
 *  - Pior caso: O(n²)
 *  - Melhor caso: O(n), se o vetor já estiver ordenado.
 *  - Estável: não troca elementos iguais de lugar.
 */
void insertion_sort(int array[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
    }
}

