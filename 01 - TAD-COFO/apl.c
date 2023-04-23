#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

#define TRUE 1
#define FALSE 0

// gcc apl.c cofo.c -o apl
//./apl

int main(void)
{
    Cofo *meuCofo;
    int opcao = 0, cofoCriado = FALSE, sucesso = FALSE, tamanhoCofo;

    do
    {
        printf("\n\n|------------------------------------------------|\n");
        printf("|                      MENU                      |\n");
        printf("|------------------------------------------------|\n");
        printf("|| 1. Criar o cofo\n");
        printf("|| 2. Destruir o cofo\n");
        printf("|| 3. Inserir um elemento no cofo\n");
        printf("|| 4. Verificar se um elemento está no cofo\n");
        printf("|| 5. Remover um elemento do cofo\n");
        printf("|| 6 - Sair\n");
        printf("||- Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (cofoCriado == FALSE)
            {
                printf("\nDigite o tamanho do cofo: ");
                scanf("%d", &tamanhoCofo);
                meuCofo = cofCreate(tamanhoCofo);
                if (meuCofo != NULL)
                {
                    cofoCriado = TRUE;
                }
                else
                {
                    printf("\nNão foi possível criar seu cofo, tente novamente mais tarde :( !\n");
                }
            }
            else
            {
                printf("\nVocê já possui um cofo criado. Divirta-se com as operações do seu cofo!\n");
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("\n\nAtenção: digite um dígito válido!\n\n");
        }
    } while (opcao != 6);

    printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
}