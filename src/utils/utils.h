
#if !defined(UTILS_H)
#define UTILS_H
#include <stdio.h>

typedef struct rgb
{
    int R;
    int G;
    int B;
} RGB;

RGB getRGB(FILE *fp);

void initMatrix(RGB ***M, int w, int h);

void getDimensions(int *w, int *h, FILE *fp);

#endif // UTILS_H
