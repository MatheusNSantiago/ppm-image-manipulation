#include "utils.h"
#include <stdlib.h>

RGB getRGB(FILE *fp)
{
    RGB rgb;

    rgb.R = fgetc(fp);
    rgb.G = fgetc(fp);
    rgb.B = fgetc(fp);

    return rgb;
}

void initMatrix(RGB ***M, int w, int h)
{
    *M = malloc(h * sizeof(RGB *));

    for (int i = 0; i < h; i++)
    {
        RGB *linha = malloc(sizeof(RGB) * w);

        (*M)[i] = linha;
    }
}

void getDimensions(int *w, int *h, FILE *fp)
{
    char magicNumber[3];
    int maxval;

    /* Pega o magic number */
    fgets(magicNumber, 3, fp); // Inútil

    /* Pega as dimensões da matriz  */
    fscanf(fp, "%i %i", w, h); // (Só esse que importa)

    /* Pega o valor máxim do RGB */
    fscanf(fp, "%i\n", &maxval); // Inútil
}