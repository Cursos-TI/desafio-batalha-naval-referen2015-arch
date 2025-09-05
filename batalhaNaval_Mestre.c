#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Função para aplicar uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha_tab = origem_linha - TAM_HAB / 2 + i;
            int coluna_tab = origem_coluna - TAM_HAB / 2 + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (linha_tab >= 0 && linha_tab < TAM_TAB && coluna_tab >= 0 && coluna_tab < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] != 3) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }
}

int main() {
    char linha_colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[TAM_TAB][TAM_TAB];
    int i, j;

    // Inicializa tabuleiro com água (0)
    for (i = 0; i < TAM_TAB; i++) {
        for (j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navios (valor 3)
    for (j = 0; j < 3; j++) tabuleiro[0][1 + j] = 3;
    for (i = 0; i < 3; i++) tabuleiro[1 + i][5] = 3;
    for (i = 0; i < 3; i++) tabuleiro[3 + i][0 + i] = 3;
    for (i = 0; i < 3; i++) tabuleiro[6 + i][9 - i] = 3;

    // Matriz Cone (5x5)
    int cone[TAM_HAB][TAM_HAB];
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            cone[i][j] = (i >= j && i >= TAM_HAB - 1 - j) ? 1 : 0;
        }
    }

    // Matriz Cruz (5x5)
    int cruz[TAM_HAB][TAM_HAB];
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            cruz[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }

    // Matriz Octaedro (5x5)
    int octaedro[TAM_HAB][TAM_HAB];
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            int dist = abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2);
            octaedro[i][j] = (dist <= TAM_HAB / 2) ? 1 : 0;
        }
    }

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    // Exibe tabuleiro
    printf("Tabuleiro de Batalha Naval com Habilidades:\n\n");
    printf("   ");
    for (i = 0; i < TAM_TAB; i++) printf("%c ", linha_colunas[i]);
    printf("\n");

    for (i = 0; i < TAM_TAB; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAM_TAB; j++) {
            int celula = tabuleiro[i][j];
            if (celula == 0) printf("0 ");
            else if (celula == 3) printf("3 ");
            else if (celula == 5) printf("^ ");
        }
        printf("\n");
    }
        printf("\n");
    return 0;
}