#include "cocktail_shaker_sort.h"

/**
 * Função: swap
 * --------------
 * Troca os valores de duas variáveis inteiras utilizando ponteiros.
 *
 * Parâmetros:
 *  - int *primeiro: ponteiro para a primeira variável inteira.
 *  - int *segundo: ponteiro para a segunda variável inteira.
 *
 * Retorno:
 *  - void (sem retorno). A troca é feita diretamente nas variáveis apontadas.
 *
 * Exemplo de uso:
 *  int a = 5, b = 10;
 *  swap(&a, &b);
 *  // Agora a = 10 e b = 5
 */
void swap(int *primeiro, int *segundo) {
    int temp = *primeiro;
    *primeiro = *segundo;
    *segundo = temp;
}

/**
 * Função: cocktail_shaker_sort
 * ----------------------------
 * Ordena um vetor de inteiros utilizando o algoritmo Cocktail Shaker Sort,
 * uma variação do Bubble Sort que percorre o vetor em ambas as direções.
 *
 * Parâmetros:
 *  - int vetor[]: vetor de inteiros a ser ordenado.
 *  - int tamanho: número de elementos no vetor.
 *
 * Funcionamento:
 *  - A ordenação ocorre em "ida e volta":
 *      1. Da esquerda para a direita, empurrando os maiores valores para o final.
 *      2. Da direita para a esquerda, empurrando os menores valores para o início.
 *  - A cada passagem, os limites (esquerda e direita) são ajustados,
 *    diminuindo a área a ser verificada.
 *  - O processo se repete até que nenhuma troca seja mais necessária.
 *
 * Requisitos:
 *  - A função utiliza a função auxiliar `swap(int*, int*)` para trocar valores.
 *
 * Complexidade:
 *  - Pior caso: O(n²)
 *  - Melhor caso: O(n), se o vetor já estiver ordenado.
 */
void cocktail_shaker_sort(int vetor[], int tamanho){

    int esquerda = 0; 
    int direita = tamanho - 1;
    
   
    while (esquerda < direita) {
        
        for (int i = esquerda; i < direita; i++) {
            if (vetor[i] > vetor[i + 1]) {
                swap(&vetor[i], &vetor[i + 1]);
            }
        }
       
        direita--;

      
        for (int i = direita; i > esquerda; i--) {
            if (vetor[i] < vetor[i - 1]) {
                swap(&vetor[i], &vetor[i - 1]);
            }
        }
       
        esquerda++;
    }
}

/**
 * Função: cocktail_shaker_sort_v2
 * -------------------------------
 * Versão otimizada do algoritmo Cocktail Shaker Sort.
 * Ordena um vetor de inteiros em ordem crescente, com verificação de trocas
 * para interromper o algoritmo mais cedo se o vetor já estiver ordenado.
 *
 * Parâmetros:
 *  - int vetor[]: vetor de inteiros a ser ordenado.
 *  - int tamanho: número de elementos no vetor.
 *
 * Funcionamento:
 *  - A ordenação ocorre em duas direções (ida e volta), semelhante ao Bubble Sort.
 *  - Em cada passada, o algoritmo verifica se houve troca de elementos:
 *      - Se não houver troca em uma direção, o vetor está ordenado e o loop é encerrado.
 *  - Isso evita iterações desnecessárias, melhorando a eficiência no melhor caso.
 *
 * Vantagens sobre a versão original:
 *  - Interrompe a ordenação mais cedo se o vetor estiver parcialmente ou totalmente ordenado.
 *
 * Requisitos:
 *  - Utiliza a função auxiliar `swap(int*, int*)` para realizar as trocas.
 *
 * Complexidade:
 *  - Pior caso: O(n²)
 *  - Melhor caso: O(n), se o vetor já estiver ordenado.
 */
void cocktail_shaker_sort_v2(int vetor[], int tamanho) {
    int esquerda = 0;  
    int direita = tamanho - 1;  
    int trocou;  

    while (esquerda < direita) {
        trocou = 0;  

       
        for (int i = esquerda; i < direita; i++) {
            if (vetor[i] > vetor[i + 1]) {
                swap(&vetor[i], &vetor[i + 1]);
                trocou = 1; 
            }
        }
        if (!trocou) break;  

        
        direita--;  

        trocou = 0;  
        
        for (int i = direita; i > esquerda; i--) {
            if (vetor[i] < vetor[i - 1]) {
                swap(&vetor[i], &vetor[i - 1]);
                trocou = 1; 
            }
        }
        if (!trocou) break;

        
        esquerda++;  
    }
}