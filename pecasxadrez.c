#include <stdio.h>

// ======================= FUNÇÕES RECURSIVAS =========================

// Função recursiva para mover a Torre para a Direita
void moverTorreRecursivo(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorreRecursivo(casas - 1);
}

// Função recursiva para mover a Rainha para a Esquerda
void moverRainhaRecursivo(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainhaRecursivo(casas - 1);
}

// Função recursiva para o Bispo (Diagonal Superior Direita)
// Inclui loops aninhados para simular o avanço diagonal
void moverBispoRecursivoComLoops(int casas) {
    if (casas == 0) return;

    // Loop aninhado: vertical e horizontal (movimento diagonal)
    for (int linha = 0; linha < 1; linha++) {
        for (int coluna = 0; coluna < 1; coluna++) {
            printf("Cima Direita\n");
        }
    }

    moverBispoRecursivoComLoops(casas - 1);
}

// ======================= MOVIMENTOS DO CAVALO =========================

// Cavalo (Cima + Direita em L): 2 cima, 1 direita
// Utiliza loops aninhados com múltiplas variáveis, break e continue
void moverCavaloCimaDireita_L() {
    printf("\n--- Cavalo (Movimento em L - 2x Cima + 1x Direita) ---\n");

    const int casasCima = 2;
    const int casasDireita = 1;

    for (int i = 0; i <= casasCima; i++) {
        if (i == casasCima) {
            for (int j = 0; j < casasDireita + 1; j++) {
                if (j == 1) {
                    printf("Direita\n");
                    break;
                }
                continue;
            }
        } else {
            printf("Cima\n");
        }
    }
}

// Cavalo (Baixo + Esquerda em L) com loops simples
void moverCavaloBaixoEsquerda_L() {
    const int casasBaixo = 2;
    const int casasEsquerda = 1;

    printf("\n--- Cavalo (Movimento em L - 2x Baixo + 1x Esquerda) ---\n");

    // Loop externo com FOR para "Baixo"
    for (int i = 0; i < casasBaixo; i++) {
        printf("Baixo\n");
    }

    // Loop interno com WHILE para "Esquerda"
    int j = 0;
    while (j < casasEsquerda) {
        printf("Esquerda\n");
        j++;
    }
}

// ======================= MOVIMENTOS INICIAIS (DESAFIOS ANTERIORES) =========================

void movimentosIniciais() {
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;

    printf("\n--- Torre (5 casas para a Direita - loop for) ---\n");
    for (int i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n--- Bispo (5 casas na Diagonal Superior Direita - loop while) ---\n");
    int i = 0;
    while (i < casasBispo) {
        printf("Cima Direita\n");
        i++;
    }

    printf("\n--- Rainha (8 casas para a Esquerda - loop do-while) ---\n");
    int j = 0;
    do {
        printf("Esquerda\n");
        j++;
    } while (j < casasRainha);

    printf("\n--- Cavalo (Movimento em L - 1x Baixo + 1x Esquerda) ---\n");
    for (int i = 0; i < 1; i++) {
        int j = 0;
        while (j < 1) {
            printf("Baixo\n");
            printf("Esquerda\n");
            j++;
        }
    }
}

// ======================= MAIN =========================

int main() {
    printf("=== DESAFIO DE XADREZ - MATECHECK ===\n");

    // Nível Novato + Aventureiro Inicial
    movimentosIniciais();

    // Cavalo com loops aninhados (2 baixo + 1 esquerda)
    moverCavaloBaixoEsquerda_L();

    // ================== NÍVEL MESTRE ==================

    printf("\n=== NÍVEL MESTRE ===\n");

    // Torre com recursão
    printf("\n--- Torre (5 casas para a Direita - Recursão) ---\n");
    moverTorreRecursivo(5);

    // Rainha com recursão
    printf("\n--- Rainha (8 casas para a Esquerda - Recursão) ---\n");
    moverRainhaRecursivo(8);

    // Bispo com recursividade e loops aninhados
    printf("\n--- Bispo (5 casas na Diagonal Superior Direita - Recursão + Loops) ---\n");
    moverBispoRecursivoComLoops(5);

    // Cavalo com movimento em L (Cima + Direita) com loops complexos
    moverCavaloCimaDireita_L();

    return 0;
}

