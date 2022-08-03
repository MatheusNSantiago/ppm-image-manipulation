#include <stdio.h>
#include <string.h>
#include "./utils/utils.h"
#include "./resize/resize.h"
#include "./rotate/rotate.h"
#include "./gray-scale/gray.h"
#include "./color-inversion/inversion.h"
#include "./remove-color/colorRemove.h"
#include "./filter/filtro.h"
void liberar_memoria(RGB**M,int h);
int main(int argc, char *argv[])
{
    FILE *fp;
    RGB **M;  /* Matriz */
    int w, h; /* Dimensões da matriz */

    fp = fopen(argv[1], "rb");
    getDimensions(&w, &h, fp);
    /* Matriz da imagem original */
    initMatrix(&M, w, h);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            M[i][j] = getRGB(fp);
    if (strcasecmp(argv[2],"amp")==0)
        ampliar(&M,w,h,atoi(argv[3]),argv[4]);
    else if (strcasecmp(argv[2],"red")==0)
        reduzir(M,w,h,atoi(argv[3]),argv[4]);
    else if (strcasecmp(argv[2],"rot")==0)
        rotacao(M,w,h,atoi(argv[3]),argv[4]);
    else if (strcasecmp(argv[2],"cinza")==0)
        scale(M,w,h,argv[3]);
    else if (strcasecmp(argv[2],"inverte")==0)
        invert(h,w,M,argv[3]);
    else if  (strcasecmp(argv[2],"remove")==0)
        colorRemove(h,w,M,retorna_cor(argv[3]),argv[4]);
    else if  (strcasecmp(argv[2],"filtro")==0)
        filtro(M,w,h,argv[3]);
    fclose(fp);
    liberar_memoria(M,h);
    return 0;
}

void liberar_memoria(RGB**M,int h)
{
    for (int i = 0; i < h; i++)
        free(M[i]);
    free(M);    
}