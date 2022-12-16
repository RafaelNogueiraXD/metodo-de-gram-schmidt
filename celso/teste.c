#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void vetorMostra(float *vet, int tamanho)
{
    printf("\n \nVetor : {");
    for (int i = 0; i < tamanho; i++)
        printf(" %.2f ,", vet[i]);
    printf(" }");
};

float *vetorPreenche(float *vet, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
        vet[i] = rand() % 10;

    return vet;
};

float *vetorCria(int tamanho)
{
    float *vetor = (float *)malloc(sizeof(float) * tamanho);

    return vetor;
};

float multiplicaVetores(float *vet1, float *vet2, int tamanho)
{

    int resultado = 0;
    for (int i = 0; i < tamanho; i++)
        resultado += vet1[i] * vet2[i];
    return resultado;
}

float encontraCoeficiente(float *vet1, float *vet2, int tamanho)
{

    float coeficienteA = 0.0;
    coeficienteA = multiplicaVetores(vet1, vet2, tamanho) / multiplicaVetores(vet2, vet2, tamanho);
    return coeficienteA;
}


int main()
{
    //srand(time(NULL));
    int tamanho = 3, Wn = 1;
    int controlador = 1;
    float *diferenca = vetorCria(tamanho), coeficiente = 0, *vetWresultado = vetorCria(tamanho);

    float **vetores = malloc(sizeof(float) * tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        vetores[i] = vetorCria(tamanho);
        vetores[i] = vetorPreenche(vetores[i], tamanho);
    }

    float **vetoresW = malloc(sizeof(float) * tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        vetoresW[i] = vetorCria(tamanho);
    }



    for (int i = 0; i < tamanho; i++)
        vetorMostra(vetores[i], tamanho);

    for (int i = 0; i < tamanho; i++)
        vetoresW[0][i] = vetores[0][i];

    for (int i = 0; i <= Wn; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            printf("\n\ncoeficiente = %f\n\n", coeficiente = encontraCoeficiente(vetores[Wn], vetoresW[i - 1], tamanho));

            for (int k = 0; k < tamanho; k++)
                diferenca[k] += coeficiente * vetores[Wn - 1][k];
        }
    }

    for (int k = 0; k < tamanho; k++)
        printf("\nvet[%d] = %f\n", k, vetoresW[Wn][k] = vetores[Wn][k] - diferenca[k]);



    Wn++;
    for (int i = 0; i < tamanho; i++)
        diferenca[i] = 0.0f;



    for (int i = 0; i <= Wn; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (i - j != 2)
            {
                printf("\n\ncoeficiente = %f\ni=%d Wn=%d\n", coeficiente = encontraCoeficiente(vetores[Wn], vetoresW[i - 1], tamanho), i, Wn);

                for (int k = 0; k < tamanho; k++)
                    printf("\ndiferenca[%d] += %f * %f = %f",k,coeficiente,vetoresW[i-1][k],diferenca[k] += coeficiente * vetoresW[i - 1][k]);
            }
        }
    }

    for (int k = 0; k < tamanho; k++)
        printf("\nvet[%d] = %f\n", k, vetoresW[Wn][k] = vetores[Wn][k] - diferenca[k]);





}
