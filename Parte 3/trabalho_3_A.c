#include <stdio.h>

#define TOTAL_INPUT 25
#define TOTAL_LETRA 2
#define THRESHOLD 0

// Função de ativação (degrau)

int activate(double sum) {
    return sum >= THRESHOLD ? 1 : -1;
}

int main() {
    // Dados de treinamento
    int x[TOTAL_LETRA][TOTAL_INPUT] = {
        // Letra X
        {
            1, -1, -1, -1, 1,
            -1, 1, -1, 1, -1,
            -1, -1, 1, -1, -1,
            -1, 1, -1, 1, -1,
            1, -1, -1, -1, 1
        },
        // Letra T
        {
            1, 1, 1, 1, 1,
            -1, -1, 1, -1, -1,
            -1, -1, 1, -1, -1,
            -1, -1, 1, -1, -1,
            -1, -1, 1, -1, -1
        }
    };
    
    int t[TOTAL_LETRA] = {1, -1}; // X: 1, T: -1

    // Inicialização dos pesos e parâmetros
    double pesos[TOTAL_INPUT] = {0};
    double bias = 0;
    double novos_pesos[TOTAL_INPUT];
    double new_bias;
    double ape = 1;
    int cycles = 0;
    int changed;

    printf("Treinamento do Perceptron para identificação de letras X e T\n\n");

    // Treinamento da rede neural
    do {
        changed = 0;
        cycles++;

        printf("Ciclo %d =>  ", cycles);

        for (int letra = 0; letra < TOTAL_LETRA; letra++) {

            double sum = 0;

            for (int input = 0; input < TOTAL_INPUT; input++) {
                sum += pesos[input] * x[letra][input];
            }

            int output = activate(sum + bias);

            if (output != t[letra]) {
                changed = 1;

                for (int input = 0; input < TOTAL_INPUT; input++) {
                    novos_pesos[input] = pesos[input] + ape * x[letra][input] * t[letra];
                }

                new_bias = bias + ape * t[letra];

                for (int input = 0; input < TOTAL_INPUT; input++) {
                    pesos[input] = novos_pesos[input];
                }

                bias = new_bias;
            }
        }

        printf("Pesos: [%.2f, %.2f, ...], Bias: %.2f\n", pesos[0], pesos[1], bias);

    } while (changed);

    printf("\nFim do treinamento com %d ciclos.\n\n", cycles);
    
    
    int x_teste[TOTAL_LETRA][TOTAL_INPUT] = {
            // Letra X
            {
            1, -1, -1, -1, 1,
            -1, 1, -1, 1, -1,
            -1, -1, 1, -1, -1,
            -1, 1, -1, 1, -1,
            1, -1, -1, -1, 1
            },
            // Letra T
            {
             1, 1, 1, 1, 1,
            -1, -1, 1, -1, -1,
            -1, -1, 1, -1, -1,
            -1, -1, 1, -1, -1,
            -1, -1, 1, -1, -1
            }
        };

    char letra_teste[2] ={'X','T'};
    
    // Teste da rede treinada
    printf("Teste da rede treinada:\n");
    for (int letra = 0; letra < TOTAL_LETRA; letra++) {
        double sum = 0;

        for (int input = 0; input < TOTAL_INPUT; input++) {
            sum += pesos[input] * x_teste[letra][input];
        }

        int output = activate(sum + bias);

       
        printf("Letra %c: Saída: %d\n", letra_teste[letra], output);
    }

    return 0;
}
