//Gabriel Araujo Augustavo
//12111ECP017
//Aprendizado de Maquina - Regra de Hebb

#include <stdio.h>

void imprimir(int i, int j, int vetor[i][j]){
    for(int k = 0; k <i; k++){
        for(int l = 0; l < j; l++){

            printf("%d ", vetor[k][l]);
        }
        printf("\n");
    }
}

void imprimir_linha(int i, int j, int vetor[i][j]){
    
        for(int l = 0; l < j; l++){

            printf("%d ", vetor[i][l]);
        }
        printf("\n");
   
}

int main(){

    int inputs[4][2] ={
        {1, 1}, 
        {1, -1},
        {-1, 1},
        {-1,  -1}}; 
    printf("Entrada x1 e x2: \n");
    imprimir( 4, 2, inputs);

    int combinacoes[16][4] ={
        {1, 1, 1, 1},
        {1, 1, 1, -1},
        {1, 1, -1, 1},
        {1, 1, -1, -1},
        {1, -1, 1, 1},
        {1, -1, 1, -1},
        {1, -1, -1, 1},
        {1, -1, -1, -1},
        {-1, 1, 1, 1},
        {-1, 1, 1, -1},
        {-1, 1, -1, 1},
        {-1, 1, -1, -1},
        {-1, -1, 1, 1},
        {-1, -1, 1, -1},
        {-1, -1, -1, 1},
        {-1, -1, -1, -1}
    }; 
    int total = 0;
    for(int i = 0; i < 16; i++){
        printf("\nSaída sendo testada, respectivamente:");
        imprimir_linha( i, 4, combinacoes);
        int b= 0;
        int w[2] = {0,0};
        int b_n = 0;
        int d_w1, d_w2; //delta w1 e w2;
        int d_b;
        int gap = 0;

            for(int z = 0; z < 4; z++){
                d_w1 = inputs[z][0] * combinacoes[i][z];
                d_w2 = inputs[z][1] * combinacoes[i][z];
                w[0]+= d_w1;
                w[1]+=d_w2; 
                b += combinacoes[i][z];

            }
        
        printf("w1 = %d, w2 = %d, b = %d\n", w[0], w[1], b);

        for(int z = 0; z< 4; z++){
           
            if(combinacoes[i][z] == 1){
                if(b+inputs[z][0]*w[0]+inputs[z][1]*w[1]>= 0){
                    gap++;
                }
                
            }
            else{
                if(b+inputs[z][0]*w[0]+inputs[z][1]*w[1]< 0){
                    gap++;
                }
                    
            }
            
        }
    if(gap == 4){
            printf("Tudo Certo!\n");
            total++;
        }
        else{
            printf("Errado!\n");
        }

    }
    printf("\nTotal treinado corretamente : %d\n", total);

    return 0;
}