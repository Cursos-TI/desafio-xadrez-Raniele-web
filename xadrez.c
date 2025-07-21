#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    // Nível Novato - Movimentação das Peças
    // Declarar variáveis constantes para representar o número de casas que cada peça pode se mover.
    const int MOV_BISPO = 5;
    const int MOV_TORRE = 5;
    const int MOV_RAINHA = 8;

    // Implementação de Movimentação do Bispo
    // Utilizar uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
    printf("Movimentação do Bispo (diagonal superior direita):\n");
    for (int i = 0; i < MOV_BISPO; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }

    printf("\n---------------------------\n");

    // Implementação de Movimentação da Torre
    // Utilizar uma estrutura de repetição para simular a movimentação da Torre para a direita.
    printf("Movimentação da Torre (horizontal para a direita):\n");
    int i = 0;
    while (i < MOV_TORRE) {
        printf("Direita\n");
        i++;
    }

    printf("\n---------------------------\n");

    // Implementação de Movimentação da Rainha
    // Utilizar uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
    printf("Movimentação da Rainha (horizontal para a esquerda):\n");
    int j = 0;
    do {
        printf("Esquerda\n");
        j++;
    } while (j < MOV_RAINHA);



    return 0;
}
