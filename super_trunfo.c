#include <stdio.h>
#include <string.h>

// Estrutura de uma carta
struct Carta {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

// Cálculo da densidade demográfica
void calcular_densidade(struct Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
}

// Exibe menu de atributos
void exibir_menu(int excluido) {
    printf("\nEscolha um atributo:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função para obter valor do atributo
float obter_valor(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontos_turisticos;
        case 5: return carta.densidade;
        default: return -1;
    }
}

// Nome do atributo
const char* nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.0, 25};
    struct Carta carta2 = {"Argentina", 45195777, 2780400.0, 640.0, 18};

    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    do {
        exibir_menu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) {
            printf("Atributo inválido. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo
    do {
        exibir_menu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
            printf("Atributo inválido ou repetido. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Obter valores dos atributos
    float v1a1 = obter_valor(carta1, atributo1);
    float v2a1 = obter_valor(carta2, atributo1);
    float v1a2 = obter_valor(carta1, atributo2);
    float v2a2 = obter_valor(carta2, atributo2);

    // Exibir os valores
    printf("\nComparando %s e %s:\n", carta1.pais, carta2.pais);
    printf("%s:\n  %s: %.2f\n  %s: %.2f\n",
           nome_atributo(atributo1), carta1.pais, v1a1, carta2.pais, v2a1);
    printf("%s:\n  %s: %.2f\n  %s: %.2f\n",
           nome_atributo(atributo2), carta1.pais, v1a2, carta2.pais, v2a2);

    // Comparação com regra de densidade (menor vence)
    int pontos1 = 0, pontos2 = 0;
    pontos1 += (atributo1 == 5) ? (v1a1 < v2a1) : (v1a1 > v2a1);
    pontos2 += (atributo1 == 5) ? (v2a1 < v1a1) : (v2a1 > v1a1);
    pontos1 += (atributo2 == 5) ? (v1a2 < v2a2) : (v1a2 > v2a2);
    pontos2 += (atributo2 == 5) ? (v2a2 < v1a2) : (v2a2 > v1a2);

    // Soma dos valores
    float soma1 = v1a1 + v1a2;
    float soma2 = v2a1 + v2a2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.pais, soma1);
    printf("%s: %.2f\n", carta2.pais, soma2);

    // Resultado final com operador ternário
    printf("\nResultado final:\n");
    printf("%s\n",
           (soma1 > soma2) ? (printf("Vencedor: %s\n", carta1.pais), "") :
           (soma2 > soma1) ? (printf("Vencedor: %s\n", carta2.pais), "") :
           "Empate!");

    return 0;
}
