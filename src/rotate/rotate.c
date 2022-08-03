#include "rotate.h"

static void rotacao_90(FILE* fp,RGB **M, int w, int h);
static void rotacao_180(FILE* fp,RGB **M, int w, int h);
static void rotacao_270(FILE* fp,RGB **M, int w, int h);


void rotacao(RGB **M, int w, int h, int angulo,char saida[])
{
    FILE *fp;
    fp = fopen(saida, "wb");
    switch (angulo)
    {
    case 90:
        rotacao_90(fp,M,w,h);
        break;
    case 180:
        rotacao_180(fp,M,w,h);
        break;
    case 270:
        rotacao_270(fp,M,w,h);
        break;
    }
    fclose(fp);
}
static void rotacao_90(FILE* fp,RGB **M, int w, int h)
{
    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n", h, w);
    fwrite("255\n", 4, 1, fp);
    for (int j = w-1; j >=0 ; j--)
        for (int i = 0; i < h; i++)
        {
            RGB aux = M[i][j];
            fwrite(&aux.R,sizeof(char),1,fp);
            fwrite(&aux.G,sizeof(char),1,fp);
            fwrite(&aux.B,sizeof(char),1,fp);
        }
    
}
static void rotacao_180(FILE* fp,RGB **M, int w, int h)
{
    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n", w, h);
    fwrite("255\n", 4, 1, fp);
    for (int i = h-1; i >=0; i--)
        for (int j = w-1; j >=0 ; j--)
        {
            RGB aux = M[i][j];
            fwrite(&aux.R,sizeof(char),1,fp);
            fwrite(&aux.G,sizeof(char),1,fp);
            fwrite(&aux.B,sizeof(char),1,fp);
        }
}
static void rotacao_270(FILE* fp,RGB **M, int w, int h)
{
    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n", h, w);
    fwrite("255\n", 4, 1, fp);
    for (int j = 0; j < w ; j++)
        for (int i = h-1; i >=0; i--)
        {
            RGB aux = M[i][j];
            fwrite(&aux.R,sizeof(char),1,fp);
            fwrite(&aux.G,sizeof(char),1,fp);
            fwrite(&aux.B,sizeof(char),1,fp);
        }
}