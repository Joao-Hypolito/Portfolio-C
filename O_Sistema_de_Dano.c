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

void inicializar(Personagem *p, char nome[], int v, int f) {
    
    strcpy(p->nome, nome);
    p->vida = v;
    p->max_vida = v;

    p->forca = f;

    p->defesa = 0;
}

void tomarDano(Personagem *p, int dano) {

    p->vida = p->vida - dano;

    if(p->vida < 0){
        p->vida = 0;
    }
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
                break;

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

void AtaqueInimigos(Personagem *heroi, Personagem inimigos[]){

    printf("\n---TURNO DOS INIMIGOS---\n");

    for(int i = 0; i < 3; i++){
        if(inimigos[i].vida > 0){

            int dano = inimigos[i].forca + (rand() % 4);

            printf("O %s atacou voce!\n", inimigos[i].nome);

            tomarDano(heroi, dano);

            printf("Voce tomou %d de dano. Vida restante: %d/%d\n", dano, heroi->vida, heroi->max_vida);
            printf("\n");

        }
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
        printf("\n");
        printf("Onde quer investir?\n");
        printf("\n");
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

    int batalha_continua = 1;

    while(batalha_continua == 1) {

        printf("/n--- SITUACAO DA BATALHA ---\n");
        printf("Heroi: %d/%d HP\n", heroi.vida, heroi.max_vida);
        for(int i = 0; i < 3; i++){
            if(inimigos[i].vida > 0){
                printf("[%d] %s: %d HP\n", i, inimigos[i].nome, inimigos[i].vida);
            } else{
                printf("[%d] %s: DERROTADO!\n", i, inimigos[i].nome);
            }
        }
        OpcoesDeAtaque(p, inimigos);

        int inimigos_vivos = 0;
        for(int i = 0; i < 3; i++){
            if(inimigos[i].vida > 0){
                inimigos_vivos++;
            }
        }

        if(inimigos_vivos == 0){
            printf("\n--- VITORIA! TODOS OS INIMIGOS FORAM DERROTADOS! ---\n");
            batalha_continua = 0;
            break;
        }

        AtaqueInimigos(p, inimigos);

        if(heroi.vida <= 0) {
            printf("\nO heroi caiu em combate!");
            batalha_continua = 0;
        }
    }

    return 0;
}