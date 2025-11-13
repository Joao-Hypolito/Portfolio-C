#include <stdio.h>

void dobrar(int * n){
    *n = *n * 2;
}

int main() {
    int x = 10;

    printf("Antes: %d\n", x);
    dobrar(&x);
    printf("Depois: %d\n", x);



    /*
    int *p = &x;
    int **pp = &p;
    
    printf("Valor de x: %d\n", x);
    printf("Endereco de x (&x): %p\n", &x);
    printf("Valor de p (endereco armazenado em p): %p\n", p);
    printf("Valor apontado por p (*p): %d\n", *p);
    printf("Valor de pp (endereco de p): %p\n", pp);
    printf("Valor apontado por pp (**pp): %d\n", **pp);
    

    
    printf("Antes: x = %d\n", x);

    *p = 99; // altera o valor de x atráves do ponteiro

    printf("Depois: x = %d\n", x);
    printf("Valor apontado por p (*p): %d\n", *p);
    */



    return 0;
}