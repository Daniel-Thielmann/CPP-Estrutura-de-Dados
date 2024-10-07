#include <iostream>
#include <fstream>
#include <vector>
#include "Movie.h"                // Classe Movie para manipulação de filmes
#include "sort.h"                 // Funções de ordenação
#include "compress.h"             // Funções de compressão de Huffman


using namespace std;

int main() {
    int escolha;
    do {
        cout << "Menu Principal\n";
        cout << "1. Processamento dos Dados\n";
        cout << "2. Comparação de Algoritmos de Ordenação\n";
        cout << "3. Aplicação - Contagem por vote_average\n";
        cout << "4. Análise das Estruturas Balanceadas\n";
        cout << "5. Compressão dos Overviews\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch(escolha) {
            case 1:
                // processaDados();     // Chama a função de processamento dos dados
                break;
            case 2:
                // comparaSort();       // Chama a função de comparação de algoritmos de ordenação
                break;
            case 3:
                // voteAverageHash();   // Chama a função que usa Hash para vote_average
                break;
            case 4:
                // comparaTree();       // Chama a função de comparação de árvores balanceadas
                break;
            case 5:
                //compressOverviews // Chama a função de compressão de Overviews
                break;
            case 0:
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Opcao invalida, tente novamente.\n";
        }
    } while (escolha != 0);

    return 0;
}
