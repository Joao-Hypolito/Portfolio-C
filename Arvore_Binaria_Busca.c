#include <stdio.h>
#include <stdlib.h>

/* ==========================================================
   DEFINIÇÃO DA ESTRUTURA DO NÓ
   - Cada nó tem:
     - id   → valor armazenado
     - pai  → ponteiro para o nó pai (pode ajudar em remoções)
     - esq  → ponteiro para filho esquerdo
     - dir  → ponteiro para filho direito
   ========================================================== */

typedef struct _no{
    int id;
    struct _no *pai;
    struct _no *esq;
    struct _no *dir;
} No;

/* ==========================================================
   FUNÇÃO: inicializar
   - Coloca a árvore como vazia (raiz = NULL).
   - Repare que usamos ponteiro para ponteiro (No **)
     porque queremos modificar a variável passada.
   ========================================================== */

void inicializar(No **raiz) {
    *raiz = NULL;
}

/* ==========================================================
   FUNÇÃO: estaVazia
   - Retorna 1 se a árvore está vazia, 0 caso contrário.
   ========================================================== */

int estavazia(No *raiz) {
    return(raiz == NULL);
}   

/* ==========================================================
   FUNÇÃO: criarNovoNo
   - Cria dinamicamente um nó, já inicializado com o valor.
   ========================================================== */


 