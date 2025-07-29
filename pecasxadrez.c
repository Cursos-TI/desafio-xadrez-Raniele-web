#include <stdio.h>

// Função recursiva para o movimento do Bispo (diagonal superior direita)
void moverBispo(int casas) {
    if (casas == 0) return;
    printf("Cima Direita\n");
    moverBispo(casas - 1);
}

// Função recursiva para o movimento da Torre (direita)
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento da Rainha (esquerda)
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função para movimentar o Cavalo (1x em L - Cima + Direita)
void moverCavaloCimaDireita() {
    // Loop aninhado com múltiplas variáveis e uso de break/continue
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 1 && j == 1) {
                printf("Cima\n");
                printf("Direita\n");
                break;
            } else {
                continue;
            }
        }
    }
}

// Função para movimentar o Cavalo (2 Baixo + 1 Esquerda)
// Desafio do Nível Aventureiro
void moverCavaloBaixoEsquerda() {
    // Constantes para o número de casas a percorrer
    const int casasBaixo = 2;
    const int casasEsquerda = 1;

    printf("\n--- Cavalo (Movimento em L - 2x Baixo + 1x Esquerda) ---\n");

    // Loop externo com FOR para casas para baixo
    for (int i = 0; i < casasBaixo; i++) {
        printf("Baixo\n");
    }

    // Loop interno com WHILE para casa para esquerda
    int j = 0;
    while (j < casasEsquerda) {
        printf("Esquerda\n");
        j++;
    }
}

// Versão inicial com diferentes tipos de loops
void movimentosIniciais() {
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;

    printf("\n--- Torre (5 casas para a Direita) ---\n");
    for (int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n--- Bispo (5 casas na Diagonal Superior Direita) ---\n");
    int i = 0;
    while (i < casasBispo) {
        printf("Cima Direita\n");
        i++;
    }

    printf("\n--- Rainha (8 casas para a Esquerda) ---\n");
    int j = 0;
    do {
        printf("Esquerda\n");
        j++;
    } while (j < casasRainha);

    printf("\n--- Cavalo (Movimento em L - Baixo + Esquerda) ---\n");
    for (int i = 0; i < 1; i++) {
        int j = 0;
        while (j < 1) {
            printf("Baixo\n");
            printf("Esquerda\n");
            j++;
        }
    }
}

int main() {
    printf("=== DESAFIO DE XADREZ - MATECHECK ===\n");

    // Nível Novato + Aventureiro Inicial
    movimentosIniciais();

    // Nível Aventureiro (Movimento do Cavalo com Loops Aninhados)
    moverCavaloBaixoEsquerda();

    // Nível Mestre
    printf("\n=== NÍVEL MESTRE ===\n");

    printf("\n--- Bispo (5 casas na Diagonal Superior Direita - Recursão) ---\n");
    moverBispo(5);

    printf("\n--- Torre (5 casas para a Direita - Recursão) ---\n");
    moverTorre(5);

    printf("\n--- Rainha (8 casas para a Esquerda - Recursão) ---\n");
    moverRainha(8);

    printf("\n--- Cavalo (1 movimento em L - Cima + Direita) ---\n");
    moverCavaloCimaDireita();

    return 0;
}

