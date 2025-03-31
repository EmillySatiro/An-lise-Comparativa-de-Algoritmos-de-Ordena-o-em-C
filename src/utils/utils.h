#ifndef UTILS_H
#define UTILS_H

#define TAMANHO_MAXIMO 1000000

typedef void (*SortFunction)(int[], int);

int* criar_array_cresecente(int size);
  
int* criar_array_decrescente(int size);

int* criar_array_aleatorio(int size);

int esta_ordenado(int array[], int size);

int* copiar_array(int array[], int size);
        
double calcular_tempo(int array[], int size, SortFunction sortFunc);
      
#endif