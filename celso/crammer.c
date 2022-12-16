
void metodoCrammer(float **matriz,int tamanho,float *vetResultado){
    //parte correta! {
    float determinante[2] = {1.0,1.0};
    float *dimensoes = vetorCria(tamanho);
    float d = 0.0;
    //pega valores na diagonal
    for (int j = 0; j < tamanho; j++)
        determinante[0] *= matriz[j][j];
        // printf("\n %.1f * %.1f = %.2f \n",determinante[0],matriz[j][j],determinante[0] *matriz[j][j]);
    
    //pega valores na diagonal inversa
    for (int i = 0; i < tamanho; i++) 
        determinante[1] *= matriz[i][tamanho - 1 - i];
    
    d = determinante[0] - determinante[1];
    printf("\n\n d = %.2f ", d);
    //parte correta! }


    // parte errada !!!!
    //funfa so com o Dx
    for(int k  = 0 ; k < tamanho; k++){
        determinante[0] = 1.0;
        determinante[1] = 1.0;
        
        determinante[k] *= vetResultado[k];

        for(int j = 0; j < tamanho; j++){
            if(j == k ); 
            else determinante[0] *= matriz[j][j];
        }
        for (int i = 0; i < tamanho; i++) {
            if(tamanho - 1 - i == k);
            else  determinante[1] *= matriz[i][tamanho - 1 - i];
        } 
        dimensoes[k] = (determinante[0] - determinante[1]) /d;  
        //inves de ser x , sera 0. inves de y sera 1 e assim por diante ...
        printf("\n\n\t posicao %d == %.2f \n", k, dimensoes[k]);
    }
    

    
}