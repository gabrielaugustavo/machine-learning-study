//Gabriel Araujo Augustavo
//12111ECP017

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
    
    int t[TOTAL_LETRA][2] = {
        {1, -1}, // X: 1, T: -1
        {-1, 1}  // X: -1, T: 1
    };

    // Inicialização dos pesos e parâmetros
    double weights[TOTAL_LETRA][2][TOTAL_INPUT] = {{{0}}};
    double bias[TOTAL_LETRA][2] = {{0}};
    double learning_rate = 1;
    int cycles = 0;
    int changed;

    printf("Treinamento do Perceptron para identificação de letras X e T\n\n");

    // Treinamento da rede neural
    do {
        changed = 0;
        cycles++;

        for (int letra = 0; letra < TOTAL_LETRA; letra++) {
            for (int neuron = 0; neuron < 2; neuron++) {

                double sum = 0;

                for (int input = 0; input < TOTAL_INPUT; input++) {
                    sum += weights[letra][neuron][input] * x[letra][input];
                }

                int output = activate(sum + bias[letra][neuron]);
                
                if (output != t[letra][neuron]) {
                    changed = 1;
                    for (int input = 0; input < TOTAL_INPUT; input++) {
                        weights[letra][neuron][input] += learning_rate * x[letra][input] * t[letra][neuron];
                    }

                    bias[letra][neuron] += learning_rate * t[letra][neuron];
                }
            }
        }


    } while (changed);

    printf("\nFim do treinamento com %d ciclos.\n\n", cycles);

    // Teste da rede treinada
    printf("Teste da rede treinada:\n");
    for (int letra = 0; letra < TOTAL_LETRA; letra++) {
        char letra_char = (letra == 0) ? 'X' : 'T';

        for (int neuron = 0; neuron < 2; neuron++) {
            double sum = 0;

            for (int input = 0; input < TOTAL_INPUT; input++) {
                sum += weights[letra][neuron][input] * x[letra][input];
            }

            int output = activate(sum + bias[letra][neuron]);

            printf("Letra %c, Neurônio %d: Saída: %d\n", letra_char, neuron + 1, output);
        }
    }

    return 0;
}
