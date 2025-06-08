#include <stdio.h>

// Estrutura para a carta
struct Carta {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

// Função para calcular densidade
void calcular_densidade(struct Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
}

// Exibe os dados da carta
void exibir_carta(struct Carta carta) {
    printf("\nPaís: %s\n", carta.pais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidade);
}

// Função principal
int main() {
    struct Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.0, 25};
    struct Carta carta2 = {"Argentina", 45195777, 2780400.0, 640.0, 18};

    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    int opcao;

    printf("=== SUPER TRUNFO - COMPARAÇÃO DE CARTAS ===\n");
    exibir_carta(carta1);
    exibir_carta(carta2);

    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nComparação entre %s e %s:\n", carta1.pais, carta2.pais);

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.pais, carta1.populacao);
            printf("%s: %d\n", carta2.pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.pais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.pais, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.pais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.pais, carta1.pontos_turisticos);
            printf("%s: %d\n", carta2.pais, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5:
            printf("Atributo: Densidade Demográfica (menor vence)\n");
            printf("%s: %.2f hab/km²\n", carta1.pais, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.pais, carta2.densidade);
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu!\n", carta1.pais);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu!\n", carta2.pais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida. Por favor, escolha de 1 a 5.\n");
            break;
    }

    return 0;
}
