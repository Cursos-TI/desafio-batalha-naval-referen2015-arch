#include <stdio.h>

int main() {
    
    char linha_colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];
    int i, j;

    // 1. Inicializa todas as posições do tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionar os Navios

    // Navio horizontal (valor 3)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 1;
    for (j = 0; j < 3; j++) {
        if (coluna_navio_horizontal + j < 10) {
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] = 3;
        }
    }

    // Navio vertical (valor 3)
    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 5;
    for (i = 0; i < 3; i++) {
        if (linha_navio_vertical + i < 10) {
            tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
        }
    }
    
    // 3. Exibir o Tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");

    // Cabeçalho das colunas
    printf("   ");
    for (i = 0; i < 10; i++) {
        printf("%c ", linha_colunas[i]);
    }
    printf("\n");

    // Linhas do tabuleiro
    for (i = 0; i < 10; i++) {
        printf("%2d", i + 1);  // Alinhamento da numeração das linhas
        for (j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n"); // Linha em branco ao final da exibição

    return 0;
}
