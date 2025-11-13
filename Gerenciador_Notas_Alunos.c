#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    double *notas;
    int qtdNotas;
} Alunos;


    double ValorFinal(Alunos *turma, int n){
        if(n == 0)
            return 0;

           double somaAluno = 0;
           for(int i = 0; i < turma [n-1].qtdNotas; i++){
                somaAluno += turma[n-1].notas[i];
           } 

            return somaAluno + ValorFinal(turma, n-1);           

    }   

int main(){

    int n;

    printf("Numero de alunos para calcular a media da turma:\n");
    scanf("%d", &n);

    Alunos *turma;
    turma = (Alunos*) malloc(n* sizeof(Alunos));

    if(turma == NULL){
    printf("Erro de alocacao!\n");
    return 1;
    }


    for(int i = 0; i < n; i++){

        printf("Nome do %dº aluno(a): ", i+1);
        scanf("%s", turma[i].nome);

        printf("Quantas notas o aluno(a) teve?\n");
        scanf("%d", &turma[i].qtdNotas);

        turma[i].notas = malloc(turma[i].qtdNotas * sizeof(double));

        printf("As notas de %s foram:\n", turma[i].nome);

            for(int j = 0; j < turma[i].qtdNotas; j++){
        scanf("%lf", &turma[i].notas[j]);

        }       
        
    }

    double somaTotal = ValorFinal(turma, n);

    int totalNotas = 0;
    for(int i = 0; i < n; i++){
        totalNotas += turma[i].qtdNotas;
    }

    double media = somaTotal / totalNotas;

    printf("A media da turma foi: %.2lf\n", media);

    for(int i = 0; i < n; i++){
        free(turma[i].notas);
    }

    free(turma);

    return 0;
}