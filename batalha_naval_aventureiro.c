#include <stdio.h>

// DEFINES para facilitar manutenção
#define TAM 10          // Tamanho do tabuleiro (10x10).
#define AGUA 0          // Representa água no tabuleiro.
#define NAVIO 3         // Representa parte de um navio.
#define TAM_NAVIO 3     // Tamanho fixo dos navios.

int main() {

    // Vetor de caracteres representando as colunas (A até J).
    char colunas[TAM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Declaração da matriz 10x10 (tabuleiro do jogo).
    int tabuleiro[TAM][TAM];

    // Inicializando todas as posições do tabuleiro com água (0).
    for (int i = 0; i < TAM; i++) {            // Percorre as linhas.
        for (int j = 0; j < TAM; j++) {        // Percorre as colunas.
            tabuleiro[i][j] = AGUA;            // Define cada posição como água.
        }
    }

    // Vetor representando um navio de tamanho 3 (todos valores = 3).
    int navio[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // =========================
    // NAVIO HORIZONTAL
    // =========================

    int linhaH = 2, colunaH = 3; // Posição inicial do navio horizontal.

    int podeH = 1; // Flag: 1 = pode posicionar, 0 = não pode.

    // Verifica se o navio pode ser colocado.
    for (int i = 0; i < TAM_NAVIO; i++) {

        // Verifica:
        // 1. Se sai do limite do tabuleiro.
        // 2. Se já existe outro navio na posição.
        if (colunaH + i >= TAM || tabuleiro[linhaH][colunaH + i] != AGUA) {
            podeH = 0; // Não pode posicionar.
        }
    }

    // Se for válido, posiciona o navio.
    if (podeH) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navio[i];
        }
    } else {
        printf("Erro ao posicionar navio horizontal\n");
    }

    // =========================
    // NAVIO VERTICAL
    // =========================

    int linhaV = 5, colunaV = 7; // Posição inicial do navio vertical.

    int podeV = 1; // Flag de validação.

    // Verificação de posição.
    for (int i = 0; i < TAM_NAVIO; i++) {

        // Verifica limite e sobreposição.
        if (linhaV + i >= TAM || tabuleiro[linhaV + i][colunaV] != AGUA) {
            podeV = 0;
        }
    }

    // Posiciona o navio se possível.
    if (podeV) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = navio[i];
        }
    } else {
        printf("Erro ao posicionar navio vertical\n");
    }

    // =========================
    // NAVIO DIAGONAL ↘ (principal)
    // =========================

    int linhaD1 = 3, colunaD1 = 1; // Nova posição inicial da diagonal.

    int podeD1 = 1; // Flag de validação.

    // Verifica se pode posicionar.
    for (int i = 0; i < TAM_NAVIO; i++) {

        // Verifica:
        // linha + i e coluna + i (movimento diagonal ↘).
        // limite do tabuleiro e sobreposição.
        if (linhaD1 + i >= TAM || colunaD1 + i >= TAM ||
            tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
            podeD1 = 0;
        }
    }

    // Posiciona se válido.
    if (podeD1) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
        }
    } else {
        printf("Erro ao posicionar navio diagonal 1\n");
    }

    // =========================
    // NAVIO DIAGONAL ↙ (secundária)
    // =========================

    int linhaD2 = 0, colunaD2 = TAM - 1; // Começa na última coluna.

    int podeD2 = 1; // Flag de validação.

    // Verificação de posição.
    for (int i = 0; i < TAM_NAVIO; i++) {

        // linha + i e coluna - i (movimento diagonal ↙).
        // verifica limites e sobreposição.
        if (linhaD2 + i >= TAM || colunaD2 - i < 0 ||
            tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
            podeD2 = 0;
        }
    }

    // Posiciona se válido.
    if (podeD2) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
        }
    } else {
        printf("Erro ao posicionar navio diagonal 2\n");
    }

    // =========================
    // EXIBIÇÃO DO TABULEIRO
    // =========================

    printf("\n      TABULEIRO BATALHA NAVAL   \n\n");

    // Imprime as letras das colunas.
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2c ", colunas[j]);
    }
    printf("\n");

    // Percorre o tabuleiro para imprimir.
    for (int i = 0; i < TAM; i++) {

        printf("%2d ", i + 1); // Número da linha (1 a 10).

        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]); // Valor da posição (0 ou 3).
        }

        printf("\n"); // Quebra de linha após cada linha do tabuleiro.
    }

    return 0;
}