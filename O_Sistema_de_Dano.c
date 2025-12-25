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

    int dano;
    int cura;

    printf("Vida antes da batalha: %d\n", heroi.vida);    

    printf("Quanto de dano o heroi recebeu?\n");
    scanf("%d", &dano);
    
    tomarDano(p, dano); 

    printf("Vida depois de tomar %d de dano: %d\n",dano, heroi.vida);

    printf("Quanto de cura o heroi recebeu?\n");
    scanf("%d", &cura);    

    receberCura(p, cura);

    printf("Vida depois de receber %d de cura: %d\n",cura, heroi.vida);

    if (heroi.vida <= 0) {
        printf("O heroi caiu!\n");
    }

    int id_alvo;

    printf("\n--- HORA DO ATAQUE ---\n");
    printf("Quem o %s vai atacar? (0: Goblin, 1: Orc, 2: Troll): ", heroi.nome);
    scanf("%d", &id_alvo);

    if(id_alvo >= 0 && id_alvo < 3){
        printf("Pow! Voce atacou o %s\n", inimigos[id_alvo].nome);

        int dano_final = heroi.forca + (rand() % 6);

        printf("Atacando com forca %d + dado... Total: %d!\n", heroi.forca, dano_final);
        tomarDano(&inimigos[id_alvo], dano_final);

        printf("O %s gritou de dor! Vida restante: %d\n", inimigos[id_alvo].nome, inimigos[id_alvo].vida);
    } else {
        printf("Voce atacou o vento! (Alvo invalido)\n");
    }

    int i;
    for(i = 0; i < 3; i++) {
        printf("Monstro %s | Vida: %d\n", inimigos[i].nome , inimigos[i].vida);
    }

    return 0;
}