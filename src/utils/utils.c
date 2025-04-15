#include <time.h>
#include <stdlib.h>
#include "utils.h"

/**
 * Arquivo utilitário para geração, cópia e verificação de vetores,
 * além de medição de tempo de execução de algoritmos de ordenação.
 *
 * Funções incluídas:
 *
 * 1. int* criar_array_crescente(int size)
 *    - Cria e retorna um vetor com valores de 0 até size - 1 em ordem crescente.
 *
 * 2. int* criar_array_decrescente(int size)
 *    - Cria e retorna um vetor com valores de size - 1 até 0 em ordem decrescente.
 *
 * 3. int* criar_array_aleatorio(int size)
 *    - Cria e retorna um vetor com valores aleatórios entre 0 e TAMANHO_MAXIMO - 1.
 *    - Requer que a constante TAMANHO_MAXIMO esteja definida.
 *
 * 4. int esta_ordenado(int array[], int size)
 *    - Verifica se um vetor está ordenado em ordem crescente.
 *    - Retorna 1 se estiver ordenado, 0 caso contrário.
 *
 * 5. int* copiar_array(int array[], int size)
 *    - Cria e retorna uma cópia de um vetor passado por parâmetro.
 *
 * 6. double calcular_tempo(int array[], int size, SortFunction sortFunc)
 *    - Calcula e retorna o tempo de execução (em milissegundos) de uma função
 *      de ordenação (passada como ponteiro de função) aplicada a um vetor.
 *    - Usa a função clock() da biblioteca <time.h>.
 *
 * Observações:
 *  - O tipo SortFunction deve ser definido como um ponteiro para função de ordenação
 *    com a seguinte assinatura: void funcao(int array[], int size);
 *  - Todas as alocações usam malloc. O usuário é responsável por liberar a memória alocada.
 *
 * Requisitos:
 *  - Incluir as bibliotecas: <stdlib.h>, <stdio.h>, <time.h>
 */
int* criar_array_cresecente(int size) {
  int* array = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
      array[i] = i;
  }
  return array;
}

int* criar_array_decrescente(int size) {
  int* array = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
      array[i] = size - i - 1;
  }
  return array;
}

int* criar_array_aleatorio(int size) {
  int* array = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
      array[i] = rand() % (TAMANHO_MAXIMO); 
  }
  return array;
}

int esta_ordenado(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
      if (array[i] > array[i + 1]) {
          return 0; 
      }
  }
  return 1; 
}

int* copiar_array(int array[], int size) {
  int* copia = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
      copia[i] = array[i];
  }
  return copia;
}


double calcular_tempo(int array[], int size, SortFunction sortFunc) {
  clock_t start, end;
  
  start = clock();
  sortFunc(array, size);
  end = clock();
  
  double tempo = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
  
  return tempo;
}