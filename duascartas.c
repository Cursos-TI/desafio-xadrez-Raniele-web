#include <stdio.h>

/*
Desafio Super Trunfo - Nível Aventureiro
Comparação entre duas cartas de cidades com menu interativo e lógica condicional.
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

    // --- Carta 2: Salvador ---
    char estado2[] = "BA";
    char codigo2[] = "D02";
    char nomeCidade2[] = "Salvador";
    unsigned long int populacao2 = 2886698;
    float area2 = 693.28;
    float pib2 = 67.3; // bilhões de reais
    int pontosTuristicos2 = 25;

    // --- Cálculo da densidade e PIB per capita ---
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // --- Menu Interativo ---
    int escolha;
    printf("=== SUPER TRUNFO - COMPARAÇÃO ENTRE CIDADES ===\n");
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &escolha);

    printf("\n--- Comparando %s e %s ---\n", nomeCidade1, nomeCidade2);

    // --- Comparação com switch ---
    switch (escolha) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lu habitantes\n", nomeCidade1, populacao1);
            printf("%s: %lu habitantes\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);
            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões R$\n", nomeCidade1, pib1);
            printf("%s: %.2f bilhões R$\n", nomeCidade2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d pontos\n", nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (MENOR valor vence)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);
            if (densidade1 < densidade2) {
                printf("Resultado: %s venceu! (Menor densidade)\n", nomeCidade1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: %s venceu! (Menor densidade)\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha um número entre 1 e 5.\n");
    }

    return 0;
}
