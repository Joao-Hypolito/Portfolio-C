#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id_aco;          
    int quantidade;
    struct No *proximo;  
} No;

No* adicionarAco(No *topo, int valor, int qtd) {
    No *novo = (No*)malloc(sizeof(No));
    novo->id_aco = valor;
    novo->quantidade = qtd;
    novo->proximo = topo;
    return novo;
}

void receberEntrega(No *topo, int aco_desejado, int qtd_chegou){
    No *atual = topo;

    while (atual != NULL){
        if (atual->id_aco == aco_desejado) {
            atual->quantidade = atual->quantidade + qtd_chegou;

            printf("Fornecedor chegou: Voce recebeu %d barras no aco %d.\n", qtd_chegou, aco_desejado);
            printf("-> Novo saldo na prateleira: %d barras.\n\n", atual->quantidade);

            return;
        }
        atual = atual->proximo;
    }

    printf("Erro: O fornecedor entregou o aco %d, mas nao tem prateleira para esse aco!\n", aco_desejado);
}

void usarAco(No *topo, int aco_desejado, int qtd_gasta){
    No *atual = topo;

    while (atual != NULL){
        if(atual->id_aco == aco_desejado){
            if (atual->quantidade >= qtd_gasta) {
                atual->quantidade = atual->quantidade - qtd_gasta;

                printf("Forja Ligada: Voce gastou %d barras no aco %d.\n", qtd_gasta, aco_desejado);
                printf("-> Novo saldo na prateleira: %d barras.\n\n", atual->quantidade);
        } else{
            
                printf("Erro na Forja: Voce tentou gastar %d barras do aco %d, mas so temos %d na prateleira!\n\n", qtd_gasta, aco_desejado, atual->quantidade);
        }

                return;
            }
            atual = atual->proximo;
    }

    printf("Erro: aco %d nao existe no estoque para ser usado!\n", aco_desejado);
}

int main() {
    No *estoque = NULL; 

    estoque = adicionarAco(estoque, 1095, 10);
    estoque = adicionarAco(estoque, 5160, 5);
    estoque = adicionarAco(estoque, 1520, 2);    

    int aco_procurado = 1095; 
    int encontrou = 0;        
    int qtd_encontrada = 0;

    No *atual = estoque; 
    while (atual != NULL){
        if(atual->id_aco == aco_procurado){
            encontrou = 1;
            qtd_encontrada = atual->quantidade;
            break;
        }
        atual = atual->proximo;
    }

    printf("\n--- RESULTADO DA BUSCA ---\n");
    if(encontrou == 1) {
        printf("Otimo! O aco %d esta no estoque. Temos %d barras disponiveis. Pode ligar a forja!\n", aco_procurado, qtd_encontrada);
    } else {
        printf("Putz, o aco %d acabou. Vai ter que encomendar mais.\n", aco_procurado);
    }

    printf("\n--- HORA DE TRABALHAR ---\n");

    usarAco(estoque, 1095, 1);

    usarAco(estoque, 5160, 3);

    usarAco(estoque, 1520, 5);

    receberEntrega(estoque, 1095, 4);

    receberEntrega(estoque, 1520, 7);

    return 0;
}