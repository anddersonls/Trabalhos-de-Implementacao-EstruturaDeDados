#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

#ifndef _COFO_C_
#define _COFO_C_

#define TRUE 1
#define FALSE 0

typedef struct _cofo_
{
    int numItens;
    int maxItens;
    int *item;
} Cofo;

// retorna o cofo criado
Cofo *cofCreate(int maxItems)
{
    Cofo *c;

    if (maxItems > 0)
    {
        c = (Cofo *)malloc(sizeof(Cofo));

        if (c != NULL)
        {
            c->item = (int *)malloc(sizeof(int) * maxItems);

            if (c->item != NULL)
            {
                c->numItens = 0;
                c->maxItens = maxItems;
                return c;
            }

            free(c);
        }
    }

    return NULL;
}

// retorna TRUE ou FALSE
int cofDestroy(Cofo *c)
{
    if (c != NULL)
    {
        if (c->numItens == 0)
        {
            free(c->item);
            free(c);
            return TRUE;
        }
    }

    return FALSE;
}

// retorna TRUE ou FALSE
int cofInsert(Cofo *c, int item)
{
    if (c != NULL)
    {
        if (c->numItens < c->maxItens)
        {
            c->item[c->numItens] = item;
            c->numItens++;
            return TRUE;
        }
    }

    return FALSE;
}

// retorna TRUE ou FALSE
int cofQuery(Cofo *c, int key)
{
    int i, status;

    if (c != NULL)
    {
        if (c->numItens > 0)
        {
            i = 0;
            status = FALSE;
            while (i < c->numItens && status != TRUE)
            {
                if (c->item[i] == key)
                {
                    status = TRUE;
                }
                else
                {
                    i++;
                }
            }
            if (status == TRUE)
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

// retorna o element removido
int cofRemove(Cofo *c, int key)
{
    int i, j, status, aux;

    if (c != NULL)
    {
        if (c->numItens > 0)
        {
            i = 0;
            status = FALSE;

            while (i < c->numItens && status != TRUE)
            {
                if (c->item[i] == key)
                {
                    status = TRUE;
                }
                else
                {
                    i++;
                }
            }

            if (status == TRUE)
            {
                aux = c->item[i];

                for (j = i; j < c->numItens - 1; j++)
                {
                    c->item[j] = c->item[j + 1];
                }

                c->numItens--;
                return aux;
            }
        }
    }
}

#endif