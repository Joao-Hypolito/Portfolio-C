#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

int main(){

    int n;
    int val;

    No* lista = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &val);

        No *novo = malloc(sizeof(No));
        novo ->valor = val;
        novo ->prox = lista;
        lista = novo;

    }


    return 0;
}