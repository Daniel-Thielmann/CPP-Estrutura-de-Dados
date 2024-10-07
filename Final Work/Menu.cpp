#include "Menu.h"

#include <iostream>
#include <chrono>
#include "./Menu.h"
#include "./sort.h"
#include "./ArvoreVP.h"
#include "./compress.h"
#include "./Hash.h"

extern std::string globalPath;

Menu::Menu(){
    UI();
}

void Menu::UI(){
    int option = 1;
    while (option != 0) {
        std::cout << "MENU" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "[1] Ordenacao" << std::endl;
        std::cout << "[2] Hashing" << std::endl;
        std::cout << "[3] Estruturas balanceadas" << std::endl;
        std::cout << "[4] Metodos de compressao" << std::endl;
        std::cout << "[0] Sair" << std::endl;
        std::cout << "Sua escolha: ";
        std::cin >> option;

        switch (option) {
            case 1:{
                outputFile.open(globalPath + "/compara_sort.out");
                if (outputFile.is_open())
                    sortMenu();
                else
                    std::cout << "Erro ao abrir arquivo" << std::endl;
            }
                break;
            case 2: {
                hashTable();
                break;
            }
            case 3:{
                outputFile.open(globalPath + "/compara_tree.txt");
                if (outputFile.is_open())
                    treeMenu();
                else
                    std::cout << "Erro ao abrir arquivo" << std::endl;
                break;
            }
            case 4:{
                compressionsMenu();
                break;
            }
            case 0: break;
            default: std::cout << "Opcao invalida!" << std::endl;
        }

    }

}

void Menu::sortMenu() {
    int option = 1;
    int M = 3; // número de vezes que cada algoritmo será executado para o cálculo de desempenho

    std::ifstream input;

    while (option != 3) {
        std::cout << std::endl << "SORT MENU" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "[0] QuickSort" << std::endl;
        std::cout << "[1] MergeSort" << std::endl;
        std::cout << "[2] HeapSort" << std::endl;
        std::cout << "[3] Sair" << std::endl;
        std::cout << "Sua escolha: ";
        std::cin >> option;

        switch (option) {
            case 0: {
                input.open( globalPath + "/compara_sort.dat");
                if (!input.is_open()) {
                    std::cout << "Erro ao abrir arquivo de entrada para metricas de desempenho" << std::endl;
                    return;
                }

                outputFile << "\nMÉTRICAS DE DESEMPENHO DO QUICKSORT" << std::endl;
                outputFile << "Considerando a quantidade de movies a serem ordenadas como N " << std::endl;
                outputFile << "e o número de execuções do algoritmo fixo em M = 3" << std::endl << std::endl;

                std::string line;
                int N = 0;
                while (getline(input, line)) {
                    N = stoi(line);
                    outputFile << "\n\nRESULTADOS PARA N = " << N << std::endl;
                    for (int i = 0; i < M; ++i) {
                        outputFile << std::endl;
                        outputFile << "Execução número " << (i + 1) << std::endl;
                        Movie *movies = Movie::import(N);
                        sort(movies, N, 0, outputFile);
                    }
                }
                input.close();
            }break;
            case 1:{
                input.open(globalPath + "/compara_sort.dat");
                if (!input.is_open()) {
                    std::cout << "Erro ao abrir arquivo de entrada para metricas de desempenho" << std::endl;
                    return;
                }

                outputFile << "\nMÉTRICAS DE DESEMPENHO DO MERGESORT" << std::endl;
                outputFile << "Considerando a quantidade de movies a serem ordenadas como N " << std::endl;
                outputFile << "e o número de execuções do algoritmo fixo em M = 3" << std::endl << std::endl;

                std::string line;
                int N = 0;
                while (getline(input, line)) {
                    N = stoi(line);
                    outputFile << "\n\nRESULTADOS PARA N = " << N << std::endl;
                    for (int i = 0; i < M; ++i) {
                        outputFile << std::endl;
                        outputFile << "Execução número " << (i + 1) << std::endl;
                        Movie *reviews = Movie::import(N);
                        sort(reviews, N, 1, outputFile);
                    }
                }
                input.close();
            }break;
            case 2: {
                input.open( globalPath + "/compara_sort.dat");
                if (!input.is_open()) {
                    std::cout << "Erro ao abrir arquivo de entrada para metricas de desempenho" << std::endl;
                    return;
                }

                outputFile << "\nMÉTRICAS DE DESEMPENHO DO HEAPSORT" << std::endl;
                outputFile << "Considerando a quantidade de movies a serem ordenadas como N " << std::endl;
                outputFile << "e o número de execuções do algoritmo fixo em M = 3" << std::endl << std::endl;

                std::string line;
                int N = 0;
                while (getline(input, line)) {
                    N = stoi(line);
                    outputFile << "\nRESULTADOS PARA N = " << N << std::endl;
                    for (int i = 0; i < M; ++i) {
                        outputFile << std::endl;
                        outputFile << "Execução número " << (i + 1) << std::endl;
                        Movie *reviews = Movie::import(N);
                        sort(reviews, N, 2, outputFile);
                    }
                }
                input.close();
            }break;
            case 3: break;
            default: std::cout << "Opcao invalida!" << std::endl;
        }

    }
}

