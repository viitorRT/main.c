#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void limpar_nova_linha(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void palindromo() {
    char palavra[100], invertida[100];

    printf("\nDigite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    limpar_nova_linha(palavra);

    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        invertida[i] = palavra[len - 1 - i];
    }
    invertida[len] = '\0';

    if (strcmp(palavra, invertida) == 0) {
        printf("\nA palavra é um palíndromo.\n");
    } else {
        printf("\nA palavra NÃO é um palíndromo.\n");
    }
}

void sequencia_fibonacci() {
    int tamanho;
    printf("\nDigite a quantidade de termos da sequência de Fibonacci (1 a 50): ");
    scanf("%d", &tamanho);
    getchar();

    if (tamanho < 1) tamanho = 1;
    if (tamanho > 50) tamanho = 50;

    int a = 0, b = 1, c;
    printf("\nSequência de Fibonacci: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

void fatorial() {
    int n;
    printf("\nDigite um número para calcular o fatorial: ");
    scanf("%d", &n);
    getchar();

    if (n < 0) {
        printf("Fatorial não é definido para negativos.\n");
        return;
    }

    unsigned long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    printf("Fatorial de %d é: %llu\n", n, resultado);
}

void verificar_substring() {
    char palavra1[100], palavra2[100];

    printf("\nDigite a primeira palavra: ");
    fgets(palavra1, sizeof(palavra1), stdin);
    limpar_nova_linha(palavra1);

    printf("Digite a segunda palavra: ");
    fgets(palavra2, sizeof(palavra2), stdin);
    limpar_nova_linha(palavra2);

    if (strstr(palavra1, palavra2) != NULL) {
        printf("A segunda string está contida na primeira.\n");
    } else {
        printf("A segunda string NÃO está contida na primeira.\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("\n==== MENU DE EXERCÍCIOS ====\n");
        printf("1 - Sequência de Fibonacci\n");
        printf("2 - Fatoriais\n");
        printf("3 - Verificar Palíndromo\n");
        printf("4 - Verificar Substring\n");
        printf("0 - Sair\n");
        printf("Digite o número do exercício: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                sequencia_fibonacci();
                break;
            case 2:
                fatorial();
                break;
            case 3:
                palindromo();
                break;
            case 4:
                verificar_substring();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

int main() {
    setlocale(LC_ALL, "");
    menu();
    return 0;
}
int main() {
    setlocale(LC_ALL, "");
    menu();
    return 0;
}
