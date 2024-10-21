#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    char valor;
    struct elemento *proximo; //ponteiro *proximo para variaveis do tipo struct elemento, como um 'int *pont'
} Elemento;

typedef struct pilha{
    Elemento *topo; //outra declaração de ponteiro, poderia ser reescrita como 'struct elemento *topo;'
    int tamanho;
} Pilha;

Pilha* iniciar(){ //função chamada iniciar que retorna um ponteiro do tipo pilha
    
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;

    return p;
}

int empty(Pilha *p){
    return p->tamanho == 0;
}

int size(Pilha *p){
    return p->tamanho;
}

char top(Pilha *p){
    if(empty(p)){
        printf("Pilha vazia");
    }

    return p->topo->valor;
}

void push(Pilha *p, char caractere){
    Elemento *e = malloc(sizeof(Elemento));
    e->valor = caractere;
    e->proximo = p->topo;
    p->topo = e;

    p->tamanho = p->tamanho+1;
}

char pop(Pilha *p){
    Elemento *e;
    char c;

    if(!empty(p)){
        e = p->topo;
        c = e->valor;
        p->topo = p->topo->proximo;

        p->tamanho = p->tamanho-1;

        free(e);
        e = NULL;

        return c;
    } else{
        printf("Pilha vazia");
    }
}

int main(){
    Pilha *p = iniciar();
    char escolha;

    while (escolha != '0'){
        printf("\nEscolha a operacao:\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Top\n");
        printf("4 - Size\n");
        printf("5 - Empty\n");
        printf("0 - Sair\n");

        scanf(" %c", &escolha);

        switch(escolha) {
            case '1': {
                char caractere;
                printf("Digite o caractere para empilhar: ");
                scanf(" %c", &caractere);
                push(p, caractere);
                printf("Elemento %c empilhado.\n", caractere);
                break;
            }
            case '2': {
                if (!empty(p)) {
                    printf("Elemento removido: %c\n", pop(p));
                } else {
                    printf("Pilha vazia\n");
                }
                break;
            }
            case '3': {
                if (!empty(p)) {
                    printf("Topo da pilha: %c\n", top(p));
                } else {
                    printf("Pilha vazia\n");
                }
                break;
            }
            case '4': {
                printf("Tamanho da pilha: %d\n", size(p));
                break;
            }
            case '5': {
                if (empty(p)) {
                    printf("Pilha vazia\n");
                } else {
                    printf("Pilha nao esta vazia\n");
                }
                break;
            }
            case '0': {
                break;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        }
    }

    free(p);
    p = NULL;

    return 0;
}