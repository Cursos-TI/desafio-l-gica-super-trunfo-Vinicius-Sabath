#include <stdio.h>

// Definição da estrutura Cidade
typedef struct {
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Cidade;

// Função para cadastrar uma cidade
void cadastrarCidade(Cidade *c) {
    printf("Digite o código da cidade: ");
    scanf("%s", c->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->nome); // Permite nomes com espaços
    printf("Digite a população: ");
    scanf("%d", &c->populacao);
    printf("Digite a área (km²): ");
    scanf("%f", &c->area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
    printf("\n");
}

// Função para comparar dois atributos
void compararAtributos(char *atributo, float valorA, float valorB, char *nomeA, char *nomeB, int *pontosA, int *pontosB) {
    printf("%s: ", atributo);
    if (valorA > valorB) {
        printf("%s venceu!\n", nomeA);
        (*pontosA)++;
    } else if (valorB > valorA) {
        printf("%s venceu!\n", nomeB);
        (*pontosB)++;
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int pontos1 = 0, pontos2 = 0;

    printf("=== Cadastro da Cidade 1 ===\n");
    cadastrarCidade(&cidade1);

    printf("=== Cadastro da Cidade 2 ===\n");
    cadastrarCidade(&cidade2);

    printf("=== Comparação das Cidades ===\n");
    compararAtributos("População", cidade1.populacao, cidade2.populacao, cidade1.nome, cidade2.nome, &pontos1, &pontos2);
    compararAtributos("Área", cidade1.area, cidade2.area, cidade1.nome, cidade2.nome, &pontos1, &pontos2);
    compararAtributos("PIB", cidade1.pib, cidade2.pib, cidade1.nome, cidade2.nome, &pontos1, &pontos2);
    
    // Calculando densidade populacional
    float densidade1 = cidade1.populacao / cidade1.area;
    float densidade2 = cidade2.populacao / cidade2.area;
    compararAtributos("Densidade Populacional", densidade1, densidade2, cidade1.nome, cidade2.nome, &pontos1, &pontos2);

    compararAtributos("Pontos Turísticos", cidade1.pontosTuristicos, cidade2.pontosTuristicos, cidade1.nome, cidade2.nome, &pontos1, &pontos2);

    printf("\n=== Resultado Final ===\n");
    if (pontos1 > pontos2) {
        printf("A cidade vencedora é: %s\n", cidade1.nome);
    } else if (pontos2 > pontos1) {
        printf("A cidade vencedora é: %s\n", cidade2.nome);
    } else {
        printf("O resultado final foi um empate!\n");
    }

    return 0;
}