void Menu::treeMenu() {
    int option = 1;
    int M = 3;
    int N = 10000;
    int B = 100;

    std::ifstream input;

    ///AJUSTAR VALOR DE N
    while (option != 0) {
        std::cout << std::endl << "MENU DE ESTRUTURAS BALANCEADAS" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "[1] Arvore rubro-negra" << std::endl;
        std::cout << "[2] Arvore B" << std::endl;
        std::cout << "[0] Sair" << std::endl;
        std::cout << "Sua escolha: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                outputFile << "MÉTRICAS DE DESEMPENHO DO ÁRVORE RUBRO-NEGRA" << std::endl;
                outputFile << "Considerando a quantidade de reviews a serem ordenadas" << std::endl;
                outputFile << "como N = " << N << " e o número de execuções do algoritmo fixo em M = 3" << std::endl << std::endl;

                long long int sumCompInsert = 0;
                long long int sumTimeInsert = 0;
                long long int sumCompSearch = 0;
                long long int sumTimeSearch = 0;

                for (int i = 0; i < M; ++i) {
                    outputFile << std::endl;
                    outputFile << "Execução número " << (i + 1) << std::endl;
                    std::cout << std::endl;
                    std::cout << "Execucao numero " << (i + 1) << std::endl;

                    auto *tree = new ArvoreVP();

                    Movie *movies = Movie::import(N);

                    long int comparisons = 0;
                    auto start = std::chrono::steady_clock::now();

                    for (int k = 0; k < N; ++k) {
                        tree->insere(movies[k].getId(), movies[k].getBinaryIndex(),  comparisons);
                    }

                    auto end = std::chrono::steady_clock::now();
                    auto elapsed = end - start;
                    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
                    sumTimeInsert += time;
                    sumCompInsert += comparisons;

                    outputFile << "INSERÇÃO:" << std::endl;
                    outputFile << "Comparações: " << comparisons << std::endl;
                    outputFile << "Tempo de inserção: " << time << "ms" << std::endl;
                    std::cout << "INSERCAO:" << std::endl;
                    std::cout << "Comparacoes: " << comparisons << std::endl;
                    std::cout << "Tempo de insercao: " << time << "ms" << std::endl;

                    movies = Movie::import(B);

                    comparisons = 0;

                    start = std::chrono::steady_clock::now();
                    for (int j = 0; j < B; ++j) {
                        // std::cout << "BUSCANDO O NO " << movies[j].getId() << std::endl;
                        NodeVP* node = tree->busca(movies[j].getId(), comparisons);
                        if(node != nullptr){
                           node->print();
                        }
                    }
                    end = std::chrono::steady_clock::now();
                    elapsed = end - start;
                    time = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
                    sumTimeSearch += time;
                    sumCompSearch += comparisons;

                    outputFile << "BUSCA:" << std::endl;
                    outputFile << "Comparacoes: " << comparisons << std::endl;
                    outputFile << "Tempo de busca: " << time << "ms" << std::endl;
                    std::cout << "BUSCA:" << std::endl;
                    std::cout << "Comparacoes: " << comparisons << std::endl;
                    std::cout << "Tempo de busca: " << time << "ms" << std::endl;

                    //tree->print();

                    delete tree;
                }
                outputFile << "\nMÉDIA DE " << M << " EXECUÇÕES:" << std::endl;
                outputFile << "INSERÇÃO:" << std::endl;
                outputFile << "Comparações: " << sumCompInsert/M << std::endl;
                outputFile << "Tempo de inserção: " << sumTimeInsert/M << "ms" << std::endl;
                outputFile << "BUSCA:" << std::endl;
                outputFile << "Comparações: " << sumCompSearch/M << std::endl;
                outputFile << "Tempo de busca: " << sumTimeSearch/M << "ms" << std::endl;

            }break;
            case 2:{
            }break;

            case 0: break;
            default: std::cout << "Opcao invalida!" << std::endl;
        }

    }
}

void Menu::compressionsMenu() {
    int select = -1;
    while (select < 0 || select > 2) {
        std::cout << std::endl << "COMPRESSAO/DESCOMPRESSAO" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "[0] Compressao" << std::endl;
        std::cout << "[1] Descompressao" << std::endl;
        std::cout << "[2] Sair" << std::endl;
        std::cout << "Sua escolha: ";
        std::cin >> select;
    }
    switch (select) {
        case 0: {
            std::ofstream outputFileTxt;
            outputFileTxt.open(globalPath + "/overviewOrd.txt");
            if (!outputFileTxt.is_open()) {
                std::cout << "Erro ao criar arquivo original de saída" << std::endl;
            }

            int P = -1;

            std::cout << "Quantos filmes deseja comprimir?" << std::endl;
            std::cin >> P;
            if(P <= 0 || P > 44714){
                std::cout << "Erro: Digite um valor entre 0 e 44714" << std::endl;
                exit(-1);
            }

            Movie *movies = Movie::import(P);
            for (int i = 0; i < P; ++i) {
                outputFileTxt << movies[i].getOverview();
            }
            outputFileTxt.close();

            Huffman* huffman = new Huffman();
            huffman->compress(globalPath+"/overviewOrd.txt", globalPath+"/overviewComp.bin");

            break;
        }
        case 1: {
            Huffman* huffman = new Huffman();
            huffman->decompress(globalPath+"/overviewComp.bin", globalPath+"/overviewDecomp.txt");
            break;
        }
    }
}