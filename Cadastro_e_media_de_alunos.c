#include <stdio.h>
#include <stdlib.h>

    typedef struct {
        char nome [50]; 
        int prova;
        int participacao;
    } Aluno;

int main(){

    int n;

    printf("Numero de alunos para calcular a média:\n");
    scanf("%d", &n);

    Aluno *turma;
    turma = (Aluno*) malloc(n* sizeof(Aluno));

    if(turma == NULL){
    printf("Erro de alocacao!\n");
    return 1;
}

    for(int i = 0; i < n; i++){
        printf("Nome do %dº aluno(a): ", i+1);
        scanf("%s", turma[i].nome);

        printf("Nota da prova de %s foi de:\n", turma[i].nome);
        scanf("%d", &turma[i].prova);

        printf("nota de participao do %s foi de:\n", turma[i].nome);
        scanf("%d", &turma[i].participacao);

        double media = (turma[i].prova + turma[i].participacao) / 2.0;

        if(media > 5){
            printf("%s foi aprovado(a)\n", turma[i].nome);
            printf("Nota final: %lf\n", media);
        }else{
            printf("%s foi reprovado(a)\n", turma[i].nome);
            printf("Nota final: %.2lf\n", media);            
        }
    }

    free(turma);

    return 0;
}




