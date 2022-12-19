#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "function.c"
#include "crammer.c"
#include "escalonamento.c"
//  FAVOR LER 
// A FUNÇÃO "vetorGera" aloca,preenche e mostra o vetor, utilizem ele.
int main(){
 
    int tamanho = 0,qtd = 0;
    printf("digite o numero de dimensoes dos vetores");
    scanf("%d",&tamanho);
    
    printf("digite o numero de vetores: ");
    scanf("%d",&qtd);
    getchar();
    //teste de Funções
    /*
    float * vetor2 = vetorGera(tamanho);
    printf("\n soma igual a  %.2f ",vetorSoma(vetor,vetor2,tamanho));
    printf("\n modulo do vetor 1: %.2f ",vetorModulo(vetor,tamanho));
    printf("\n modulo do vetor 2: %.2f ",vetorModulo(vetor2,tamanho));


    printf("\n diferenca entre eles:");
    vetorMostra(" De diferenca ",diferencaVetores(vetor,vetor2,tamanho), tamanho);
    printf("\n multiplicacao: %.2f ",multiplicaVetores(vetor,vetor2,tamanho));
    vetorMostra("que encontra W ",encontraVetor_W_Individual(vetor,vetor2,tamanho),tamanho);
    verificaLi(vetor,vetor2,tamanho);
    */

    float **matriz = matrizGera(qtd,tamanho);
    // escalonamento(matriz,qtd,tamanho,vetorResultado);
    
    verificaLi(matriz, qtd, tamanho) == 1 ? printf("\n sistema eh linear\n"): printf("\n sistema nao eh linear!\n") ;
    // MetodoCramerVetores(matriz[0],matriz[1],vetorResultado,tamanho);
    // vetorMostra(encontraVetor_W_Individual(vetor,vetor2,tamanho),tamanho);
    // printf("\n encontra W: %.2f ",encontraVetor_W_Individual(vetor,vetor2,tamanho));
}
