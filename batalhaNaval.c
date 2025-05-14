#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para verificar se um navio pode ser posicionado em uma direção
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'H') {
            if (coluna + i >= TAMANHO_TABULEIRO || tabuleiro[linha][coluna + i] != VALOR_AGUA)
                return 0; // Fora do tabuleiro ou já ocupado
        } else if (direcao == 'V') {
            if (linha + i >= TAMANHO_TABULEIRO || tabuleiro[linha + i][coluna] != VALOR_AGUA)
                return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = VALOR_NAVIO;
        } else if (direcao == 'V') {
            tabuleiro[linha + i][coluna] = VALOR_NAVIO;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração da matriz do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaNavio1 = 2, colunaNavio1 = 3; // horizontal
    int linhaNavio2 = 5, colunaNavio2 = 7; // vertical

    // Verifica e posiciona o primeiro navio (horizontal)
    if (podePosicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 'H')) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 'H');
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Verifica e posiciona o segundo navio (vertical)
    if (podePosicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 'V')) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 'V');
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro final
    printf("\nTabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}