#ifndef __COFO_H
#define __COFO_H

typedef struct _cofo_ Cofo;

Cofo *cofCreate(int maxItems);
int cofInsert(Cofo *c, int item);
int cofRemove(Cofo *c, int key);
int cofQuery(Cofo *c, int key);
int cofDestroy(Cofo *c);
void cofShow(Cofo *c);

#endif
