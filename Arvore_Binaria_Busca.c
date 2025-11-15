#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int id;
    struct _no *pai;
    struct _no *esq;
    struct _no *dir;
} No;

void inicializar(No **raiz) {
    *raiz = NULL;
}

int estavazia(No *raiz) {
    return(raiz == NULL);
}   

No* criarNovoNo(int id, No* pai) {
    No *novo = (No*) malloc(sizeof(No));  

    if (novo == NULL) {                   
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    novo->id  = id;        
    novo->pai = pai;       
    novo->esq = NULL;      
    novo->dir = NULL;      

    return novo;           
}

void inserir(No **raiz, int id) {
    No *atual = *raiz;
    No *pai = NULL;

    
    while (atual != NULL) {
        pai = atual;

        if (id < atual->id) {
            atual = atual->esq;
        }
        else if (id > atual->id) {
            atual = atual->dir;
        }
        else {
            
            printf("Valor %d ja existe na arvore!\n", id);
            return;
        }
    }

    
    No *novo = criarNovoNo(id, pai);

    if (pai == NULL) {
        
        *raiz = novo;
    }
    else if (id < pai->id) {
        pai->esq = novo;
    }
    else {
        pai->dir = novo;
    }
}

void inOrder(No *raiz) {
    if (raiz == NULL) return;
    inOrder(raiz->esq);
    printf("%d ", raiz->id);
    inOrder(raiz->dir);
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) {
        return; 
    }

    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);

    free(raiz);
}

int main() {
    int n;
    int *valores;
    No *raiz = NULL;

    printf("Quantos valores deseja inserir na arvore?\n");
    scanf("%d", &n);

    valores = (int*) malloc(n * sizeof(int));
    if (valores == NULL) {
        printf("Erro de alocacao de memoria\n");
        return 1;
    }

    printf("Digite %d valor(es):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
        inserir(&raiz, valores[i]);
    }

    printf("\nValores inseridos (em ordem): ");
    inOrder(raiz);
    printf("\n");

    liberarArvore(raiz);
    raiz = NULL;   

    free(valores);

    return 0;
}





 

