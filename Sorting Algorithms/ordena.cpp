#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>  
#include "filme.h"
#include "sort.h"

int obter_numero_de_filmes(const std::string& nomeArquivoTexto) {
    std::ifstream arquivo(nomeArquivoTexto);
    int numeroLinhas = 0;

    if (arquivo.is_open()) {
        std::string linha;
        while (getline(arquivo, linha)) {
            numeroLinhas++;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivoTexto << std::endl;
    }

    return numeroLinhas;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <arquivo_binário>.dat inteiro" << std::endl;
        return 1;
    }

    std::string NomeArquivoBinario = argv[1];
    int metodo = std::stoi(argv[2]);

    std::ifstream arquivoBinario(NomeArquivoBinario, std::ios::binary);

    if (!arquivoBinario.is_open()) {
        std::cerr << "Erro ao abrir arquivo binário." << std::endl;
        return 1;
    }

    std::vector<Filme> filmes;
    Filme filme;

    while (arquivoBinario.read(reinterpret_cast<char*>(&filme), sizeof(Filme))) {
        filmes.push_back(filme);
    }

    arquivoBinario.close();

    switch (metodo) {
        case 1:
            bubbleSort(filmes);
            break;
        case 2:
            mergeSort(filmes);
            break;
        case 3:
            quickSort(filmes);
            break;
        default:
            std::cout << "O inteiro deve ser 1, 2 ou 3." << std::endl;
            return 1;
    }

    std::ofstream arquivoTexto("filmes_ordenados.txt");
    if (!arquivoTexto.is_open()) {
        std::cerr << "Erro ao abrir arquivo de texto." << std::endl;
        return 1;
    }

    arquivoTexto << std::left << std::setw(50) << "NOME" << "Year" << "Metascore" << std::endl;
    for (const Filme& f : filmes) {
        arquivoTexto << std::left << std::setw(50) << f.nome
                     << std::setw(8) << f.ano
                     << std::setw(10) << f.metascore << std::endl;
    }

    arquivoTexto.close();

    return 0;
}
