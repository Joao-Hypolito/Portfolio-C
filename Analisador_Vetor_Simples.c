#include <stdio.h>
#include <stdlib.h>

    void leValores(int *v, int x){
        printf("Digite %d valor(es):\n", x);

        for(int i = 0; i < x; i++){
            scanf("%d", &v[i]);
        }
    }

    void mostraParidade(int *v, int x){
        for(int i = 0; i < x; i++){
            if(v[i] % 2 == 0){
                printf("O numero: %d e par\n", v[i]);
            }else{
                printf("O numero: %d e impar\n", v[i]);
            }
        }
    }

    int contaPares(int *v, int x){
        int pares = 0;
        for(int i = 0; i < x; i++){
            if(v[i] % 2 == 0){
                pares ++;
            }
        }
        return pares;
    }

    int maiorValor(int *v, int x){
        int maior = v[0];
        for(int i = 0; i < x; i++){
            if(maior < v[i]){
                maior = v[i];
            }            
        }
        return maior;
    }

    int menorValor(int *v, int x){
        int menor = v[0];
        for(int i = 0; i < x; i++){
            if(menor > v[i]){
                menor = v[i];
            }            
        }
        return menor;
    }

int main(){

    int x;
    int *valores;

        printf("Digite um valor:\n");
        scanf("%d", &x);

        printf("\n");

    valores = (int*) malloc(x * sizeof(int));
    if(valores == NULL){
        printf("Erro de alocacao de memoria\n");
        return 1;
    }

        leValores(valores, x);
        mostraParidade(valores, x);
        int pares = contaPares(valores, x);
        int maior = maiorValor(valores, x);
        int menor = menorValor(valores, x);

        printf("\n");
        printf("Quantidade de numeros pares: %d\n", pares);

        printf("\n");
        printf("O maior valor: %d\n", maior);

        printf("\n");
        printf("O menor valor: %d\n", menor);

    free(valores);  

    return 0;
}

