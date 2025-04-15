#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>  
#include "insertion_sort/insertionsort.h"
#include "cocktail_shaker_sort/cocktail_shaker_sort.h"
#include "utils/utils.h"


#define REPETICOES 3

// Função para testar um algoritmo de ordenação
void testar_algoritmo(const char* nome_algoritmo, int sizes[], int num_sizes, 
                     void (*algoritmo)(int*, int), int* bases_cresc[], int* bases_dec[], int* bases_rand[]) {
    
    double soma_cresc[num_sizes];
    double soma_dec[num_sizes];
    double soma_rand[num_sizes];

    for (int i = 0; i < num_sizes; i++) {
        soma_cresc[i] = 0.0;
        soma_dec[i] = 0.0;
        soma_rand[i] = 0.0;
    }

    printf("===================== TESTE DE ORDENAÇÃO =====================\n");
    printf("Algoritmo: %s\n", nome_algoritmo);
    printf("-------------------------------------------------------------\n");
    printf(" N° Exec | Tamanho | Crescente (ms) | Decrescente (ms) | Aleatório (ms) |\n");
    printf("-------------------------------------------------------------\n");
    
    for (int exec = 0; exec < REPETICOES; exec++) {
        for (int i = 0; i < num_sizes; i++) {
            int size = sizes[i];

            // Criando cópias para ordenação
            int* cres_cpy = copiar_array(bases_cresc[i], size);
            int* dec_cpy = copiar_array(bases_dec[i], size);
            int* rand_cpy = copiar_array(bases_rand[i], size);
            
            // Medindo tempo para cada caso
            double temp_cresc = calcular_tempo(cres_cpy, size, algoritmo);
            double temp_dec = calcular_tempo(dec_cpy, size, algoritmo);
            double temp_rand = calcular_tempo(rand_cpy, size, algoritmo);
            
            // Verificando se os vetores foram ordenados corretamente
            if (!esta_ordenado(cres_cpy, size) || 
            !esta_ordenado(dec_cpy, size) || 
            !esta_ordenado(rand_cpy, size)) {
                printf("ERRO: Falha na ordenação para o tamanho %d\n", size);
            }

            // Imprimindo resultados
            printf(" %7d | %7d | %14.2f | %15.2f | %13.2f |\n", 
            exec + 1, size, temp_cresc, temp_dec, temp_rand);

            soma_cresc[i] += temp_cresc;
            soma_dec[i] += temp_dec;
            soma_rand[i] += temp_rand;
            
            free(cres_cpy);
            free(dec_cpy);
            free(rand_cpy);
        }
    }

    // Imprimindo a média dos tempos
    printf("-------------------------------------------------------------\n");
    printf("| Média dos tempos de ordenação para o algoritmo %s\n", nome_algoritmo);
    printf("-------------------------------------------------------------\n");
    printf("| Tamanho | Crescente (ms) | Decrescente (ms) | Aleatório (ms) |\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < num_sizes; i++) {
        printf("| %7d | %14.2f | %15.2f | %13.2f |\n", 
               sizes[i], soma_cresc[i] / REPETICOES, soma_dec[i] / REPETICOES, soma_rand[i] / REPETICOES);
    }
    printf("-------------------------------------------------------------\n\n");
}

int main() {
    // Tamanhos dos conjuntos de teste
    int sizes[] = {20000, 40000, 60000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // bases para todos os testes
    int* bases_cresc[num_sizes];
    int* bases_dec[num_sizes];
    int* bases_rand[num_sizes];

    srand(time(NULL));

    // Gerando os vetores bases
    for (int i = 0; i < num_sizes; i++) {
        bases_cresc[i] = criar_array_cresecente(sizes[i]);
        bases_dec[i] = criar_array_decrescente(sizes[i]);
        bases_rand[i] = criar_array_aleatorio(sizes[i]);
    }

    // Testando cada algoritmo com os vetores
    testar_algoritmo("Insertion Sort", sizes, num_sizes, insertion_sort, bases_cresc, bases_dec, bases_rand);
    testar_algoritmo("Cocktail Shaker Sort", sizes, num_sizes, cocktail_shaker_sort, bases_cresc, bases_dec, bases_rand);
    testar_algoritmo("Cocktail Shaker Sort Melhorado", sizes, num_sizes, cocktail_shaker_sort, bases_cresc, bases_dec, bases_rand);


    for (int i = 0; i < num_sizes; i++) {
        free(bases_cresc[i]);
        free(bases_dec[i]);
        free(bases_rand[i]);
    }

    return 0;
}