#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cofo.h"

#define TRUE 1
#define FALSE 0

// cd 01-TADCOFO
// gcc apl.c cofo.c -o apl
// ./apl

// DECLARAÇÃO DAS FUNÇÕES AUXILIARES
int chamaCofDestroy(Cofo *meuCofo);
void chamaCofInsert(Cofo *meuCofo);
void chamaCofQuery(Cofo *meuCofo);
void chamaCofRemove(Cofo *meuCofo);

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Cofo *meuCofo;
    int opcao = 0, cofoCriado = FALSE, tamanhoCofo;

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
                    printf("Cofo criado com SUCESSO!");
                    cofoCriado = TRUE;
                }
                else
                {
                    printf("\nNão foi possível criar seu cofo, tente novamente mais tarde :( !");
                }
            }
            else
            {
                printf("\nVocê já possui um cofo criado. Divirta-se com as operações do seu cofo!");
            }
            break;

        case 2:
            if (cofoCriado)
            {
                cofoCriado = chamaCofDestroy(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 3:
            if (cofoCriado)
            {
                chamaCofInsert(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 4:
            if (cofoCriado)
            {
                chamaCofQuery(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
            }
            break;

        case 5:
            if (cofoCriado)
            {
                chamaCofRemove(meuCofo);
            }
            else
            {
                printf("\nATENÇÃO: antes de utilizar as operações você deve primeireiramente criar um cofo!");
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

// FUNÇÕES AUXILIARES
int chamaCofDestroy(Cofo *meuCofo)
{
    int sucesso;
    sucesso = cofDestroy(meuCofo);
    if (sucesso)
    {
        printf("\nCofo Destruído!");
        return FALSE;
    }
    else
    {
        printf("\nNão foi possível destruir o cofo, tente novamente!");
        return TRUE;
    }
}

void chamaCofInsert(Cofo *meuCofo)
{
    int sucesso, elemento;
    printf("\nDigite o elemento que você deseja inserir no cofo: ");
    scanf("%d", &elemento);

    sucesso = cofInsert(meuCofo, elemento);
    if (sucesso)
    {
        printf("\nO elemento %d foi inserido com sucesso!", elemento);
    }
    else
    {
        printf("\nNão foi possível inserir o elemento %d no cofo!", elemento);
    }
}

void chamaCofQuery(Cofo *meuCofo)
{
    int elemento, sucesso;

    printf("\nDigite o elemento que você deseja saber se está no cofo: ");
    scanf("%d", &elemento);

    sucesso = cofQuery(meuCofo, elemento);
    if (sucesso)
    {
        printf("\nO elemento %d está no cofo!", elemento);
    }
    else
    {
        printf("\nO elemento %d não está no cofo!", elemento);
    }
}

void chamaCofRemove(Cofo *meuCofo)
{
    int elemento, sucesso;

    printf("\nDigite o elemento que você deseja retirar do cofo: ");
    scanf("%d", &elemento);
    sucesso = cofRemove(meuCofo, elemento);
    if (sucesso)
    {
        printf("\nItem removido com sucesso!");
    }
    else
    {
        printf("\nNão foi possível remover o item do cofo!");
    }
}