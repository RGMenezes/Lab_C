#include <stdio.h>

int main(void)
{
    int idade;
    float altura;

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    // Em scanf, usamos o operador & para passar o endereço de memória
    // da variável. Assim, a função consegue armazenar o valor lido.

    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    printf("\nResumo dos dados informados:\n");
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f m\n", altura);

    return 0;
}
