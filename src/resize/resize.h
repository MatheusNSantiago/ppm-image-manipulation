#if !defined(RESIZE_H)
#define RESIZE_H
#include "../utils/utils.h"
#include <stdlib.h>

void ampliar(RGB ***M, int w, int h, int fator,char saida[]);

void reduzir(RGB **M, int w, int h, int fator,char saida[]);

#endif // RESIZE_H
