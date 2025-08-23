#include <stdio.h>

// Função recursiva para movimentar a Torre (direita)
void moverTorre(int casas, int *x, int *y) {
    if (casas <= 0) return;
    (*x)++;
    printf("Direita -> Posição atual: (%d, %d)\n", *x, *y);
    moverTorre(casas - 1, x, y);
}

// Função recursiva para movimentar a Rainha (esquerda)
void moverRainha(int casas, int *x, int *y) {
    if (casas <= 0) return;
    (*x)--;
    printf("Esquerda -> Posição atual: (%d, %d)\n", *x, *y);
    moverRainha(casas - 1, x, y);
}

// Função recursiva para movimentar o Bispo (cima direita)
void moverBispoRecursivo(int casas, int *x, int *y) {
    if (casas <= 0) return;
    (*x)++;
    (*y)++;
    printf("Cima Direita -> Posição atual: (%d, %d)\n", *x, *y);
    moverBispoRecursivo(casas - 1, x, y);
}

// Movimento do Bispo com loops aninhados
void moverBispoComLoops(int casas, int *x, int *y) {
    for (int i = 0; i < casas; i++) {
        for (int j = 0; j < 1; j++) {
            (*x)++;
            (*y)++;
            printf("Cima Direita -> Posição atual: (%d, %d)\n", *x, *y);
        }
    }
}

// Movimento do Cavalo (duas casas para cima e uma para direita)
void moverCavalo(int *x, int *y) {
    printf("\nMovimento do Cavalo:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if (i < 2 && j == i) {
                (*y)++;
                printf("Cima -> Posição atual: (%d, %d)\n", *x, *y);
            } else if (i == 2 && j == 2) {
                (*x)++;
                printf("Direita -> Posição atual: (%d, %d)\n", *x, *y);
                break;
            } else {
                continue;
            }
        }
    }
}

int main() {
    int x = 0, y = 0;
    int movimentoTorre, movimentoBispo, movimentoRainha;

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
