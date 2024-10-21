#include <stdio.h>
#include <stdlib.h>

int main(){
    int **matriz;
    int linhas, colunas;
    int i, j;

    scanf("%d", &linhas);
    scanf("%d", &colunas);
    matriz = (int **) malloc(linhas * sizeof(int *)); //aloca o vetor de ponteiros

    for(i = 0; i < linhas; i++){
        *(matriz + i) = (int *) malloc(colunas * sizeof(int));
    }

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            *(*(matriz + i) + j) = i + j; //matriz[i][j] exemplo de atribuição i + j
        }
    }

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%d", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    for(i = 0; i < linhas; i++){
        free(*(matriz + i));
    }
    free(matriz);


    return 0;
}