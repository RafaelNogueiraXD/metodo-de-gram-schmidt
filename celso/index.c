#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.c"
//  FAVOR LER 
// A FUNÇÃO "vetorGera" aloca,preenche e mostra o vetor, utilizem ele.
int main(){
 
    int tamanho = 0;
    printf("digite o tamanho do vetor");
    scanf("%d",&tamanho);
    getchar();

    //teste de Funções
    float * vetor = vetorGera(tamanho);
    float * vetor2 = vetorGera(tamanho);
    printf("\n soma igual a  %.2f ",vetorSoma(vetor,vetor2,tamanho));
    printf("\n modulo do vetor 1: %.2f ",vetorModulo(vetor,tamanho));
    printf("\n modulo do vetor 2: %.2f ",vetorModulo(vetor2,tamanho));


    printf("\n diferenca entre eles: ");
    vetorMostra(diferencaVetores(vetor,vetor2,tamanho), tamanho);
    printf("\n multiplicacao: %.2f ",multiplicaVetores(vetor,vetor2,tamanho));
    vetorMostra(encontraVetor_W_Individual(vetor,vetor2,tamanho),tamanho);
    
    
    // vetorMostra(encontraVetor_W_Individual(vetor,vetor2,tamanho),tamanho);
    // printf("\n encontra W: %.2f ",encontraVetor_W_Individual(vetor,vetor2,tamanho));
}
