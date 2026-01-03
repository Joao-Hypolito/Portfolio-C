#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int x;
    int y;

}generica;

void mover(generica *p){

    int dx; 
    int dy;
    int escolha;


    printf("Digite 1 para alterar o valor de X\n");
    printf("Digite 2 para alterar o valor de Y\n");   
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            printf("Quanto voce quer adicionar em X?\n");
            scanf("%d", &dx);
            p->x += dx;
        break;

        case 2:
            printf("Quanto voce quer adicionar em Y?\n");
            scanf("%d", &dy);
            p->y += dy;
        break;
    }

    printf("O personagem andou! Nova posicao: X=%d / Y=%d\n", p->x, p->y);
    }


void invertaSinal(generica *p){

    p->x *= (-1);
    p->y *= (-1);

    printf("Valor negativo de X: %d\n", p->x);
    printf("Valor negativo de Y: %d\n", p->y);

    printf("\n");

}

void atribuirValor(generica *p){

    printf("Digite o valor de X:\n");
    scanf("%d", &(p->x));
    printf("\n");
    printf("Digite o valor de Y\n");
    scanf("%d", &(p->y));

    printf("\n");

    printf("Valor de X: %d / Valor de Y: %d\n", p->x, p->y);

    printf("\n");

}

void alterarValor(generica *p){

    int aux;

    printf("Valor de X antes: %d\n", p->x);
    printf("Valor de Y antes: %d\n", p->y);
    
    aux = p->x;
    p->x = p->y;
    p->y = aux; 

    printf("\n");

    printf("Valor de X depois: %d\n", p->x);
    printf("Valor de Y depois: %d\n", p->y);    

    printf("\n");

}


int main(){

    generica g1;
    generica *p;
 
    p = &g1;

    p->x = 0;
    p->y = 0;

    int rodando = 1;
    int jaDefiniu = 0;
    int escolha; 

        while(rodando == 1){
            printf("Digite 1 para adicionar valores a X e Y\n");
            printf("Digite 2 para alterar os valores\n");
            printf("Digite 3 para inverter os sinais\n");
            printf("Digite 4 para mover as posicoes de X e Y\n");
            printf("Digite 5 para encerrar o programa\n");
            scanf("%d", &escolha);

            if(escolha > 5){
                printf("Por favor selecione uma das opcoes disponiveis\n");
                continue;
            }
            if(jaDefiniu == 0 && escolha > 1 && escolha < 5){
                printf("Voce ainda nao selecionou os valores de X e Y\n");
                continue;
            }

            if(jaDefiniu == 1 && escolha == 1){
                printf("Voce ja definiu os valores dos numeros\n");
                continue;
            }

                switch(escolha){
                    case 1:
                        atribuirValor(p);
                        jaDefiniu = 1;
                    break;

                    case 2:
                        alterarValor(p);
                    break;
                    
                    case 3:
                        invertaSinal(p);
                    break;
                    
                    case 4:
                        mover(p);
                    break;

                    case 5:
                        rodando = 0;
                }
                
                
        }

    return 0;
}