#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cofo.h"

#define TRUE 1
#define FALSE 0

// cd 01-TADCOFO
// gcc apl.c cofo.c -o apl
// ./apl

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Cofo *meuCofo;
    int opcao = 0, cofoCriado = FALSE, sucesso, tamanhoCofo, elemento;

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
                printf("\nVAMOS CRIAR SEU COFO!");
                printf("\nDigite o tamanho do cofo: ");
                scanf("%d", &tamanhoCofo);
                meuCofo = cofCreate(tamanhoCofo);
                if (meuCofo != NULL)
                {
                    cofoCriado = TRUE;
                }
                else
                {
                    printf("\nN�o foi poss�vel criar seu cofo, tente novamente mais tarde :( !\n");
                }
            }
            else
            {
                printf("\nVoc� j� possui um cofo criado. Divirta-se com as opera��es do seu cofo!\n");
            }
            printf("%d", cofoCriado);
            break;
        case 2:
            sucesso = cofDestroy(meuCofo);
            if (sucesso)
            {
                printf("Cofo Destruído!");
                cofoCriado = FALSE;
            }
            else
            {
                printf("Não foi possível destruir o cofo, tente novamente!");
            }
            break;
        case 3:
            printf("Digite o elemento que você deseja inserir no cofo: ");
            scanf("%d", &elemento);
            sucesso = cofInsert(meuCofo, elemento);
            if (sucesso)
            {
                printf("O elemento %d foi inserido com sucesso!", elemento);
            }
            else
            {
                printf("Não foi possível inserir o elemento %d no cofo!", elemento);
            }
            break;
        case 4:
            printf("Digite o elemento que você deseja saber se está no cofo: ");
            scanf("%d", &elemento);
            sucesso = cofQuery(meuCofo, elemento);
            if (sucesso)
            {
                printf("O elemento &d está no cofo!", elemento);
            }
            else
            {
                printf("O elemento %d não está no cofo!", elemento);
            }
            break;
        case 5:
            printf("Digite o elemento que você deseja retirar do cofo: ");
            scanf("%d", elemento);
            sucesso = cofRemove(meuCofo, elemento);
            if (sucesso)
            {
                printf("Item removido com sucesso!");
            }
            else
            {
                printf("Não foi possível remover o item do cofo!");
            }
            break;
        case 6:
            printf("\n\nObrigado por utilizar meu programa :) !!\n\n");
            break;
        default:
            printf("\n\nAtenção: digite um dígito válido!\n\n");
        }

    } while (opcao != 6);
}
