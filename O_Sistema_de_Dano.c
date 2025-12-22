#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[20];
    int vida;
    int defesa;
} Personagem;

void inicializar(Personagem *p, char *n, int v, int d) {
    
    strcpy(p->nome, n);
    p->vida = v;
    p->defesa = d;
}

void tomarDano(Personagem *p, int dano) {

    p->vida = p->vida - dano;
}

void receberCura(Personagem *p, int cura){

    p->vida = p->vida + cura;

    if(p->vida > 100){
        p->vida = 100;
    }
}

int main() {

    srand(time(NULL));

    Personagem heroi;

    inicializar(&heroi, "Heroi", 100, 10);

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

        int forca_ataque = (rand() % 20) + 1;

        printf("Rolando dados... Dado Gerado: %d!\n", forca_ataque);
        tomarDano(&inimigos[id_alvo], forca_ataque);

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