/*------------------------------------------------
cofo.h
Arquivo com a especificação para o TAD Cofo,
tipo de dado para uma coleção de inteiros
---------------------------------------------------
Autor: Anderson Lopes Silva
April/2023
-------------------------------------------------*/

#ifndef __COFO_H
#define __COFO_H

typedef struct _cofo_ Cofo;

Cofo *cofCreate(int maxItems);
int cofInsert(Cofo *c, int item);
int cofRemove(Cofo *c, int key);
int cofQuery(Cofo *c, int key);
int cofDestroy(Cofo *c);
int *cofItems(Cofo *c);
int cofNumItems(Cofo *c);

#endif
