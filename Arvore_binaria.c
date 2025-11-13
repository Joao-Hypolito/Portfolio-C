#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No **raiz, int valor){
    No *novo = criarNo(valor);
    No *aux = *raiz;
    No *papai = *raiz;

    if(*raiz == NULL){
        *raiz = novo;
        return novo;
    }

    while(aux != NULL){
        papai = aux;
        if(aux->valor == valor)
            return NULL;

        if(valor < aux->valor){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }

    }

    if(valor < papai->valor)
        papai->esq = novo;
    else
        papai->dir = novo;
        
    return novo;

}


void imprimirEmOrdem(No* raiz) {
    if(raiz != NULL){
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->dir);        
    }
}


int main(){

    No *raiz = NULL;
    No *auxiliar;

    int numero[] = {10, 5, 15, 3, 7, 12, 18};
    int n = sizeof(numero)/sizeof(numero[0]);

    for(int i =0; i < n; i++){
        auxiliar = inserir(&raiz, numero[i]);
        if(auxiliar == NULL){
            printf("Erro ao inserir %d!\n", numero[i] );
        } else{
            printf("Valor %d inserido com sucesso!\n", numero[i]);
        }
    }

    
    printf("Árvore em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    return 0;
}