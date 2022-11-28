#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.c"

int main(){
 
    int tamanho = 0;
    printf("digite o tamanho do vetor");
    scanf("%d",&tamanho);
    getchar();

    float * vetor = vetorGera(tamanho);
    float * vetor2 = vetorGera(tamanho);
    printf("\n soma igual a  %.2f ",vetorSoma(vetor,vetor2,tamanho));
    printf("\n modulo do vetor 1: %.2f ",vetorModulo(vetor,tamanho));
    printf("\n modulo do vetor 2: %.2f ",vetorModulo(vetor2,tamanho));
}