float **inverteMatriz(float **matriz, int linha, int coluna){
    float**matrizInversa = (float**) malloc(sizeof(float)*linha);
    for(int i = 0; i< linha; i++){
        matrizInversa[i] = (float*) malloc(sizeof(float) * coluna);
        for (int j = 0; j < coluna; j++){
          matrizInversa[i][j] = matriz[j][i];
        }
        
    }
    printf("\n retorno da matriz \n");
    return matrizInversa;   
}
void mostraMatrizVirada(float **matriz, int linha, int coluna){
    for(int i = 0; i< linha; i++){
        printf("\n");
        for (int j = 0; j < coluna; j++)
        {
            printf(" %.2f  ", matriz[j][i]);
        }
        
    }
}
void escalonamento(float **matriz, int linha, int coluna,float *vetResultado){
    printf("\n\n\tRealizando Escalonamento! ");
    float **matrizResultado = (float**) malloc(sizeof(float)* linha);
    for (int i = 0; i < linha; i++)matrizResultado[i] = (sizeof(float) * (coluna+1));
    
    float *vetResultadoFinal = vetResultado;
    float determinante[2] = {0.0,0.0};
    // matrizMostra(matrizResultado,linha, coluna);
    matrizResultado = inverteMatriz(matriz,linha, coluna);
    for(int i = 0 ; i< linha; i++)matrizResultado[i][coluna] = vetResultado[i];
    vetorMostra("resultante",vetResultado,coluna);
    
    float m1 = matrizResultado[0][0];
    float m2 = 0;
    matrizMostra(matrizResultado,linha, coluna+1);
    //eliminando x
    for (int i = 1; i < linha; i++)
    {
        if(matrizResultado[i][0] != 0){
            m2 = matrizResultado[i][0];
            for(int a = 0; a <= coluna ; a ++){
                matrizResultado[i][a] = m1*matrizResultado[i][a]  - m2*matrizResultado[0][a]; 
            }
            matrizResultado[i][0] = 0.0; 
        }
    }
    matrizMostra(matrizResultado,linha, coluna+1);
    getch();
    //eliminando y
    m1 = matrizResultado[1][1];
    for (int i = 2; i < linha; i++){
        if(matrizResultado[i][1] != 0){
            m2 = matrizResultado[i][1];
            if((m2 > 0 && m1 > 0) || (m2 < 0 && m1 < 0)){
                for(int a = 0; a <= coluna ; a ++)
                    matrizResultado[i][a] = m1*matrizResultado[i][a]  - m2*matrizResultado[1][a]; 
            }else{
                for(int a = 0; a <= coluna ; a ++)
                    matrizResultado[i][a] = m1*matrizResultado[i][a]  + m2*matrizResultado[1][a]; 
            }
            matrizMostra(matrizResultado,linha, coluna+1);
            getch();
            matrizResultado[i][1] = 0.0; 
        }
    }
    
    // matrizResultado[1][2] = m1*matrizResultado[1][2]  - m2*matrizResultado[0][2]; 
    // matrizResultado[1][3] = m1*matrizResultado[1][3]  - m2*matrizResultado[0][3]; 

    // int k = 0 ;
    // for (int c = 0; c < coluna-1; c++){
    //     for(int l = linha - 1; l > k; l--){
    //             if(matrizResultado[l][c] != 0){
    //                 matrizResultado[l][c] = 0.0;
    //                 // matrizMostra(matrizResultado,linha, coluna+1);
                 
    //             }
    //     }   
    //     k++;
    // }

    printf("\n ultimo termo: %.2f = %.2f", matrizResultado[linha-1][coluna - 1],matrizResultado[linha-1][coluna]);
    matrizMostra(matrizResultado,linha, coluna+1);
    
    // mostraMatrizVirada(matrizResultado,linha,coluna);
    //Escalonamento, formula para x com sinais iguais
    //matrizResultado[x] = X[k] * (x[n],y[n],z[n],V[n]) - x[n] * (x[k],y[k],z[k],v[k])
    //Escalonamento, formula para x com sinais diferentes
    //matrizResultado[x] = X[k] * (x[n],y[n],z[n],V[n]) + x[n] * (x[k],y[k],z[k],v[k])
  
    //Escalonamento, formula para y com sinais iguais
    //matrizResultado[y] = y[k] * (y[n],z[n],V[n]) - y[n] * (y[k],z[k],v[k])
    //Escalonamento, formula para y com sinais diferentes
    //matrizResultado[y] = y[k] * (y[n],z[n],V[n]) - y[n] * (y[k],z[k],v[k])
    // matrizMostra(matrizResultado, linha, coluna);

}



/*
void teste1(){


      for (int dimensao = 0; dimensao < coluna; dimensao++){ // seleciona se vai manipular (x,y,z...)
        for (int i = dimensao + 1; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                determinante[0] = matrizResultado[dimensao][dimensao]*(matrizResultado[i][j]); 
                determinante[1] = matrizResultado[i][dimensao]*(matrizResultado[dimensao][j]);
                
                if (matrizResultado[dimensao][dimensao] >=  0 && matrizResultado[i][dimensao] >= 0){
                    matrizResultado[i][j] = determinante[0] - determinante[1];
                    printf("\n %.2f = %.2f - %.2f \n ",matrizResultado[i][j], determinante[0],determinante[1]);
                }
                else{
                    matrizResultado[i][j] = determinante[0] + determinante[1];
                    printf("\n %.2f = %.2f - %.2f \n ",matrizResultado[i][j], determinante[0],determinante[1]);
                }
                
                determinante[0] = matrizResultado[dimensao][dimensao]*(vetResultadoFinal[j]);
                determinante[1] = matrizResultado[i][dimensao]*(vetResultadoFinal[j]);
               
                if (matrizResultado[dimensao][dimensao] >=  0 && matrizResultado[i][dimensao] >= 0)
                    vetResultadoFinal[j] = determinante[0] - determinante[1];
                else
                    vetResultadoFinal[j] = determinante[0] + determinante[1];
                getch();
            }
        }
        
        matrizMostra(matrizResultado,linha, coluna);
        vetorMostra("Vetor resultante",vetResultadoFinal,coluna);
        getch();


    }
  
}

*/