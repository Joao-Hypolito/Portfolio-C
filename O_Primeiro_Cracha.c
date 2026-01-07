#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    char classe[50];
    int nivel;
}Personagem;

int main(){

    Personagem p1;
    int escolha;

    printf("Escolha o nome do personagem:\n");
    fgets(p1.nome, 50, stdin);

    p1.nome[strcspn(p1.nome, "\n")] = 0;

    do{
        printf("Escolha a classe:\n");
        printf("opcao 1: Tatico /");
        printf(" opcao 2: Vanguarda /");
        printf(" opcao 3: Baluarte\n");
        scanf("%d", &escolha);

        if(escolha > 3){
            printf("Opcao Invalida!\n");
            continue;
        }

    } while (escolha < 1|| escolha > 3);

            switch(escolha){
        case 1:
            strcpy(p1.classe, "Tatico");    
        break;       

        case 2:
            strcpy(p1.classe, "Vanguarda");    
        break;  

        case 3:
            strcpy(p1.classe, "Baluarte");    
        break;  
    }

    printf("Escolha o nivel do personagem:\n");
    scanf("%d", &p1.nivel);

    printf("\n");

    printf("Heroi criado com sucesso!\n");
    printf("Nome do Heroi: %s!\n", p1.nome);
    printf("Classe do Heroi: %s!\n", p1.classe);
    printf("Nivel do Heroi: %d!\n", p1.nivel);

    return 0;
}