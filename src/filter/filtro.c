#include "filtro.h"

void filtro(RGB **M,int w, int h,char saida[])
{
    FILE *fp;
    fp = fopen(saida, "wb");
    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n", w, h);
    fwrite("255\n", 4, 1, fp);
    int w2 = (w)/2;
    int h2 = (h)/2;
    for (int i = h2+1; i < h; i++)//Imprimi a parte de cima
    {
        for (int j = w2+1; j < w; j++)// 2x2 
        {
            RGB aux = M[i][j];
            fwrite(&aux.R,sizeof(char),1,fp);
            fwrite(&aux.G,sizeof(char),1,fp);
            fwrite(&aux.B,sizeof(char),1,fp);
        }
        for (int j = 0; j <= w2; j++)
        {
            RGB aux = M[i][j];
            fwrite(&aux.R,sizeof(char),1,fp);
            fwrite(&aux.G,sizeof(char),1,fp);
            fwrite(&aux.B,sizeof(char),1,fp);
        }
    }
    for (int i = 0; i <= h2; i++)//Imprimi a parte de cima
    {
        for (int j = w2+1; j < w; j++)// 2x2 
        {
            RGB aux = M[i][j];
            fwrite(&aux.R,sizeof(char),1,fp);
            fwrite(&aux.G,sizeof(char),1,fp);
            fwrite(&aux.B,sizeof(char),1,fp);
        }
        for (int j = 0; j <= w2; j++)
        {
            RGB aux = M[i][j];
            fwrite(&aux.R,sizeof(char),1,fp);
            fwrite(&aux.G,sizeof(char),1,fp);
            fwrite(&aux.B,sizeof(char),1,fp);
        }
    }
    fclose(fp);
}