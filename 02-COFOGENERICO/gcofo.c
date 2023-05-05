/*------------------------------------------------
cofo.c
Arquivo com a definição das funções do TAD Cofo
Genérico
---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "gcofo.h"

#ifndef _GCOFO_C_
#define _GCOFO_C_

#define TRUE 1
#define FALSE 0

gCofo *gcofCreate(int max_itens)
{
    gCofo *gc;
    if (max_itens > 0)
    {
        gc = (gCofo *)malloc(sizeof(gCofo));
        if (gc != NULL)
        {
            gc->item = (void **)malloc(sizeof(void *) * max_itens);
            if (gc->item != NULL)
            {
                gc->numItens = 0;
                gc->maxItens = max_itens;
                gc->cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}

int gcofDestroy(gCofo *gc)
{
    if (gc != NULL)
    {
        if (gc->numItens == 0)
        {
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int gcofInsert(gCofo *gc, void *item)
{
    if (gc != NULL)
    {
        if (gc->numItens < gc->maxItens)
        {
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *gcofGetFirst(gCofo *gc)
{
    void *elm;
    if (gc != NULL)
    {
        if (gc->numItens > 0)
        {
            elm = gc->item[0];
            gc->cur = 0;
            return elm;
        }
    }
    return NULL;
}

void *gcofGetNext(gCofo *gc)
{
    void *elm;
    if (gc != NULL)
    {
        if (gc->numItens > 0 && gc->cur < gc->numItens - 1)
        {
            gc->cur++;
            elm = gc->item[gc->cur];
            return elm;
        }
    }
    return NULL;
}

void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *a, void *b))
{
    int stat, i;
    if (gc != NULL)
    {
        if (gc->numItens > 0)
        {
            for (i = 0; i < gc->numItens; i++)
            {
                stat = cmp(gc->item[i], key);
                if (stat == TRUE)
                {
                    return gc->item[i];
                }
            }
        }
    }
    return NULL;
}

void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *))
{
    int i, j;
    void *data;
    int stat;
    if (c != NULL)
    {
        if (c->numItens > 0)
        {
            i = 0;
            stat = cmp(key, c->item[i]);
            while (i < c->numItens && stat != TRUE)
            {
                i++;
                stat = cmp((void *)key, (void *)c->item[i]);
            }
            printf("vai retornar n, fofa?", stat);
            if (stat == TRUE)
            {
                data = c->item[i];
                for (j = i; j < c->numItens; j++)
                {
                    c->item[j] = c->item[j + 1];
                }
                c->numItens--;
                return data;
            }
        }
        return NULL;
    }
}

int getNumItens(gCofo *gc)
{
    if (gc != NULL)
    {
        return gc->numItens;
    }
    return FALSE;
}

int gCofEmpty(gCofo *gc)
{
    if (gc != NULL)
    {
        gc->numItens = 0;
        return TRUE;
    }
    return FALSE;
}

#endif
