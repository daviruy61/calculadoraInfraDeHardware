#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Davi Gomes Ferreira Ruy de Almeida, periodo 3 Turma A
// Data da ultima revisão de codigo: 30/08/2024 19h

// Função para converter de base 10 para base 2
void base10_para_base2(int numero) {
    printf("\nConvertendo %d para base 2:\n", numero);
    int resultado[32];
    int i = 0;
    
    while (numero > 0) {
        resultado[i] = numero % 2;
        printf("%d %% 2 = %d (resto)\n", numero, resultado[i]);
        numero = numero / 2;
        printf("%d / 2 = %d (quociente)\n", numero * 2, numero);
        i++;
    }
    
    printf("Resultado em base 2: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", resultado[j]);
    }
    printf("\n");
}

// Função para converter de base 10 para base 8
void base10_para_base8(int numero) {
    printf("\nConvertendo %d para base 8:\n", numero);
    int resultado[32];
    int i = 0;
    
    while (numero > 0) {
        resultado[i] = numero % 8;
        printf("%d %% 8 = %d (resto)\n", numero, resultado[i]);
        numero = numero / 8;
        printf("%d / 8 = %d (quociente)\n", numero * 8 + resultado[i], numero);
        i++;
    }
    
    printf("Resultado em base 8: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", resultado[j]);
    }
    printf("\n");
}

// Função para converter de base 10 para base 16
void base10_para_base16(int numero) {
    printf("\nConvertendo %d para base 16:\n", numero);
    char resultado[32];
    int i = 0;
    
    while (numero > 0) {
        int resto = numero % 16;
        if (resto < 10)
            resultado[i] = resto + '0';
        else
            resultado[i] = resto - 10 + 'A';
        printf("%d %% 16 = %d (resto)\n", numero, resto);
        numero = numero / 16;
        printf("%d / 16 = %d (quociente)\n", numero * 16 + resto, numero);
        i++;
    }
    
    printf("Resultado em base 16: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", resultado[j]);
    }
    printf("\n");
}

// Função para converter de base 10 para BCD (Codigo Decimal Codificado em Binário)
void base10_para_bcd(int numero) {
    printf("\nConvertendo %d para Codigo BCD:\n", numero);
    int digitos[10], i = 0;

    while (numero > 0) {
        digitos[i] = numero % 10;
        printf("%d %% 10 = %d (dígito)\n", numero, digitos[i]);
        numero = numero / 10;
        i++;
    }

    printf("Resultado em Codigo BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        int bcd = digitos[j];
        for (int k = 3; k >= 0; k--) {
            printf("%d", (bcd >> k) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

// Função para converter de base 10 para complemento a 2 (16 bits)
void base10_para_complemento2(int numero) {
    printf("\nConvertendo %d para complemento a 2 com 16 bits:\n", numero);

    for (int i = 15; i >= 0; i--) {
        printf("%d", (numero >> i) & 1);
    }
    printf("\n");
}

void real_para_float_double(float numero) {
    unsigned int bits;
    memcpy(&bits, &numero, sizeof(bits));

    unsigned int sinal = (bits >> 31) & 1;
    unsigned int expoente = (bits >> 23) & 0xFF;
    unsigned int fracao = bits & 0x7FFFFF;

    printf("\nConvertendo %f para formato float:\n", numero);
    printf("Sinal: %u\n", sinal);
    printf("Expoente: %u\n", expoente);
    printf("Expoente com vies (127): %d\n", expoente - 127);
    printf("fracao: %u\n", fracao);
}

int main() {
    int escolha, numero;
    float numero_real;

    printf("Calculadora Programador Didatico\n");
    printf("Escolha a conversao desejada:\n");
    printf("1 - Base 10 para Base 2\n");
    printf("2 - Base 10 para Base 8\n");
    printf("3 - Base 10 para Base 16\n");
    printf("4 - Base 10 para Codigo BCD\n");
    printf("5 - Base 10 para Complemento a 2 (16 bits)\n");
    printf("6 - Real para Float e Double\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Digite um numero decimal: ");
            scanf("%d", &numero);
            base10_para_base2(numero);
            break;
        case 2:
            printf("Digite um numero decimal: ");
            scanf("%d", &numero);
            base10_para_base8(numero);
            break;
        case 3:
            printf("Digite um numero decimal: ");
            scanf("%d", &numero);
            base10_para_base16(numero);
            break;
        case 4:
            printf("Digite um numero decimal: ");
            scanf("%d", &numero);
            base10_para_bcd(numero);
            break;
        case 5:
            printf("Digite um numero decimal: ");
            scanf("%d", &numero);
            base10_para_complemento2(numero);
            break;
        case 6:
            printf("Digite um numero real: ");
            scanf("%f", &numero_real);
            real_para_float_double(numero_real);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}
