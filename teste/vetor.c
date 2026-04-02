#include <stdio.h>

int main() {
    int v[4] = {2, 4, 6, 8};
    int i;
    int input;

    for (i = 0; i < 3; i++) {
        if(i == 0) {
            v[i] = v[i] * 2; // v[0] = v[0] + 0
        } else {
            v[i] = v[i] + v[i-1]; // v[i] = v[i] + v[i-1]
        }
    }

    printf("Digite um número para verificar se ele está presente no vetor: ");
    scanf("%d", &input);

    printf("Resultado input: %d", input);

    if(input >= 0 && input <= 3){
        printf("\nO número %d está presente no vetor v[%d] = %d\n", input, input, v[input]);

    } else {
        printf("\nO número %d não está presente no vetor.\n", input);
    }

    return 0;
}