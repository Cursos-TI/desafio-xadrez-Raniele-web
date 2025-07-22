#include <stdio.h>

// Desafio Super Trunfo - Nível Mestre
// Batalha entre Curitiba e Salvador

int main() {
    // Carta 1 - Curitiba
    char estado1[] = "PR";
    char codigo1[] = "C01";
    char nomeCidade1[] = "Curitiba";
    unsigned long int populacao1 = 1963726;
    float area1 = 434.89;
    float pib1 = 58.9; // bilhões
    int pontosTuristicos1 = 20;
    float densidade1, pibPerCapita1, superPoder1;

    // Carta 2 - Salvador
    char estado2[] = "BA";
    char codigo2[] = "D02";
    char nomeCidade2[] = "Salvador";
    unsigned long int populacao2 = 2886698;
    float area2 = 693.28;
    float pib2 = 67.3; // bilhões
    int pontosTuristicos2 = 25;
    float densidade2, pibPerCapita2, superPoder2;

    // Cálculo dos atributos derivados
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;

    // Cálculo do Super Poder
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidade1);
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidade2);

    // Exibição das cartas
    printf("=== Carta 1: %s ===\n", nomeCidade1);
    printf("Estado: %s | Código: %s\n", estado1, codigo1);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bi R$ | Pontos Turísticos: %d\n", populacao1, area1, pib1, pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km² | PIB per Capita: %.2f R$ | Super Poder: %.2f\n\n", densidade1, pibPerCapita1, superPoder1);

    printf("=== Carta 2: %s ===\n", nomeCidade2);
    printf("Estado: %s | Código: %s\n", estado2, codigo2);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bi R$ | Pontos Turísticos: %d\n", populacao2, area2, pib2, pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km² | PIB per Capita: %.2f R$ | Super Poder: %.2f\n\n", densidade2, pibPerCapita2, superPoder2);

    // Comparações
    printf("=== Comparação de Cartas ===\n");
    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

    return 0;
}



