#!/bin/bash

# rode o comando para conceder permissão de execução -> chmod +x src/execute.sh


# Definições de variáveis
EXECUTABLE="ordenacao"

# Compilar o código
gcc -o $EXECUTABLE src/main.c src/insertion_sort/insertionsort.c \
    src/cocktail_shaker_sort/cocktail_shaker_sort.c src/utils/utils.c -I.

# Verificar se a compilação foi bem-sucedida
echo "Compilação concluída."
if [ $? -eq 0 ]; then
    echo "Executando o programa..."
    ./$EXECUTABLE
else
    echo "Erro na compilação."
fi
# Limpar os arquivos gerados
rm -f $EXECUTABLE