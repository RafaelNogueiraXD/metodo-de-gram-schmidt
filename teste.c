#include <stdio.h>
#include <stdlib.h>
#define N 4 //O numero de equações (linhas do sistema linear)

void main (){
    int i, j, k, linha = 3, coluna = 4;
    float fator, soma;
    float X[N];
    float M[N][N] = {  {3, 4, 6, -14},
                       {1, 0, 1, -2},
                       {0, 3, 1, -1}
                     };

     for(i = 0; i<N; i++){
        for(j = 0; j<N; j++){
            printf("|%.3f\t", M[i][j]);
        }
        printf("\n");
    }

// ELIMINACAO PROGRESSIVA
    for(k = 0; k<N-1; k++){//Laco exterior se refere a coluna pivo que se altera. (linha pivo ou equacao pivo = equacao referencial para as eliminacoes)
        for(i = (k+1); i<N; i++){//Este laco se refere as linhas que sofrerao as eliminacoes, que sempre iniciarao na linha seguinte da linha pivo
            fator = M[i][k] / M[k][k];//fator de correcao que sera multiplicada pela linha pivo
         
   for(j=0; j<N; j++){//loco interno se refere a cada coluna da linha que sofrerao modificacoes da linha i
                M[i][j] = M[i][j] - fator*M[k][j];
            }
        }
    }

    X[N-1] = M[N-1][N] / M[N-1][N-1]; // Primeria variavel que obtamos

    //Test
    printf("\n");
    for(i = 0; i<N; i++){
        for(j = 0; j<N; j++){
            printf("|%.3f\t", M[i][j]);
        }
        printf("\n");
    }

// SUBSTITUICAO PROGRESSIVA
    for(i=N-2; i>=0; i--){  //Laco exterior se refere a linha que recebera os valores das variaveis ja encontradas para descobrirmos  as outras. Ela se inicia na penultima linha e vai ate a primeira

        soma = 0;

        for(j=(i+1); j<N; j++){     //Laco interno se refere as colunas da linha i
            soma = soma + M[i][j]*X[j]; // soma todos os numeros da linha que ja tem o valor de x
        }
        X[i] = (M[i][N] - soma)/M[i][i]; // Calcula o x da coluna i
    }

    printf("\nResultado: " );
    for(i=0; i<N; i++)
         printf("\nX%d = %f\n", i+1, X[i]);

}