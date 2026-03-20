#include <stdio.h>

int main() {

    // Variavel char para definição das linhas do tabuleiro, atribuindo letras a linha.
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // 1. Criando o tabuleiro (Matriz 10x10)
    int tabuleiro[10][10];

    // Iniciando o tabuleiro com 0 (água)

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Criando os navios com tamanho 3.

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Cordenadas Inciciais dos navios

    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical

    // POSICIONANDO NAVIO HORIZONTAL

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // POSICIONANDO O NAVIO VERTICAL

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // EXIBINDO O TABULEIRO

    printf("\n      TABULEIRO BATALHA NAVAL   \n");
    printf("\n   ");
    for (int j = 0; j < 10; j++) {
        printf("%2c ", colunas[j]); // Imprime as Letras das Colunas
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Imprime os Números das linhas

        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}