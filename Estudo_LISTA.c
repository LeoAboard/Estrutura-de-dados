#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{                     //dado do tipo elemento, possui um valor e um ponteiro
    char valor;
    struct elemento *proximo;                //ponteiro para proximo elemento
} Elemento;

typedef struct lista{
    Elemento *inicio;                        //primeiro elemento da lista
    int tamanho;
} Lista;

Lista* iniciar(){
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tamanho = 0;

    return l;
}

int size(Lista *l){
    return l->tamanho;
}

int empty(Lista *l){
    return l->tamanho == 0;
}

void add(Lista *l, char caracter){          //adiciona sempre no inicio da lista
    if(empty(l)){
        Elemento *e = malloc(sizeof(Elemento)); //prepara uma posição de memória do tamanho de "elemento"
        e->valor = caracter;                    //valor do elemento = caracter recebido
        e->proximo = NULL;                      //ponteiro para o proximo é nulo pois este é o primeiro elemento da lista

        l->inicio = e;
    } else{
        Elemento *e = malloc(sizeof(Elemento)); 
        e->valor = caracter;

        Elemento *antigo_inicio = l->inicio; //salva o ponteiro para o inicio da lista antes de altera-lo
        l->inicio = e;                       //declara o novo elemento como novo inicio
        e->proximo = antigo_inicio;          //aponta o novo inicio para o antigo inicio NOVO(1) -> VELHO(2)
    }

    l->tamanho = l->tamanho + 1;             //incrementa o tamanho da lista em 1 para cada adição
}

char get(Lista *l, int posicao){             //busca uma POSIÇÃO especifica
    if(empty(l)){
        printf("Lista vazia!");            
        return 'e';
    }

    if(posicao > l->tamanho || posicao <= 0){
        printf("Posicao invalida");          //primeiro verifica se a posição acessada existe
        return 'e';
    }

    int i = 1;
    Elemento *e = l->inicio;                //coloca o ponteiro no inicio da lista
    while(e != NULL){                       //percorre a lista até nulo
        if(i == posicao){                   //se estiver na posição enviada, retorna o valor dela
            return e->valor;
        }                             
        e = e->proximo;                    //aponta para o proximo e incrementa o i
        i++;
        
    }

    return '\0';
}

char delete(Lista *l, int posicao){        //excluir a posição informada
    if(empty(l)){                          //verifica novamente se a posição é valida
        printf("Lista vazia");
        return 'e';
    }

    if(posicao > l->tamanho || posicao <= 0){ 
        printf("Posicao invalida");
        return 'e';
    }

    if(posicao == 1){
        Elemento *e = l->inicio;          //para excluir a posição 1, cria-se um elemento temporário
        char caracter = e->valor;         //obtem o valor a ser excluido
        l->inicio = l->inicio->proximo;   //o proximo elemento passa a ser o novo inicio
        free(e);                          //elimina o elemento da memória

        l->tamanho = l->tamanho - 1;      //diminui o tamanho da lista
        return caracter;
    } else{                              //caso nao for o primeiro elemento   
        Elemento *e_atual = l->inicio;   //precisamos percorrer do inicio da lista para encontrar o elemento a ser excluido
        Elemento *e_anterior;            //ponteiro para auxiliar no momento da exclusao

        int i;
        for(i = 1; i < posicao; i++){    //percorre a lista até um antes da posição
            e_anterior = e_atual;
            e_atual = e_atual->proximo;
        }

        e_anterior->proximo = e_atual->proximo; //quando a posição é atingida
        char caracter = e_atual->valor;         //guarda o valor a ser excluido para retornar
        free(e_atual);                          //elimina o valor

        l->tamanho = l->tamanho - 1;
        return caracter;
    }

}

void printLista(Lista *l){
    if(empty(l)){            
        return;
    }

    Elemento *e = l->inicio;
    while(e != NULL){
        printf("%c ", e->valor);
        e = e->proximo;
    }
}

int main(){
    
    Lista *lista = iniciar();
    int operacao;

    for(int i = 0; i < 10; i++){
        printf("Digite a operacao:\n 1 - add\n 2 - get\n 3 - delete\n");
        scanf("%d", &operacao);

        if(operacao == 1){
            char valor;
            printf("Escreva o caracter a ser adicionado: ");
            getchar();                                //limpar o maldito buffer
            scanf("%c", &valor);
            add(lista, valor);
            printLista(lista);
            printf("\n");
        }

        if(operacao == 2){
            int posicao;
            printf("Escreva a posicao a ser procurada: ");
            scanf("%d", &posicao);
            char obtido = get(lista, posicao);
            if(obtido != 'e'){
                printf("Valor na posicao %d: %c", posicao, obtido);
            }
            printf("\n");
        }

        if(operacao == 3){
            int posicao;
            printf("Escreva a posicao a ser excluida: ");
            scanf("%d", &posicao);
            char ver = delete(lista, posicao);
            if(ver != 'e'){
                printf("Item excluido, nova lista: ");
                printLista(lista);
            }
            printf("\n");
        }
    }

    printf("\nLista final: ");
    printLista(lista);

    return 0;
}