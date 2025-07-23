#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_CARTAS 5

typedef struct {
    int codigo;
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void exibirCarta(Carta c) {
    printf("Código: %d\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

int main() {
    srand(time(NULL));

    Carta cartas[NUM_CARTAS] = {
        {1, "São Paulo", 12300000, 1521.11, 780.0, 15},
        {2, "Rio de Janeiro", 6748000, 1182.30, 400.5, 20},
        {3, "Salvador", 2887000, 692.81, 63.0, 12},
        {4, "Belo Horizonte", 2530000, 331.4, 104.7, 10},
        {5, "Curitiba", 1964000, 430.9, 85.0, 8}
    };

    // Sorteia cartas
    int idxJogador = rand() % NUM_CARTAS;
    int idxComputador;
    do {
        idxComputador = rand() % NUM_CARTAS;
    } while (idxComputador == idxJogador);

    Carta jogador = cartas[idxJogador];
    Carta computador = cartas[idxComputador];

    printf("Sua carta:\n");
    exibirCarta(jogador);

    printf("\nEscolha um atributo para competir:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n");
    int escolha;
    scanf("%d", &escolha);

    printf("\nCarta do computador:\n");
    exibirCarta(computador);

    int vitoria = 0;

    switch (escolha) {
        case 1:
            if (jogador.populacao > computador.populacao) vitoria = 1;
            else if (jogador.populacao < computador.populacao) vitoria = -1;
            break;
        case 2:
            if (jogador.area > computador.area) vitoria = 1;
            else if (jogador.area < computador.area) vitoria = -1;
            break;
        case 3:
            if (jogador.pib > computador.pib) vitoria = 1;
            else if (jogador.pib < computador.pib) vitoria = -1;
            break;
        case 4:
            if (jogador.pontosTuristicos > computador.pontosTuristicos) vitoria = 1;
            else if (jogador.pontosTuristicos < computador.pontosTuristicos) vitoria = -1;
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    if (vitoria == 1)
        printf("\n🏆 Você venceu!\n");
    else if (vitoria == -1)
        printf("\n❌ Você perdeu!\n");
    else
        printf("\n⚖️ Empate!\n");

    return 0;