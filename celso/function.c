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
void vetorMostra(float*  vet,int tamanho){
    printf("\n \nVetor : {");
    for (int i = 0; i < tamanho; i++)printf(" %.2f ,",vet[i]);
    printf(" }");
};
float *vetorGera(int tamanho){
    float *vetor = vetorCria(tamanho);
    vetor = vetorPreenche(vetor,tamanho);
    vetorMostra(vetor,tamanho);
    return vetor;
};
float vetorSoma(float*vet1,float*vet2, int tamanho){
    int somatorio = 0;
    for(int i=0;i<tamanho;i++)somatorio += vet1[i] + vet2[i];
    return somatorio;
};
float vetorModulo(float*vet1, int tamanho){
    float acumulador=0;
    for (int i = 0; i < tamanho; i++) acumulador += pow(vet1[i],2);
    return sqrt(acumulador);
};
//funcoes matrizes
float **matriz2dCria(int linha,int coluna){};
float **matriz2dPreenche(float**matriz,int linha,int coluna){};
void matriz2dMostra(float**matriz,int linha,int coluna){};
float matriz2dSoma(float**matriz1,float**matriz2 ,int linha,int coluna){};
float **matriz2dMultiplicacao(float**matriz1,float**matriz2 ,int linha,int coluna1, int coluna2){};
//metodos
float **MetodoCramer(){};
float **BaseOrtogonal(){};