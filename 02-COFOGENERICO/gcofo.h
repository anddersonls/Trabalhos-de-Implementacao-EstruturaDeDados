/*---------------------------------------------------
Autor: Anderson Lopes Silva
May/2023
-------------------------------------------------*/

#ifndef __GCOFO_H_
#define __GCOFO_H_

typedef struct _gcofo_
{
    int numItens;
    int maxItens;
    int cur;
    void **item;
} gCofo;

gCofo *gcofCreate(int max_itens);
int gcofInsert(gCofo *gc, void *item);
void *gcofRemove(gCofo *gc, void *key, int (*cmp)(void *, void *));
void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *, void *));
void *gcofGetFirst(gCofo *gc);
void *gcofGetNext(gCofo *gc);
int gcofDestroy(gCofo *gc);
int getNumItens(gCofo *gc);
int gCofEmpty(gCofo *gc);

#endif
