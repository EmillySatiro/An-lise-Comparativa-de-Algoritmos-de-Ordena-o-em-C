#include <time.h>
#include <stdlib.h>
#include "utils.h"

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