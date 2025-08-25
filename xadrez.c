#include <stdio.h>

#define N 8

char tabuleiro[N][N];

// Inicializa tabuleiro vazio
void inicializarTabuleiro() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tabuleiro[i][j] = '.';
}

// Mostra o tabuleiro
void imprimirTabuleiro() {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Marca posição da peça
void marcarPosicao(int x, int y, char peca) {
    if (x >= 0 && x < N && y >= 0 && y < N)
        tabuleiro[y][x] = peca;
}

// Função recursiva Torre (direita)
void moverTorre(int casas, int *x, int *y) {
    casas <= 0 ? (void)0 : ((*x)++, marcarPosicao(*x, *y, 'T'),
    printf("Direita -> (%d,%d)\n", *x, *y), imprimirTabuleiro(),
    moverTorre(casas - 1, x, y));
}

// Função recursiva Rainha (esquerda)
void moverRainha(int casas, int *x, int *y) {
    casas <= 0 ? (void)0 : ((*x)--, marcarPosicao(*x, *y, 'R'),
    printf("Esquerda -> (%d,%d)\n", *x, *y), imprimirTabuleiro(),
    moverRainha(casas - 1, x, y));
}

// Função recursiva Bispo (cima direita)
void moverBispoRecursivo(int casas, int *x, int *y) {
    casas <= 0 ? (void)0 : ((*x)++, (*y)++, marcarPosicao(*x, *y, 'B'),
    printf("Cima Direita -> (%d,%d)\n", *x, *y), imprimirTabuleiro(),
    moverBispoRecursivo(casas - 1, x, y));
}

// Bispo com loops aninhados
void moverBispoComLoops(int casas, int *x, int *y) {
    for (int i = 0; i < casas; i++) {
        for (int j = 0; j < 1; j++) {
            (*x)++, (*y)++;
            marcarPosicao(*x, *y, 'B');
            printf("Cima Direita -> (%d,%d)\n", *x, *y);
            imprimirTabuleiro();
        }
    }
}

// Cavalo (2 para cima, 1 para direita) usando loops complexos
void moverCavalo(int *x, int *y) {
    printf("\nMovimento do Cavalo:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            (i < 2 && j == i) ? ((*y)++, marcarPosicao(*x, *y, 'C'),
            printf("Cima -> (%d,%d)\n", *x, *y), imprimirTabuleiro()) :
            (i == 2 && j == 2 ? ((*x)++, marcarPosicao(*x, *y, 'C'),
            printf("Direita -> (%d,%d)\n", *x, *y), imprimirTabuleiro(), j = 3) : (void)0);
        }
    }
}

int main() {
    int x = 0, y = 0;
    int movimentoTorre, movimentoBispo, movimentoRainha;

    inicializarTabuleiro();
    marcarPosicao(x, y, 'S'); // posição inicial (Start)

    printf("Digite o número de casas para movimentar a Torre (Direita): ");
    scanf("%d", &movimentoTorre);

    printf("Digite o número de casas para movimentar o Bispo (Cima Direita): ");
    scanf("%d", &movimentoBispo);

    printf("Digite o número de casas para movimentar a Rainha (Esquerda): ");
    scanf("%d", &movimentoRainha);

    printf("\nMovimento da Torre:\n");
    moverTorre(movimentoTorre, &x, &y);

    printf("\nMovimento do Bispo (recursão):\n");
    moverBispoRecursivo(movimentoBispo, &x, &y);

    printf("\nMovimento do Bispo (loops aninhados):\n");
    moverBispoComLoops(movimentoBispo, &x, &y);

    printf("\nMovimento da Rainha:\n");
    moverRainha(movimentoRainha, &x, &y);

    moverCavalo(&x, &y);

    return 0;
}
