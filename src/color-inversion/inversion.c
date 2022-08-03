#include "inversion.h"

void invert(int h, int w, RGB **M,char saida[])
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
            M[i][j].R = 255 - M[i][j].R;
            M[i][j].G = 255 - M[i][j].G;
            M[i][j].B = 255 - M[i][j].B;
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