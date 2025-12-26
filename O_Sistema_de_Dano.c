#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[20];
    char sexo;
    int vida;
    int max_vida;
    int defesa;
    int forca;
} Personagem;

void inicializar(Personagem *p, char *n, int v, int d) {
    
    strcpy(p->nome, n);
    p->vida = v;
    p->max_vida = v;
    p->defesa = d;
}

void tomarDano(Personagem *p, int dano) {

    p->vida = p->vida - dano;
}

void receberCura(Personagem *p, int cura){

    p->vida = p->vida + cura;

    if(p->vida > p->max_vida){
        p->vida = p->max_vida;
    }
}

void OpcoesDeAtaque(Personagem *p, Personagem inimigos[]){

    int escolha;
    int id_alvo;

        printf("\n---SEU TURNO---\n");
        printf("1. Ataque básico\n");
        printf("2. Curar\n");
        printf("3. Intimidar\n");
        printf("4. Ataque Perfurante\n");
        printf("Escolha seu proximo movimento: \n");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                printf("Atacar quem? (0: Goblin, 1: Orc, 2: Troll): ");
                scanf("%d", &id_alvo);

                if(id_alvo >= 0 && id_alvo < 3){
                    int dano_final = p->forca + (rand() % 6);
                printf("Voce atacou com forca %d! Dano total: %d\n", p->forca, dano_final); 
                
                    tomarDano(&inimigos[id_alvo], dano_final);
                printf("Vida do %s caiu para %d.\n", inimigos[id_alvo].nome, inimigos[id_alvo].vida);               
                } else {
                    printf("Voce errou o alvo!\n");
                }

            case 2: {
                int valor_cura = 30;
                
                receberCura(p, valor_cura);

                printf("Voce bebeu uma pocao! Vida atual: %d / %d\n", p->vida, p->max_vida);
                break;
            }    
            case 3:    
                printf("Voce tentou intimidar, mas ainda nao aprendeu essa habilidade...\n");
                break;

            case 4:
                printf("Voce tentou furar a armadura, mas falhou...\n");
                break;
                
            default:
                printf("Voce tropecou e perdeu a vez!\n");
                break;
    }

}

void criarHeroi(Personagem *p){
    printf("--- CRIACAO DE PERSONAGEM ---\n");
    printf("Digite o nome do heroi: ");
    scanf("%s", p->nome);

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &p->sexo);

    int pontos = 10;
    int escolha;
    int qtd;

    p->vida = 100;
    p->defesa = 40;
    p->forca = 35;


    while(pontos > 0){
        printf("\nVoce tem %d pontos para distribuir.\n", pontos);
        printf("Atributos Atuais -> Vida: %d | Defesa: %d | Forca: %d\n", p->vida, p->defesa, p->forca);
        printf("Onde quer investir?\n");
        printf("1. Vida (+10 por ponto)\n");
        printf("2. Defesa (+1 por ponto)\n");
        printf("3. Forca (+1 por ponto)\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        printf("Quantos pontos quer gastar nisso? ");
        scanf("%d", &qtd);

        if(qtd > pontos){
            printf("Voce nao tem mais pontos suficientes!\n");
        }else if(qtd <= 0){
            printf("Valor invalido!\n");
        }else{
            pontos = pontos - qtd;

        switch(escolha){
            case 1:
                p->vida += (qtd * 10);
                break;
            case 2:
                p->defesa += qtd;
                break;
            case 3:
                p->forca += qtd;
                break;
            default:
                printf("Opcao invalida, pontos devolvidos.\n");
                pontos = pontos + qtd;
                break;
            }
        }
    }

    p->max_vida = p->vida;

    printf("\n--- PERSONAGEM CRIADO COM SUCESSO! ---\n");
}


int main() {

    srand(time(NULL));

    Personagem heroi;

    criarHeroi(&heroi);

    Personagem *p;
    p = &heroi;

    Personagem inimigos[3];   
    
    inicializar(&inimigos[0], "Goblin", 50, 5); // Monstro A
    inicializar(&inimigos[1], "Orc", 40, 3); // Monstro B
    inicializar(&inimigos[2], "Troll", 80, 8); // Monstro C

    OpcoesDeAtaque(p, inimigos);

    printf("\n---STATUS APOS SEU TURNO ---\n");
    for(int i = 0; i < 3; i++){
        printf("%s / Vida: %d\n", inimigos[i].nome, inimigos[i].vida);
    }

    return 0;
}