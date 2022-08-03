# Manipulação de imagens PPM

> **Instituto Federal de Brasília (IFB) - Campus Taguatinga**
>
> Integrantes: Gabriel Gonçalves Sá , Matheus Nilo Santiago e Khalil De Freitas Pimentel
>
> Data: 01/08/2022

_Sistema Operacional utilizado: Linux_

## Instruções de compilação

A compilação é realizada por um arquivo Makefile, bastando digitar:

```bash
make
```

## Operações

### Redimensionamento de imagem;

Amplia ou reduz a imagem por um certo fator
    
```bash
./main entrada.ppm [amp|red] X saida.ppm
```

onde _entrada.ppm_ e _saida.ppm_ são os arquivos de imagem de entrada e saída, respectivamente, já _amp_ indica que a imagem deve ser ampliada em X vezes e red X de que a imagem deve ser reduzida em X vezes.

Por fim, X é um número inteiro que varia de 1 a 5 (indicando quantas vezes mais a imagem será ampliada ou reduzida).

### Rotação de imagem;

Rotaciona a imagem em ângulos retos (90º, 180º e 270º)

```bash
./main entrada.ppm rot X saida.ppm
```

onde _rot_ indica a funcionalidade de rotação e X indicará qual o ângulo de rotação

### Conversão para Escala de cinza;

Conversão de uma imagem colorida para a escala de cinza

```bash
./main entrada.ppm cinza saida.ppm
```

### Inversão de cores (efeito negativo);

Aplica a inversão de cores, ou efeito negativo, onde cada pixel terá sua cor invertida

```bash
./main entrada.ppm inverte saída.ppm
```

### Remoção de cor;

Zera uma ou mais cores do formato RGB, ou seja, poderá remover o vermelho, o verde, o azul ou alguma dessas combinações de cores da imagem de entrada

```bash
./main entrada.ppm remove [r|g|b|rg|rb|gb] saida.ppm

```

onde _remove_ indica a função de remover cores e _[r|g|b|rg|rb|gb]_ indica alguma das seguintes possibilidades:
- r: remover a cor vermelha;
- g: remover a cor verde;
- b: remover a cor azul;
- rg: remover as cores vermelho e verde;
- rb: remover as cores vermelho azul;
- gb: remover as cores verde e azul.

### Filtro de imagem à escolha do grupo;


```bash
./main entrada.ppm amp 3 saida.ppm
```
