#include <stdio.h>
#include <stdbool.h>

#define TAM 10
#define NAVIO 3
#define MAR 0
#define NAVIO_VALOR 3
#define HABILIDADE 5
#define TAM_HAB 5  // Tamanho das matrizes de habilidade (deve ser ímpar)

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = MAR;
}

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

bool dentroDoTabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

bool verificarEspaco(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l += i; c += i; }
        else if (direcao == 'E') { l += i; c -= i; }

        if (!dentroDoTabuleiro(l, c) || tabuleiro[l][c] != MAR)
            return false;
    }
    return true;
}

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

// Aplica uma matriz de habilidade no tabuleiro, com centro na posição (linhaOrigem, colunaOrigem)
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int linhaOrigem, int colunaOrigem) {
    int offset = TAM_HAB / 2;  // Para centralizar a matriz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int l = linhaOrigem + (i - offset);
                int c = colunaOrigem + (j - offset);
                if (dentroDoTabuleiro(l, c) && tabuleiro[l][c] == MAR) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }
}

// Gera uma matriz em forma de cone (triângulo para baixo)
void gerarMatrizCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB - 1) / 2 - i && j <= (TAM_HAB - 1) / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera uma matriz em forma de cruz
void gerarMatrizCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera uma matriz em forma de octaedro (losango)
void gerarMatrizOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posiciona 4 navios fixos
    posicionarNavio(tabuleiro, 0, 0, 'H');   // Horizontal
    posicionarNavio(tabuleiro, 5, 2, 'V');   // Vertical
    posicionarNavio(tabuleiro, 2, 2, 'D');   // Diagonal ↘
    posicionarNavio(tabuleiro, 1, 8, 'E');   // Diagonal ↙

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    gerarMatrizCone(cone);
    gerarMatrizCruz(cruz);
    gerarMatrizOctaedro(octaedro);

    // Aplica as habilidades no tabuleiro com ponto de origem fixo
    aplicarHabilidade(tabuleiro, cone, 6, 6);      // Cone na posição (6,6)
    aplicarHabilidade(tabuleiro, cruz, 3, 3);      // Cruz na posição (3,3)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);  // Octaedro na posição (7,2)

    // Exibe o tabuleiro final
    printf("\n=== Tabuleiro Batalha Naval - Nível Mestre ===\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
