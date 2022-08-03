#include "resize.h"


void ampliar(RGB ***M, int w, int h, int fator,char saida[])
{
    FILE *fp;
    int newW, newH;
    RGB **newM;
    RGB aux;

    newW = w * fator;
    newH = h * fator;

    initMatrix(&newM, newW, newH);

    fp = fopen(saida, "wb");

    /* Escrever no arquivo */
    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n", newW, newH);
    fwrite("255\n", 4, 1, fp);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            aux = (*M)[i][j];
            for (int fi = 0; fi < fator; fi++)
                for (int fj = 0; fj < fator; fj++)
                    newM[(i * fator) + fi][(j * fator) + fj] = aux;
        }
    }

    for (int i = 0; i < newH; i++)
        for (int j = 0; j < newW; j++)
        {
            aux = newM[i][j];

            fwrite(&aux.R, sizeof(char), 1, fp);
            fwrite(&aux.G, sizeof(char), 1, fp);
            fwrite(&aux.B, sizeof(char), 1, fp);
        }

    fclose(fp);
    for (int i = 0; i < newH; i++)
    {
        free(newM[i]);
    }
    free(newM);
}

void reduzir(RGB **M, int w, int h, int fator,char saida[])
{
    
    FILE *fp;
    int newW, newH;
    RGB sum;
    fp = fopen(saida, "wb");

    newW = w % fator==0?w/fator:w/fator+1  ;
    newH = h % fator==0?h/fator:h/fator+1 ;

    /* Escrever no arquivo */
    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n", newW, newH);
    fwrite("255\n", 4, 1, fp);
    for (int i =0; i < h; i+=fator){
        for (int j = 0; j < w; j+=fator)
        {
            sum.R=0;
            sum.G=0;
            sum.B=0;
            for (int k = 0; k < fator && k+i < h; k++)
                for (int n = 0; n < fator && n+j<w; n++)
                {
                    sum.R+=M[i+k][j+n].R;
                    sum.G+=M[i+k][j+n].G;
                    sum.B+=M[i+k][j+n].B;
                }
        sum.R/=(fator*fator);
        sum.G/=(fator*fator);
        sum.B/=(fator*fator);
        fwrite(&sum.R, sizeof(char), 1, fp);
        fwrite(&sum.G, sizeof(char), 1, fp);
        fwrite(&sum.B, sizeof(char), 1, fp);
        fflush(fp);
        }
    }
    fclose(fp);
}