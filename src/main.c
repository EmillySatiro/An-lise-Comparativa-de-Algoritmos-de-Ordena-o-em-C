#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>  
#include "insertion_sort/insertionsort.h"
#include "cocktail_shaker_sort/cocktail_shaker_sort.h"
#include "utils/utils.h"

// Função para testar um algoritmo de ordenação e retornar resultados
void testar_algoritmo(const char* nome_algoritmo, int sizes[], int num_sizes, 
                     void (*algoritmo)(int*, int)) {
    // Arrays para armazenar os tempos de execução
    double temp_cresc[num_sizes];
    double temp_dec[num_sizes];
    double temp_rand[num_sizes];
    
    printf("===================== TESTE DE ORDENAÇÃO =====================\n");
    printf("Algoritmo: %s\n", nome_algoritmo);
    printf("-------------------------------------------------------------\n");
    printf("| Tamanho | Crescente (ms) | Decrescente (ms) | Aleatório (ms) |\n");
    printf("-------------------------------------------------------------\n");
    
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        
        // Criando os vetores de teste
        int* crescente = criar_array_cresecente(size);
        int* decrescente = criar_array_decrescente(size);
        int* random = criar_array_aleatorio(size);
        
        // Criando cópias para ordenação
        int* cres_cpy = copiar_array(crescente, size);
        int* dec_cpy = copiar_array(decrescente, size);
        int* rand_cpy = copiar_array(random, size);

        // Medindo tempo para cada caso
        temp_cresc[i] = calcular_tempo(cres_cpy, size, algoritmo);
        temp_dec[i] = calcular_tempo(dec_cpy, size, algoritmo);
        temp_rand[i] = calcular_tempo(rand_cpy, size, algoritmo);
        
        // Verificando se os vetores foram ordenados corretamente
        int cresc_sorted = esta_ordenado(cres_cpy, size);
        int dec_sorted = esta_ordenado(dec_cpy, size);
        int rand_sorted = esta_ordenado(rand_cpy, size);
        
        // Imprimindo resultados
        printf("| %7d | %14.2f | %15.2f | %13.2f |\n", 
               size, temp_cresc[i], temp_dec[i], temp_rand[i]);
        
        // Verificação de ordenação
        if (!cresc_sorted || !dec_sorted || !rand_sorted) {
            printf("ERRO: Falha na ordenação para o tamanho %d\n", size);
            if (!cresc_sorted) printf("  - Array crescente não ordenado corretamente\n");
            if (!dec_sorted) printf("  - Array decrescente não ordenado corretamente\n");
            if (!rand_sorted) printf("  - Array aleatório não ordenado corretamente\n");
        }
        
        // Liberando memória
        free(crescente);
        free(decrescente);
        free(random);
        free(cres_cpy);
        free(dec_cpy);
        free(rand_cpy);
    }
    
    printf("-------------------------------------------------------------\n\n");
}

int main() {
    // Tamanhos dos conjuntos de teste
    int sizes[] = {20000, 40000, 60000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    srand(time(NULL));

    //testar_algoritmo("Insertion Sort", sizes, num_sizes, insertion_sort);
    
    testar_algoritmo("Cocktail Shaker Sort", sizes, num_sizes, cocktail_shaker_sort);
    
    return 0;
}