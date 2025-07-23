#include <stdio.h>

/*
Desafio Super Trunfo - Nível Mestre
Comparação entre duas cartas de cidades reais usando atributos numéricos.

Neste programa:
- Os dados das cidades já estão cadastrados.
- A densidade populacional e o PIB per capita são calculados.
- É feita a comparação entre as duas cartas usando o atributo escolhido no código (PIB per capita neste caso).
*/

int main() {
    // --- Carta 1: Curitiba ---
    char estado1[] = "PR";
    char codigo1[] = "C01";
    char nomeCidade1[] = "Curitiba";
    unsigned long int populacao1 = 1963726;
    float area1 = 434.89;
    float pib1 = 58.9; // bilhões de reais
    int pontosTuristicos1 = 20;
    float densidade1, pibPerCapita1;

    // --- Carta 2: Salvador ---
    char estado2[] = "BA";
    char codigo2[] = "D02";
    char nomeCidade2[] = "Salvador";
    unsigned long int populacao2 = 2886698;
    float area2 = 693.28;
    float pib2 = 67.3; // bilhões de reais
    int pontosTuristicos2 = 25;
    float densidade2, pibPerCapita2;

    // --- Cálculo da densidade populacional e PIB per capita ---
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;

    // --- Exibição dos dados das cartas ---
    printf("=== Carta 1: %s (%s) ===\n", nomeCidade1, estado1);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bi R$ | Pontos Turísticos: %d\n", populacao1, area1, pib1, pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km² | PIB per Capita: %.2f R$\n\n", densidade1, pibPerCapita1);

    printf("=== Carta 2: %s (%s) ===\n", nomeCidade2, estado2);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bi R$ | Pontos Turísticos: %d\n", populacao2, area2, pib2, pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km² | PIB per Capita: %.2f R$\n\n", densidade2, pibPerCapita2);

    // --- Comparação utilizando um único atributo ---
    printf("=== Comparação de Cartas (Atributo: PIB per Capita) ===\n");
    printf("Carta 1 - %s: %.2f R$\n", nomeCidade1, pibPerCapita1);
    printf("Carta 2 - %s: %.2f R$\n", nomeCidade2, pibPerCapita2);

    if (pibPerCapita1 > pibPerCapita2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (pibPerCapita2 > pibPerCapita1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate entre as duas cartas!\n");
    }

    return 0;
}




