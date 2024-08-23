#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "filme.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat" << std::endl;
        return 1;
    }

    std::string NomeArquivoTexto = argv[1];
    std::string NomeArquivoBinario = argv[2];

    std::ifstream arquivoCsv(NomeArquivoTexto);
    std::ofstream arquivoBinario(NomeArquivoBinario, std::ios::binary);

    if (!arquivoCsv.is_open() || !arquivoBinario.is_open())
    {
        std::cerr << "Erro ao abrir arquivos." << std::endl;
        return 1;
    }

    std::string linha;
    std::vector<Filme> filmes;

    while (std::getline(arquivoCsv, linha))
    {
        std::istringstream ss(linha);
        std::string nome, ano, metascore;

        if (std::getline(ss, nome, ',') &&
            std::getline(ss, ano, ',') &&
            std::getline(ss, metascore))
        {
            Filme filme;
            filme.nome = nome;
            filme.ano = std::stoi(ano);
            filme.metascore = std::stoi(metascore);

            arquivoBinario.write(reinterpret_cast<char*>(&filme), sizeof(Filme));

            filmes.push_back(filme);
        }
    }

    arquivoCsv.close();
    arquivoBinario.close();

    return 0;
}
