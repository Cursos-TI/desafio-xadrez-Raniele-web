#include <stdio.h>
#include <stdbool.h>

#define TAM 10        // Tamanho do tabuleiro
#define NAVIO 3       // Tamanho do navio
#define MAR 0         // Representa água
#define NAVIO_VALOR 3 // Valor que representa navio no tabuleiro

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = MAR;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se coordenadas estão dentro dos limites do tabuleiro
bool dentroDoTabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

// Verifica se há espaço livre para posicionar o navio na direção desejada
bool verificarEspaco(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha, c = coluna;

        if (direcao == 'H') c += i;              // Horizontal
        else if (direcao == 'V') l += i;         // Vertical
        else if (direcao == 'D') { l += i; c += i; } // Diagonal ↘
        else if (direcao == 'E') { l += i; c -= i; } // Diagonal ↙

        if (!dentroDoTabuleiro(l, c) || tabuleiro[l][c] != MAR)
            return false;
    }
    return true;
}

// Posiciona o navio no tabuleiro se houver espaço
bool posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    if (!verificarEspaco(tabuleiro, linha, coluna, direcao))
        return false;

    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 'H') tabuleiro[linha][coluna + i] = NAVIO_VALOR;
        else if (direcao == 'V') tabuleiro[linha + i][coluna] = NAVIO_VALOR;
        else if (direcao == 'D') tabuleiro[linha + i][coluna + i] = NAVIO_VALOR;
        else if (direcao == 'E') tabuleiro[linha + i][coluna - i] = NAVIO_VALOR;
    }
    return true;
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento fixo de 4 navios (2 normais e 2 diagonais)
    // Cada chamada tenta posicionar o navio e, se falhar, ignora (para este nível não há repetição de tentativa)

    // Navios horizontais ou verticais
    posicionarNavio(tabuleiro, 0, 0, 'H');  // Horizontal no canto superior esquerdo
    posicionarNavio(tabuleiro, 5, 2, 'V');  // Vertical no meio

    // Navios diagonais
    posicionarNavio(tabuleiro, 2, 2, 'D');  // Diagonal ↘ (principal)
    posicionarNavio(tabuleiro, 1, 8, 'E');  // Diagonal ↙ (invertida)

    // Exibe o tabuleiro final
    printf("\n=== Tabuleiro Batalha Naval - Nível Aventureiro ===\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
