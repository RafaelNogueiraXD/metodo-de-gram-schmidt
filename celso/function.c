//funcoes vetores 
float *vetorCria(int tamanho){
    float*vetor = (float*) malloc(sizeof(float)*tamanho);
    return vetor;
};
float *vetorPreenche(float*vet,int tamanho){
    char op;
    for (int j = 0; j != 1 ;)
    {
        printf("\n Preencher o vetor de forma Automatica ou Manual(a/m)?");
        scanf("%c",&op);
        getchar();
        switch (op){
        case 'a':
            for (int i = 0; i < tamanho; i++)vet[i] = rand() % 100;
            j++;
        break;
        case 'm':
            for (int i = 0; i < tamanho; i++){
                printf("%d : ",i);
                scanf("%f",&vet[i]);
                getchar();
            }
            j++;
        break;
        default:
            printf("\n opcao invalida \n");
            break;
        }
    }
    
    return vet;
};
void vetorMostra(char nome[20], float*  vet,int tamanho){
    printf("\n \nVetor %s: {", nome);
    for (int i = 0; i < tamanho; i++)printf(" %.2f ,",vet[i]);
    printf(" }");
};
float *vetorGera(int tamanho){
    float *vetor = vetorCria(tamanho);
    vetor = vetorPreenche(vetor,tamanho);
    vetorMostra("gerado ",vetor,tamanho);
    return vetor;
};
float vetorSoma(float*vet1,float*vet2, int tamanho){
    int somatorio = 0;
    for(int i=0;i<tamanho;i++)somatorio += vet1[i] + vet2[i];
    return somatorio;
};

float *diferencaVetores(float *vet1, float *vet2, int tamanho){

    float *resultado=vetorCria(tamanho);

    for(int i=0;i<tamanho;i++)resultado[i]=vet1[i]-vet2[i];
    return resultado;

}   

float multiplicaVetores(float *vet1,float *vet2, int tamanho){ 

    int resultado=0;
    for(int i=0;i<tamanho;i++)resultado+=vet1[i]*vet2[i];
    return resultado;
}

float encontraCoeficiente(float *vet1, float *vet2, int tamanho){

    float coeficienteA=0.0;
    coeficienteA=multiplicaVetores(vet1,vet2,tamanho)/multiplicaVetores(vet2,vet2,tamanho);
    return coeficienteA;
}
      
float *encontraVetor_W_Individual(float *vet1,float *vet2,int tamanho){

    float *vetorW=vetorCria(tamanho);
    float coeficiente=0.0;
   
    coeficiente=encontraCoeficiente(vet1,vet2,tamanho);
    for(int i=0;i<tamanho;i++)vetorW[i]=vet1[i]-(vet2[i]*coeficiente);
    return vetorW;
}
//Wn=Vn - Somatorio de W1a1 a Wnan-1

float encontraWn(float **vetores,int tamanho,int n){

    vetores=malloc(sizeof(float)*n);
    for(int i=0;i<n;i++)vetores[i]=vetorCria(tamanho);

    float *diferença=vetorCria(tamanho);

    float **vetoresOrtogonais=malloc(sizeof(float)*n);
    for(int i=0;i<n;i++)vetoresOrtogonais[i]=vetorCria(tamanho);

    for(int i=0;i<tamanho;i)vetoresOrtogonais[1][i]=vetores[1][i];

    //W2 = vetoresOrtogonais[2][i] - encontraCoeficiente(vetores[2],vetores[1],tamanho)*vetoresOrtogonais[1][i]
    //W2 = vetoresOrtogonais[2] = vetores[2][i] - encontraVetorW(vetores[2],vetoresOrtogonais[1],tamanho)

    //W3 = vetoresOrtogonais[3][i] - (encontraCoeficiente(vetores[3],vetoresOrtogonais[1],tamanho)*vetoresOrtogonais[1][i]  + encontraCoeficiente(vetores[3],vetoresOrtogonais[2],tamanho)*vetoresOrtogonais[2][i])
    //W3 = vetoresOrtogonais[3] = vetores[3][i] - [encontraVetorW(vetores[3],vetoresOrtogonais[1],tamanho) + encontraVetorW(vetores[3],vetoresOrtogonais[2],tamanho);
    //W3 = vetoresOrtogonais[3] = vetores[3][i] - diferença[i]
    //diferença[i]+= EncontraVetorW(Vetores[i],vetoresOrtogonais[j],tamanho)

    //Wn = vetores[n][i] - encontraCoeficientes(vetores[n],vetores[n-1],tamanho)*vetores[n]

    for(int i=0;i<n;i++){
        for(int j=0;j<i-1;j++){


        }
    }
}



float vetorModulo(float*vet1, int tamanho){
    float acumulador=0;
    for (int i = 0; i < tamanho; i++) acumulador += pow(vet1[i],2);
    return sqrt(acumulador);
};


//funcoes matrizes
    // float **matriz2dCria(int linha,int coluna){};
    // float **matriz2dPreenche(float**matriz,int linha,int coluna){};
    // void matriz2dMostra(float**matriz,int linha,int coluna){};
    // float matriz2dSoma(float**matriz1,float**matriz2 ,int linha,int coluna){};
    // float **matriz2dMultiplicacao(float**matriz1,float**matriz2 ,int linha,int coluna1, int coluna2){};
//metodos
    float verificaLi(float *vet1,float *vet2, int tamanho){
        printf("\n\n\n\t !Verificando Lineariadade: ");
        float vet[2] = {0.0,0.0};
        MetodoCramer(vet1,vet2,vet, tamanho);
    }
    void MetodoCramer(float *vet1,float *vet2,float * vetResultado, int tamanho){
        float *vetorA = vetorCria(tamanho);
        float x = 0, y = 0, d = 0.0, eq1 = 0 , eq2=0;
       
        d = vet1[0] * vet2[1] - vet1[1] * vet2[0] ;
        x =( vet2[1] * vetResultado[0] - vet2[0] * vetResultado[1] ) / d;
        y =( vet1[0] * vetResultado[1] - vet1[1] * vetResultado[0])  / d; 
       
        eq1 = vet1[0] * x + vet2[0]* y;
        eq2 = vet1[1] * x + vet2[1]* y;

        eq1 == vetResultado[0] ? printf("\n Primeira equacao ok! \n") : printf(" \n primeira falhou \n");
        eq2 == vetResultado[1] ? printf("\n Segunda equacao ok! \n") : printf("\n segunda falhou \n");
        // x = vet1[0] + vet2[0] . . .
        // y = vet1[1] + vet2[1]
    };
    // float **BaseOrtogonal(){};