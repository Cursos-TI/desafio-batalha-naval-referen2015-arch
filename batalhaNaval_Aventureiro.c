#include <stdio.h>

int main() {
    
    char linha_colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // 1. Representar o Tabuleiro (Matriz 10x10)
    int tabuleiro[10][10];
    int i, j;

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionar os Navios
    
    // Coordenadas iniciais do navio 1 horizontal
    int linha_navio_horizontal1 = 0;
    int coluna_navio_horizontal1 = 1;

    // Posiciona o navio 1 horizontal (valor 3)
    for (j = 0; j < 3; j++) {
        if (coluna_navio_horizontal1 + j < 10) {
            tabuleiro[linha_navio_horizontal1][coluna_navio_horizontal1 + j] = 3;
        }
    }

    // Coordenadas iniciais do navio 1 vertical
    int linha_navio_vertical1 = 1;
    int coluna_navio_vertical1 = 5;

    // Posiciona o navio 1 vertical (valor 3)
    for (i = 0; i < 3; i++) {
        if (linha_navio_vertical1 + i < 10) {
            tabuleiro[linha_navio_vertical1 + i][coluna_navio_vertical1] = 3;
        }
    }

    // Coordenadas iniciais do navio 2 diagonal
    int linha_navio_diagonal1 = 3;
    int coluna_navio_diagonal1 = 0;

    // Posiciona o navio 2 na diagonal principal (valor 3)
    // O loop avança tanto na linha quanto na coluna
    for (i = 0; i < 3; i++) {
        if (linha_navio_diagonal1 + i < 10 && coluna_navio_diagonal1 + i < 10) {
            tabuleiro[linha_navio_diagonal1 + i][coluna_navio_diagonal1 + i] = 3;
        }
    }

    // Coordenadas iniciais do navio 2 diagonal invertida
    int linha_navio_diagonal2 = 6;
    int coluna_navio_diagonal2 = 9;

    // Posiciona o navio 2 na diagonal secundária (valor 3)
    // O loop avança na linha e retrocede na coluna
    for (i = 0; i < 3; i++) {
        if (linha_navio_diagonal2 + i < 10 && coluna_navio_diagonal2 - i >= 0) {
            tabuleiro[linha_navio_diagonal2 + i][coluna_navio_diagonal2 - i] = 3;
        }
    }

    // 3. Exibir o Tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    
    // Imprime um espaço para alinhamento com a numeração das linhas
    printf("   "); 
    
    // Loop para imprimir a linha de A até J
    for (i = 0; i < 10; i++) {
        printf("%c ", linha_colunas[i]);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        // Imprime o número da linha para alinhamento
        if (i + 1 < 10) {
            printf(" %d", i + 1);
        } else {
            printf("%d", i + 1);
        }
        
        for (j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n"); 
    }
        printf("\n"); 
    return 0;
}
