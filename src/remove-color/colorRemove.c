#include "colorRemove.h"

/* Remove as cores RGB para cada argumento [r/g/b/rg/rb/gb] */
void colorRemove(int h, int w, RGB **M,int cor,char saida[])
{
    FILE *wb;
    wb = fopen(saida, "wb");
    fwrite("P6\n", 3, 1, wb);
    fprintf(wb, "%d %d\n", w, h);
    fwrite("255\n", 4, 1, wb);

    /*Remove cor */
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            /* Remove R */
            if (cor == 1)
            M[i][j].R = M[i][j].R - M[i][j].R;

            /* Remove G */
            else if (cor == 2)
            M[i][j].G = M[i][j].G - M[i][j].G;

            /* Remove B */
            else if (cor == 3)
            M[i][j].B = M[i][j].B - M[i][j].B;

            /* Remove R/G */
            else if (cor == 4)
            {
                M[i][j].R = M[i][j].R - M[i][j].R;
                M[i][j].G = M[i][j].G - M[i][j].G;
            }

            /* Remove R/B */
            else if (cor == 5)
            {
                M[i][j].R = M[i][j].R - M[i][j].R;
                M[i][j].B = M[i][j].B - M[i][j].B;
            }

            /* Remove G/B */
            else if (cor == 6)
            {
                M[i][j].G = M[i][j].G - M[i][j].G;
                M[i][j].B = M[i][j].B - M[i][j].B;
            }
        }
    }

    /*Imprime rgb */
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fwrite(&M[i][j].R, sizeof(char), 1, wb);
            fwrite(&M[i][j].G, sizeof(char), 1, wb);
            fwrite(&M[i][j].B, sizeof(char), 1, wb);
        }
    }
    fclose(wb);
}

int retorna_cor(char cor[2])
{
    int color;
    if (strcasecmp(cor,"r")==0)
        color= 1;
    else if (strcasecmp(cor,"g")==0)
        color= 2;
    else if (strcasecmp(cor,"b")==0)
        color= 3;
    else if (strcasecmp(cor,"rg")==0)
        color= 4;
    else if (strcasecmp(cor,"rb")==0)
        color= 5;
    else if (strcasecmp(cor,"gb")==0)
        color= 6;
    return color;
}