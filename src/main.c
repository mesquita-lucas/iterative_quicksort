#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include <locale.h>

#define MAX_INPUT 1024

/*A estratégia de usar uma stack e fazer o algoritmo de quicksort iterativamente ao invés de recursivamente gera uma vantagem na complexidade
de espaço desse algoritmo. Ao invés de colocar as partições na stack de forma arbitrária, isso é, sem se importar com o tamanho das partições,
é feita uma verificação antes para checar o tamanho. Dessa forma, se adicionarmos primeiro as partições maiores e depois as menores, estas vão
ser processadas primeiro, e a profundidade total da pilha vai ser menor, evitando erros como o stack overflow, fazendo com que, além disso, 
possamos usar uma stack menor.*/

int main() {
    setlocale(LC_ALL, "portuguese");

    char input[MAX_INPUT];
    int* arr = (int*)malloc(MAX_INPUT * sizeof(int));
    int n = 0;

    printf("===== Ordenar Números (Quicksort) =====\n");
    printf("Digite os números separados por espaço: ");
    fgets(input, MAX_INPUT, stdin);

    char* token = strtok(input, " \n");
    while (token != NULL) {
        arr[n++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    if(n == 0) {
        printf("Nenhum número válido foi fornecido.\n");
        return 1;
    }

    quicksort(arr, 0, n - 1);

    printf("Sequência ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}