#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Constantes do jogo
#define NUM_CARTOES 6
#define NUM_MAX 63

// Protótipos das funções
void carregaMenu();
void jogoManNum(int modo);
void apresentaCartao(int cartao);
void inicializaCartoes();
int calcularNumero(int respostas[]);
void mostrarTodosCartoesComNumero(int numero);

// Variável global para os cartões
int cartoes[NUM_CARTOES][NUM_MAX] = {0};
int tamanhosCartoes[NUM_CARTOES] = {0};

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    inicializaCartoes(); // Preenche os cartões conforme as regras
    carregaMenu(); // Inicia o menu principal
    return 0;
}

// Função para inicializar os cartões com os números corretos
void inicializaCartoes() {
    for (int num = 1; num <= NUM_MAX; num++) {
        for (int bit = 0; bit < NUM_CARTOES; bit++) {
            if (num & (1 << bit)) {
                cartoes[bit][tamanhosCartoes[bit]++] = num;
            }
        }
    }
}

// Função para exibir o menu e processar a escolha do usuário
void carregaMenu() {
    int opcao;
    
    do {
        printf("\n=== Jogo Magic6 ===\n");
        printf("1. Computador adivinha o seu numero\n");
        printf("2. Voce adivinha o numero do computador\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao (1-3): ");
        
        if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 3) {
            printf("Opcao invalida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }
        
        if (opcao != 3) {
            jogoManNum(opcao);
        }
    } while (opcao != 3);
    
    printf("Obrigado por jogar!\n");
}

// Função principal que controla o fluxo do jogo
void jogoManNum(int modo) {
    char jogarNovamente;
    
    do {
        if (modo == 1) {
            // Modo 1: Computador adivinha o número do usuário
            int respostas[NUM_CARTOES] = {0};
            
            printf("\nPense em um numero entre 1 e %d...\n", NUM_MAX);
            printf("Para cada cartao, digite 1 se o numero estiver no cartao ou 0 caso contrario.\n\n");
            
            for (int i = 0; i < NUM_CARTOES; i++) {
                apresentaCartao(i + 1);
                printf("O numero esta neste cartao? (1-Sim, 0-Nao): ");
                
                while (scanf("%d", &respostas[i]) != 1 || (respostas[i] != 0 && respostas[i] != 1)) {
                    printf("Entrada invalida! Digite 1 para Sim ou 0 para Nao: ");
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                }
            }
            
            int numero = calcularNumero(respostas);
            printf("\nO numero que voce pensou foi: %d\n", numero);
            
        } else if (modo == 2) {
            // Modo 2: Usuário adivinha o número do computador
            int numeroComputador = rand() % NUM_MAX + 1;
            
            printf("\nO computador pensou em um numero entre 1 e %d...\n", NUM_MAX);
            printf("Estes sao os cartoes onde o numero aparece:\n");
            
            mostrarTodosCartoesComNumero(numeroComputador);
            
            int palpite;
            printf("\nQual e o numero que o computador pensou? ");
            
            while (scanf("%d", &palpite) != 1 || palpite < 1 || palpite > NUM_MAX) {
                printf("Numero invalido! Digite um numero entre 1 e %d: ", NUM_MAX);
                while (getchar() != '\n'); // Limpa o buffer de entrada
            }
            
            if (palpite == numeroComputador) {
                printf("Parabens! Voce acertou!\n");
            } else {
                printf("Que pena! O numero correto era %d.\n", numeroComputador);
            }
        }
        
        printf("\nDeseja jogar novamente neste modo? (S/N): ");
        scanf(" %c", &jogarNovamente);
        while (getchar() != '\n'); // Limpa o buffer de entrada
        
    } while (jogarNovamente == 'S' || jogarNovamente == 's');
}

// Função para exibir um cartão específico
void apresentaCartao(int cartao) {
    printf("\n=== Cartao %d ===\n", cartao);
    int index = cartao - 1;
    
    for (int i = 0; i < tamanhosCartoes[index]; i++) {
        printf("%4d", cartoes[index][i]);
        if ((i + 1) % 8 == 0) printf("\n"); // Quebra linha a cada 8 números
    }
    
    if (tamanhosCartoes[index] % 8 != 0) printf("\n"); // Garante quebra de linha se não for múltiplo de 8
    printf("\n");
}

// Função para calcular o número com base nas respostas do usuário
int calcularNumero(int respostas[]) {
    int numero = 0;
    for (int i = 0; i < NUM_CARTOES; i++) {
        if (respostas[i]) {
            numero += (1 << i);
        }
    }
    return numero;
}

// Função para mostrar todos os cartões com indicação de onde o número aparece
void mostrarTodosCartoesComNumero(int numero) {
    for (int c = 1; c <= NUM_CARTOES; c++) {
        int index = c - 1;
        bool aparece = false;
        
        // Verifica se o número está neste cartão
        for (int i = 0; i < tamanhosCartoes[index]; i++) {
            if (cartoes[index][i] == numero) {
                aparece = true;
                break;
            }
        }
        
        if (aparece) {
            printf("\n=== Cartao %d (contem o numero) ===\n", c);
        } else {
            printf("\n=== Cartao %d (nao contem o numero) ===\n", c);
        }
        
        for (int i = 0; i < tamanhosCartoes[index]; i++) {
            printf("%4d", cartoes[index][i]);
            if ((i + 1) % 8 == 0) printf("\n");
        }
        
        if (tamanhosCartoes[index] % 8 != 0) printf("\n");
    }
}