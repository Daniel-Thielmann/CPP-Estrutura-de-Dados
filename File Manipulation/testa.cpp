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

void printFilme(const Filme& filme) {
    cout << "Movie Name: " << filme.nome << endl;
    cout << "Year of Release: " << filme.ano << endl;
    cout << "Watch Time: " << filme.tempo << endl;
    cout << "Movie Rating: " << filme.avaliacao << endl;
    cout << "Metascore of Movie: " << filme.metascore << endl;
    cout << "Gross Earnings: " << filme.bilheteria << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <arquivo_binário> <índice_filme>" << endl;
        return 1;
    }

    string NomeArquivoBinario = argv[1];
    int indiceFilme = stoi(argv[2]);

    if (indiceFilme < 0 || indiceFilme > 999) {
        cout << "O índice do filme deve estar entre 0 e 999" << endl;
        return 1;
    }

    ifstream entrada(NomeArquivoBinario, ios::binary);
    if (!entrada.is_open()) {
        cout << "Erro: Falha ao abrir arquivo de entrada." << endl;
        return 1;
    }

    entrada.seekg(indiceFilme * sizeof(Filme)); // Move o ponteiro para o início do filme desejado
    Filme filme;
    entrada.read((char*)&filme, sizeof(Filme));

    printFilme(filme);

    entrada.close();

    return 0;
}
