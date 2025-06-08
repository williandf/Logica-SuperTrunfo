#include <stdio.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

// Função para calcular os atributos derivados
void calcular_derivados(struct Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibir_carta(struct Carta carta) {
    printf("\n%s (%s):\n", carta.cidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
}

int main() {
    // Cadastro das cartas diretamente no código
    struct Carta carta1 = {
        "SP", "C001", "São Paulo", 12300000, 1521.11, 236.0, 20
    };

    struct Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6748000, 1182.30, 140.0, 15
    };

    // Cálculo dos atributos derivados
    calcular_derivados(&carta1);
    calcular_derivados(&carta2);

    // Exibição das cartas
    printf("=== Carta 1 ===");
    exibir_carta(carta1);

    printf("\n=== Carta 2 ===");
    exibir_carta(carta2);

    // Escolha do atributo fixo para comparação: POPULAÇÃO
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    // Comparação usando if / if-else
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
