#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SYMBOLS 8
#define NUM_REELS 3

char* symbols[NUM_SYMBOLS] = {"Cereja", "Sino", "Limão", "BAR", "7", "Diamante", "Coração", "Ferradura"};

int randomSlot() {
    return rand() % NUM_SYMBOLS;
}

int main() {
    int reels[NUM_REELS];
    int saldo = 100; 
    int aposta;

    srand(time(0));

    while (saldo > 0) {
        printf("Saldo atual: %d. Insira sua aposta (0 para sair): ", saldo);
        scanf("%d", &aposta);

        if (aposta <= 0 || aposta > saldo) {
            break; 
        }

        saldo -= aposta; 

        for (int i = 0; i < NUM_REELS; i++) {
            reels[i] = randomSlot();
        }

        printf("Resultados: ");
        for (int i = 0; i < NUM_REELS; i++) {
            printf("%s ", symbols[reels[i]]);
        }
        printf("\n");

        if (reels[0] == reels[1] && reels[1] == reels[2]) {
            printf("Grande vitória! Você ganhou %d!\n", aposta * 10);
            saldo += aposta * 10; 
        } else {
            printf("Não ganhou desta vez. Tente novamente!\n");
        }
    }

    printf("Fim do jogo! Seu saldo final é %d\n", saldo);
    return 0;
}
