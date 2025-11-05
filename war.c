// ============================================================================
// PRATICA: SISTEMA DE JOGOS - PARTE 1
//
// OBJETIVO DESTA PARTE:
// Implementar o cadastro e a listagem de jogos usando um array estatico.
// Focar em structs, entrasa/saida de dados e organizacao basica.
//
//
// ===========================================================================

#include<stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// --- Constantes Globais ---
#define MAX_JOGOS 50
#define TAM_STRING 100

// --- Definicao da Estrutura (struct) ---
struct Jogo {
    char nome_do_territorio[TAM_STRING];
    char cor_do_exercito[TAM_STRING];
    char numero_de_tropas[TAM_STRING];
};

// --- Funcao para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} 

// --- Funcao Principal (main) ---
int main() {
    struct Jogo biblioteca[MAX_JOGOS];
    int totalJogos = 0;
    int opcao;

    // --- Laco Principal de Menu ---
    do {

        // Exibe o menu de opcoes.
        printf("=============================\n");
        printf("    JOGOS - PARTE 1\n");
        printf("==============================\n");
        printf("1 - Cadastrar novo jogo\n");
        printf("2 - Listar todos os jogos\n");
        printf("0 - Sair\n");
        printf("--------------------------------\n");
        printf("Escolha uma opcao: ");

        // Le a opcao do usuario.
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf.

        // --- Processamento da Opcao ---
        switch (opcao) {
            case 1: // CADASTRO DE NOVO TERRITORIO
                printf("--- Cadastro de Novo Territorio ---\n\n");

                if (totalJogos < MAX_JOGOS) {
                    printf("Digite o nome do territorio: ");
                    fgets(biblioteca[totalJogos].nome_do_territorio, TAM_STRING, stdin);

                    printf("Digite a cor do exercito: ");
                    fgets(biblioteca[totalJogos].cor_do_exercito, TAM_STRING, stdin);

                    printf("Digite o numero de tropas: ");
                    fgets(biblioteca[totalJogos].numero_de_tropas, TAM_STRING, stdin);                    

                    biblioteca[totalJogos].nome_do_territorio[strcspn(biblioteca[totalJogos].nome_do_territorio, "\n")] = 0;
                    biblioteca[totalJogos].cor_do_exercito[strcspn(biblioteca[totalJogos].cor_do_exercito, "\n")] = 0;
                    biblioteca[totalJogos].numero_de_tropas[strcspn(biblioteca[totalJogos].numero_de_tropas, "\n")] = 0;

                    printf("Digite a edicao: ");
                    scanf("%d", &biblioteca[totalJogos].edicao);
                    limparBufferEntrada();

                    totalJogos++;
                    // totalJogos = totalJogos + 1;

                    printf("\nTerritorio cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia! Nao e possivel cadastrar mais territorios.\n");
                }

                printf("\nPressione ENTER para continuar...");
                getchar(); // Pausa para o usuario ler a mensagem antes de voltar ao menu.
                break;

            case 2: // LISTAGEM DE JOGOS
            printf("--- Lista de Jogos cadastrados ainda.\n");

            if (totalJogos == 0) {
                printf("nenhum jogo cadastrado.\n");
            } else {
                for ( int i = 0; i < totalJogos; i++) {
                    printf("JOGOS %d:\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome_do_territorio);
                    printf("Cor: %s\n", biblioteca[i].cor_do_exercito);
                    printf("Numero de tropas: %s\n", biblioteca[i].numero_de_tropas);
                }
                printf("------------------------------------\n");
            }

            // A pausa e crucial para que o usuario veja a lista antes
            // do proximo loop limpar a tela.
            printf("\nPressione ENTER para continuar...");
            getchar(); 
            break;

            case 0: // SAIR
                printf("\nSaindo do sistema...\n");
                break;

            default: // OPCAO INVALIDA
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione ENTER para continuar...");
                getchar(); 
                break;
        }

    } while (opcao != 0);    
                             
    return 0; // Fim do programa.
}