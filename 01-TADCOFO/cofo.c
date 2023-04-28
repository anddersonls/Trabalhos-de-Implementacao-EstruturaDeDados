#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
                c->maxItens = maxItems;
                c->numItens = 0;
                return c;
            }

            free(c);
        }
    }

    return NULL;
}

int cofDestroy(Cofo *c)
{
    if (c != NULL && c->numItens == 0)
    {
        free(c->item);
        free(c);
        return TRUE;
    }

    return FALSE;
}

int cofInsert(Cofo *c, int item)
{
    if (c != NULL && c->numItens < c->maxItens)
    {
        c->item[c->numItens] = item;
        c->numItens++;
        return TRUE;
    }

    return FALSE;
}

int cofQuery(Cofo *c, int key)
{
    int i, status;

    if (c != NULL && c->numItens > 0)
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

    return FALSE;
}

int cofRemove(Cofo *c, int key)
{
    int i, j, flag;
    if (c != NULL && c->numItens > 0)
    {
        i = 0;
        flag = FALSE;

        while (i < c->numItens && flag != TRUE)
        {
            if (c->item[i] == key)
            {
                flag = TRUE;
            }
            else
            {
                i++;
            }
        }

        if (flag == TRUE)
        {

            for (j = i; j < c->numItens - 1; j++)
            {
                c->item[j] = c->item[j + 1];
            }

            c->numItens--;
            return TRUE;
        }
    }

    return FALSE;
}

int cofShow(Cofo *c)
{
    if (c != NULL && c->numItens > 0)
    {
        for (int i = 0; i < c->numItens; i++)
        {
            printf("\nItem %d: %d", i + 1, c->item[i]);
        }
        return TRUE;
    }
    return FALSE;
}

#endif