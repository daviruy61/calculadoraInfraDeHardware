#include <stdio.h>

int main() {
    int escolha, numero;
    float numero_real;

    printf("Calculadora Programador Didática\n");
    printf("Escolha a conversão desejada:\n");
    printf("1 - Base 10 para Base 2\n");
    printf("2 - Base 10 para Base 8\n");
    printf("3 - Base 10 para Base 16\n");
    printf("4 - Base 10 para Código BCD\n");
    printf("5 - Base 10 para Complemento a 2 (16 bits)\n");
    printf("6 - Real para Float e Double\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Digite um número decimal: ");
            scanf("%d", &numero);
            base10_para_base2(numero);
            break;
        case 2:
            printf("Digite um número decimal: ");
            scanf("%d", &numero);
            base10_para_base8(numero);
            break;
        case 3:
            printf("Digite um número decimal: ");
            scanf("%d", &numero);
            base10_para_base16(numero);
            break;
        case 4:
            printf("Digite um número decimal: ");
            scanf("%d", &numero);
            base10_para_bcd(numero);
            break;
        case 5:
            printf("Digite um número decimal: ");
            scanf("%d", &numero);
            base10_para_complemento2(numero);
            break;
        case 6:
            printf("Digite um número real: ");
            scanf("%f", &numero_real);
            real_para_float_double(numero_real);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}
