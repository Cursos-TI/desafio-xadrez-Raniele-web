#include <stdio.h>

/*
Desafio Super Trunfo - Nível Mestre
Comparação de dois atributos escolhidos pelo jogador com menu dinâmico.
*/

// Função auxiliar para mostrar o nome do atributo
const char* mostrarNomeAtributo(int attr) {
    switch (attr) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função auxiliar para obter o valor de um atributo
float obterValor(int atributo, unsigned long int pop, float area, float pib, int pt, float densidade) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pt;
        case 5: return densidade;
        default: return 0;
    }
}

int main() {
    // --- Carta 1: Curitiba ---
    char nomeCidade1[] = "Curitiba";
    unsigned long int populacao1 = 1963726;
    float area1 = 434.89;
    float pib1 = 58.9;
    int pontosTuristicos1 = 20;

    // --- Carta 2: Salvador ---
    char nomeCidade2[] = "Salvador";
    unsigned long int populacao2 = 2886698;
    float area2 = 693.28;
    float pib2 = 67.3;
    int pontosTuristicos2 = 25;

    // --- Densidade populacional ---
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // --- Menu de escolha ---
    int attr1, attr2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma1, soma2;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &attr1);

    if (attr1 < 1 || attr1 > 5) {
        printf("Opção inválida!\n");
        return 1;
    }

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != attr1) {
            printf("%d - %s\n", i, mostrarNomeAtributo(i));
        }
    }
    printf("Opção: ");
    scanf("%d", &attr2);

    if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
        printf("Opção inválida!\n");
        return 1;
    }

    // --- Obter valores dos atributos ---
    valor1_c1 = obterValor(attr1, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    valor1_c2 = obterValor(attr1, populacao2, area2, pib2, pontosTuristicos2, densidade2);
    valor2_c1 = obterValor(attr2, populacao1, area1, pib1, pontosTuristicos1, densidade1);
    valor2_c2 = obterValor(attr2, populacao2, area2, pib2, pontosTuristicos2, densidade2);

    // --- Ajustar densidade (menor vence = inverte valor) ---
    if (attr1 == 5) {
        valor1_c1 = -valor1_c1;
        valor1_c2 = -valor1_c2;
    }
    if (attr2 == 5) {
        valor2_c1 = -valor2_c1;
        valor2_c2 = -valor2_c2;
    }

    // --- Calcular soma final de pontos ---
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    // --- Exibir valores escolhidos ---
    printf("\n--- Comparação entre %s e %s ---\n", nomeCidade1, nomeCidade2);
    printf("Atributo 1: %s\n", mostrarNomeAtributo(attr1));
    printf("%s: %.2f | %s: %.2f\n", nomeCidade1, obterValor(attr1, populacao1, area1, pib1, pontosTuristicos1, densidade1),
                                     nomeCidade2, obterValor(attr1, populacao2, area2, pib2, pontosTuristicos2, densidade2));

    printf("Atributo 2: %s\n", mostrarNomeAtributo(attr2));
    printf("%s: %.2f | %s: %.2f\n", nomeCidade1, obterValor(attr2, populacao1, area1, pib1, pontosTuristicos1, densidade1),
                                     nomeCidade2, obterValor(attr2, populacao2, area2, pib2, pontosTuristicos2, densidade2));

    // --- Resultado final ---
    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", nomeCidade1, soma1);
    printf("%s: %.2f\n", nomeCidade2, soma2);

    printf("\nResultado Final: ");
    if (soma1 > soma2) {
        printf("%s venceu!\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", nomeCidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
