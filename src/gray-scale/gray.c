#include "gray.h"

static void real_scale(RGB aux,FILE *fp);
void scale(RGB **M, int w, int h,char saida[])
{
    FILE *fp;
    fp = fopen(saida, "wb");
    fwrite("P6\n", 3, 1, fp);
    fprintf(fp, "%d %d\n", w, h);
    fwrite("255\n", 4, 1, fp);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            real_scale(M[i][j],fp);
        }
            
    fclose(fp);
}
static void real_scale(RGB aux,FILE *fp)
{
    int tons[10]={0,28,54,79,105,128,169,192,211,220};
    int med= (aux.R +aux.B +aux.G)/3;
    int real_gray=abs(med-tons[0]);
    for (int i = 1; i < 10; i++)
    {
        if (abs(med-tons[i])< real_gray)
            real_gray=tons[i];
    }
    fwrite(&real_gray,sizeof(char),1,fp);
    fwrite(&real_gray,sizeof(char),1,fp);
    fwrite(&real_gray,sizeof(char),1,fp);
}
