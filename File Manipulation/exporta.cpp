#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Filme {
    string nome;
    int ano;
    int tempo;
    float avaliacao;
    int metascore;
    float bilheteria;
};

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat" << endl;
        return 1;
    }

    string NomeArquivoTexto = argv[1];
    string NomeArquivoBinario = argv[2];

    ifstream entrada(NomeArquivoTexto);
    if (!entrada.is_open()) {
        cout << "Erro: Falha ao abrir arquivo de entrada." << endl;
        return 1;
    }

    ofstream saida(NomeArquivoBinario, ios::binary);
    if (!saida.is_open()) {
        cout << "Erro: Falha ao abrir arquivo de saída." << endl;
        return 1;
    }

    string linhaCabecalho;
    getline(entrada, linhaCabecalho);

    Filme filme;
    string tempString;
    while (getline(entrada, filme.nome, ',')) {
        getline(entrada, tempString, ',');
        filme.ano = stoi(tempString);

        entrada >> filme.tempo;
        entrada >> filme.avaliacao;
        entrada >> filme.metascore;
        entrada >> filme.bilheteria;

        entrada.ignore();

        saida.write((char*)&filme, sizeof(Filme));
    }

    entrada.close();
    saida.close();

    cout << "Conversão concluída com sucesso!" << endl;

    return 0;
}
