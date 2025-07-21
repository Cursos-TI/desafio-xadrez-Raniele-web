#include <stdio.h>

// Desafio Super Trunfo - Nível Aventureiro
// Exemplo com cidades reais de nomes simples: Curitiba e Salvador

int main() {
    // Dados da carta 1 - Curitiba
    char estado1[] = "PR";
    char codigo1[] = "C01";
    char nomeCidade1[] = "Curitiba";
    int populacao1 = 1963726;
    float area1 = 434.89;
    float pib1 = 58.9; // bilhões
    int pontosTuristicos1 = 20;
    float densidade1, pibPerCapita1;

    // Dados da carta 2 - Salvador
    char estado2[] = "BA";
    char codigo2[] = "D02";
    char nomeCidade2[] = "Salvador";
    int populacao2 = 2886698;
    float area2 = 693.28;
    float pib2 = 67.3; // bilhões
    int pontosTuristicos2 = 25;
    float densidade2, pibPerCapita2;

    // Cálculos da carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Cálculos da carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Exibição dos dados da carta 1
    printf("Carta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n\n", pibPerCapita1);

    // Exibição dos dados da carta 2
    printf("Carta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0;
}


