#include <stdio.h>

void imprimir(int n) {
    if (n == 0) {
        // caso base: não faz nada
        return;
    } else {
        imprimir(n - 1);   // chamada recursiva
        printf("%d ", n);  // ação após a chamada
    }
}

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);

    imprimir(num);  // chama a função recursiva
    printf("\n");

    return 0;
}
