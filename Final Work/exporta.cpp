#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Movie.h"                // Classe Movie para manipulação de filmes
#include "sort.h"                 // Funções de ordenação
#include "compress.h"             // Funções de compressão de Huffman
#include "Menu.h"

using namespace std;
string globalPath;

int main(int argc, char* argv[]) {

    
     if(argc != 2){
         cout << "ERRO: parametros nao correspondem com a sintaxe do comando" << endl;
         cout << "Sintaxe correta: ./exec <arquivo_entrada>" << endl;
         return 0;
     }
    //srand(time(nullptr));
    globalPath = argv[1];

    Menu* menu = new Menu();
    delete menu;
    // int N = 10;
    // Movie* movies = Movie::import(N);
    /*
    ofstream outFile0("compara_sort_MERGE.txt");
    ofstream outFile1("compara_sort_QUICK.txt");
    ofstream outFile2("compara_sort_heap.txt");
    sort(movies, 10, 0, outFile0);
    sort(movies, 10, 1, outFile1);
    sort(movies, 10, 2, outFile2);
    cout << sizeof(Movie) << endl;*/
    return 0;
}

/*Movie* readCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        cerr << "Erro: " << strerror(errno) << endl; // Imprime uma mensagem de erro mais detalhada
        return nullptr;
    }

    string line;
    getline(file, line); // Ignorar a primeira linha (cabeçalho)

    int numMovies = 0;
    while (getline(file, line)) numMovies++; // Contar número de filmes
    file.clear();
    file.seekg(0, ios::beg);
    getline(file, line); // Ignorar a primeira linha (cabeçalho) novamente

    Movie* movies = new Movie[numMovies]; // Alocar dinamicamente um array de Movie

    int c = 0;
    cout << numMovies << endl;
    for (int i = 0; i < numMovies; i++){
        c++;
        string auxLine;
        getline(file, auxLine);
        line = auxLine;
        cout << "QTD: "<<c<<endl;

        stringstream ss(line);
        string token;
        string tokenAux = line;
        stringstream ssABC(line);

        getline(ss, token, ';');
        getline(ssABC, tokenAux, ';');// Ignorar o primeiro token (índice)
        //adulto
        bool adult;
        movies[i].setAdult(adult);
        std::getline(ss, token, ';'); //adult = (token == "True");
        getline(ssABC, tokenAux, ';');
        //ler genre
        getline(ss, token, ';');
        getline(ssABC, tokenAux, ';');
        movies[i].setGenres(token.c_str(), 100);
        // Campo 'id'
        getline(ss, token, ';');
        getline(ssABC, tokenAux, ';');
        movies[i].setId(stoi(token));

        // Campo 'imdb_id'
        getline(ss, token, ';');
        getline(ssABC, tokenAux, ';');
        movies[i].setImdbId(token.c_str());

        // Campo 'original_language'
        getline(ss, token, ';');
        getline(ssABC, tokenAux, ';');
        movies[i].setOriginalLanguage(token.c_str());

        // Campo 'original_title'
        string original_title;
        getline(ss, token, ';');
        getline(ssABC, tokenAux, ';');
        original_title = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                getline(ssABC, tokenAux, ';');
                original_title += token;
            }
        }
        movies[i].setOriginalTitle(original_title.c_str());

        // Campo 'overview'
         string overview;
//         getline(ss, token, ';');
//         getline(ssABC, tokenAux, ';');
//         overview += token;
//         //cout << "AQUI INFERNO: "<<token << endl;
//         if (token[0] == '"') {
//             getline(ssABC, tokenAux, ';');
//
//             std::string tokenCompare = token;
//             std::string tokenAuxCompare = tokenAux;
//             if(!isNumeric(tokenAuxCompare)) {
//                 if(token[token.size() - 1] == '"' && !tokenCompare.contains(tokenAuxCompare)) {
//                     token += tokenAux;string nextLine = auxLine;
//                     // getline(ssABC, tokenAux, ';');
//                     // while(!isNumeric(tokenAux)) {
//                     //     token+=tokenAux;
//                     //     getline(ssABC, tokenAux, ';');
//                     // }
//                 }
//             }
//
//
//             while (token.back() != '"') {
// //               cout << "token " << token << endl;
//                 getline(ss, token, ';');
//
//
//                 overview+= token;
//
//                 if(ss.eof()){
//                     getline(file, auxLine);
//                     // while(!nextLine.empty()){
//                     //     cout << "AQUI PORRA"<<endl;
//                     //     stringstream ss(nextLine);
//                     //     getline(ss, token, ';');
//                     //     cout << "TOKEN DO INFERNO: " << token << endl;
//                     // }
//                     //cout << "AUXLINE: " << auxLine << endl;
//                     stringstream ssAux(auxLine);
//                     getline(ssAux, token, ';');
//                     overview+=token;
//                     getline(ssAux, token, ';');
//                     string nextLine = auxLine;
//                     getline(file, nextLine);
//                     //cout << "NEXT LINE: "<<nextLine << endl;
//                     if(!nextLine.empty()) {
//                         stringstream ssAux(nextLine);
//                         getline(ssAux, token, ';');
//                         while(!isNumeric(token)) {
//                             overview+=token;
//                             getline(ssAux, token, ';');
//                         }
//                     }
//
//                     // cout << "Overview: "<< overview << endl;
//
//                     break;
//                 }
//
//
//             }
//         }

//DESCOMENTAR ACIMA


        // Campo 'popularity'
        getline(ss, token, ';');
        //cout << "SLOW SOUTHERN STEEL: "<<token << endl;
        while(!isNumeric(token)) {
            cout << "OVERVIEW: " << overview << endl;
            overview += token;
            cout << "OVERVIEW: " << overview << endl;
            getline(ss, token, ';');
            cout << "TOKEN: "<<token << endl;
            if(ss.eof()){
                getline(file, auxLine);
                 // while(!nextLine.empty()){
                 //     cout << "AQUI PORRA"<<endl;
                 //     stringstream ss(nextLine);
                 //     getline(ss, token, ';');
                 //     cout << "TOKEN DO INFERNO: " << token << endl;
                 // }
                //cout << "AUXLINE: " << auxLine << endl;
                stringstream ssAux(auxLine);
                getline(ssAux, token, ';');
                overview+=token;
                getline(ssAux, token, ';');
                string nextLine = auxLine;
                getline(file, nextLine);
                //cout << "NEXT LINE: "<<nextLine << endl;
                while(!nextLine.empty()) {
                    //cout <<"ENTROU" << endl;
                    stringstream ssAux(nextLine);
                    getline(ssAux, token, ';');
                    //cout << "TOKEN: " << token << endl;
                    while(!isNumeric(token)) {
                        //cout << "ENTROU LOOP" << endl;
                        overview+=token;
                        getline(ssAux, token, ';');
                        break;
                    }
                    getline(file, nextLine);
                }

                // cout << "Overview: "<< overview << endl;

                break;
            }
        }
        cout << "OVERVIEW: "<<overview << endl;
        movies[i].setOverview(overview.c_str());
        cout << "POPULARIDADE: " + token << endl;
        movies[i].setPopularity(stod(token));
        //cout << "POPULARIDADE FILME: " << movies[i].getPopularity() << endl;

        // Campo production_companies
        string production_companies;
        getline(ss, token, ';');
        //cout << "TOKEN TESTE: "<<token << endl;
        production_companies = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                production_companies += token;
            }
        }
        movies[i].setProductionCompanies(production_companies.c_str(), 100);


        // Campo production_countries
        string production_countries;
        getline(ss, token, ';');
        production_countries = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                production_countries += token;
            }
        }
        movies[i].setProductionCountries(production_countries.c_str(), 100);


        // Campo 'release_date'
        getline(ss, token, ';');

        movies[i].setReleaseDate(token.c_str());

        // Campo 'revenue'
        getline(ss, token, ';');

        movies[i].setRevenue(stod(token));

        // Campo 'runtime'
        getline(ss, token, ';');

        movies[i].setRuntime(stod(token));

        // Campo 'spoken_languages'
        getline(ss, token, ';');
        movies[i].setSpokenLanguages(token.c_str(), 100);



        // Campo 'title'
        string title;
        getline(ss, token, ';');
        title = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                title += token;
            }
        }
        movies[i].setTitle(title.c_str());

        // Campo 'vote_average'
        getline(ss, token, ';');
//        cout << endl << token;
        movies[i].setVoteAverage(stod(token));

        // Campo 'vote_count'
        getline(ss, token, ';');
        movies[i].setVoteCount(stoi(token));
    }


    file.close();
    return movies;
}

vector<Movie> readCsvVector(const string& filename) {
    ifstream file(filename);
    int c = 0;
    if (file.is_open()) {
        c++;
        vector<Movie> dataSet;
        string line;
        getline(file, line); // Ignorar a primeira linha (cabeçalho)
        while (getline(file, line)) {
            c++;
            Movie movie;
            string auxLine;
            getline(file, auxLine);
            line = auxLine;

            stringstream ss(line);
            string token;
            string tokenAux = line;
            stringstream ssABC(line);

            getline(ss, token, ';');
            getline(ssABC, tokenAux, ';');// Ignorar o primeiro token (índice)
            //adulto
            bool adult;
            movie.setAdult(adult);
            std::getline(ss, token, ';'); //adult = (token == "True");
            getline(ssABC, tokenAux, ';');
            //ler genre
            getline(ss, token, ';');
            getline(ssABC, tokenAux, ';');
            movie.setGenres(token.c_str(), 100);
            // Campo 'id'
            getline(ss, token, ';');
            getline(ssABC, tokenAux, ';');
            movie.setId(stoi(token));

            // Campo 'imdb_id'
            getline(ss, token, ';');
            getline(ssABC, tokenAux, ';');
            movie.setImdbId(token.c_str());

            // Campo 'original_language'
            getline(ss, token, ';');
            getline(ssABC, tokenAux, ';');
            movie.setOriginalLanguage(token.c_str());

            // Campo 'original_title'
            string original_title;
            getline(ss, token, ';');
            getline(ssABC, tokenAux, ';');
            original_title = token;
            if (token[0] == '"') {
                while (token.back() != '"') {
                    getline(ss, token, ';');
                    getline(ssABC, tokenAux, ';');
                    original_title += token;
                }
            }
            movie.setOriginalTitle(original_title.c_str());

            // Campo 'overview'
             string overview;
    //         getline(ss, token, ';');
    //         getline(ssABC, tokenAux, ';');
    //         overview += token;
    //         //cout << "AQUI INFERNO: "<<token << endl;
    //         if (token[0] == '"') {
    //             getline(ssABC, tokenAux, ';');
    //
    //             std::string tokenCompare = token;
    //             std::string tokenAuxCompare = tokenAux;
    //             if(!isNumeric(tokenAuxCompare)) {
    //                 if(token[token.size() - 1] == '"' && !tokenCompare.contains(tokenAuxCompare)) {
    //                     token += tokenAux;string nextLine = auxLine;
    //                     // getline(ssABC, tokenAux, ';');
    //                     // while(!isNumeric(tokenAux)) {
    //                     //     token+=tokenAux;
    //                     //     getline(ssABC, tokenAux, ';');
    //                     // }
    //                 }
    //             }
    //
    //
    //             while (token.back() != '"') {
    // //               cout << "token " << token << endl;
    //                 getline(ss, token, ';');
    //
    //
    //                 overview+= token;
    //
    //                 if(ss.eof()){
    //                     getline(file, auxLine);
    //                     // while(!nextLine.empty()){
    //                     //     cout << "AQUI PORRA"<<endl;
    //                     //     stringstream ss(nextLine);
    //                     //     getline(ss, token, ';');
    //                     //     cout << "TOKEN DO INFERNO: " << token << endl;
    //                     // }
    //                     //cout << "AUXLINE: " << auxLine << endl;
    //                     stringstream ssAux(auxLine);
    //                     getline(ssAux, token, ';');
    //                     overview+=token;
    //                     getline(ssAux, token, ';');
    //                     string nextLine = auxLine;
    //                     getline(file, nextLine);
    //                     //cout << "NEXT LINE: "<<nextLine << endl;
    //                     if(!nextLine.empty()) {
    //                         stringstream ssAux(nextLine);
    //                         getline(ssAux, token, ';');
    //                         while(!isNumeric(token)) {
    //                             overview+=token;
    //                             getline(ssAux, token, ';');
    //                         }
    //                     }
    //
    //                     // cout << "Overview: "<< overview << endl;
    //
    //                     break;
    //                 }
    //
    //
    //             }
    //         }

    //DESCOMENTAR ACIMA


            // Campo 'popularity'
            getline(ss, token, ';');
            //cout << "SLOW SOUTHERN STEEL: "<<token << endl;
            //bool breakLoop = false;
            while(!isNumeric(token)) {
                //cout << "OVERVIEW: " << overview << endl;
                overview += token;
                //cout << "OVERVIEW: " << overview << endl;
                getline(ss, token, ';');
                //cout << "TOKEN: "<<token << endl;
                if(ss.eof()){
                    getline(file, auxLine);
                     // while(!nextLine.empty()){
                     //     cout << "AQUI PORRA"<<endl;
                     //     stringstream ss(nextLine);
                     //     getline(ss, token, ';');
                     //     cout << "TOKEN DO INFERNO: " << token << endl;
                     // }
                    //cout << "AUXLINE: " << auxLine << endl;
                    stringstream ssAux(auxLine);
                    getline(ssAux, token, ';');
                    overview+=token;
                    getline(ssAux, token, ';');
                    string nextLine = auxLine;
                    getline(file, nextLine);
                    //cout << "NEXT LINE: "<<nextLine << endl;
                    while(!nextLine.empty()) {
                        //cout <<"ENTROU" << endl;
                        stringstream ssAux(nextLine);
                        getline(ssAux, token, ';');
                        //cout << "TOKEN: " << token << endl;
                        //bool isBreak = false;
                        while(!isNumeric(token) ) {
                            //cout << "ENTROU LOOP" << endl;
                            overview+=token;
                            getline(ssAux, token, ';');
                            break;
                            //isBreak = true;
                        }
                        getline(file, nextLine);
                    }

                    // cout << "Overview: "<< overview << endl;

                    break;
                    //breakLoop = true;
                }

            }
            //cout << "OVERVIEW: "<<overview << endl;
            movie.setOverview(overview.c_str());
            //cout << "POPULARIDADE: " + token << endl;
            movie.setPopularity(stod(token));
            //cout << "POPULARIDADE FILME: " << movies[i].getPopularity() << endl;

            // Campo production_companies
            string production_companies;
            getline(ss, token, ';');
            //cout << "TOKEN TESTE: "<<token << endl;
            production_companies = token;
            if (token[0] == '"') {
                while (token.back() != '"') {
                    getline(ss, token, ';');
                    production_companies += token;
                }
            }
            movie.setProductionCompanies(production_companies.c_str(), 100);


            // Campo production_countries
            string production_countries;
            getline(ss, token, ';');
            production_countries = token;
            if (token[0] == '"') {
                while (token.back() != '"') {
                    getline(ss, token, ';');
                    production_countries += token;
                }
            }
            movie.setProductionCountries(production_countries.c_str(), 100);


            // Campo 'release_date'
            getline(ss, token, ';');

            movie.setReleaseDate(token.c_str());

            // Campo 'revenue'
            getline(ss, token, ';');

            movie.setRevenue(stod(token));

            // Campo 'runtime'
            getline(ss, token, ';');

            movie.setRuntime(stod(token));

            // Campo 'spoken_languages'
            getline(ss, token, ';');
            movie.setSpokenLanguages(token.c_str(), 100);



            // Campo 'title'
            string title;
            getline(ss, token, ';');
            title = token;
            if (token[0] == '"') {
                while (token.back() != '"') {
                    getline(ss, token, ';');
                    title += token;
                }
            }
            movie.setTitle(title.c_str());

            // Campo 'vote_average'
            getline(ss, token, ';');
    //        cout << endl << token;
            movie.setVoteAverage(stod(token));

            // Campo 'vote_count'
            getline(ss, token, ';');
            movie.setVoteCount(stoi(token));
            dataSet.push_back(movie);
        }
        file.close();
        cout << "TOTAL FILMES: " << c << endl;
        return dataSet;
    }
    else{
        cout << "Falha ao abrir arquivo .csv" << endl;
        exit(-1);
    }


}*/

int getNumMovies(const string& filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        return 0;
    }

    string line;
    getline(file, line); // Ignorar a primeira linha (cabeçalho)

    int numMovies = 0;
    while (getline(file, line)) { // Contar o número de linhas no arquivo (número de filmes)
        numMovies++;
    }
    return numMovies;
}

Movie* readCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        cerr << "Erro: " << strerror(errno) << endl; // Imprime uma mensagem de erro mais detalhada
        return nullptr;
    }

    string line;
    getline(file, line); // Ignorar a primeira linha (cabeçalho)

    int numMovies = 0;
    while (getline(file, line)) numMovies++; // Contar número de filmes
    file.clear();
    file.seekg(0, ios::beg);
    getline(file, line); // Ignorar a primeira linha (cabeçalho) novamente

    Movie* movies = new Movie[numMovies]; // Alocar dinamicamente um array de Movie

    for (int i = 0; i < numMovies; i++){
        string auxLine;
        getline(file, auxLine);
        line = auxLine;

        stringstream ss(line);
        string token;

        getline(ss, token, ';'); // Ignorar o primeiro token (índice)

        //adulto
        bool adult;
        movies[i].setAdult(adult);
        std::getline(ss, token, ';');

        //ler genre
        getline(ss, token, ';');
        movies[i].setGenres(token.c_str(), token.size());

        // Campo 'id'
        getline(ss, token, ';');
        movies[i].setId(stoi(token));

        // Campo 'imdb_id'
        getline(ss, token, ';');
        movies[i].setImdbId(token.c_str());

        // Campo 'original_language'
        getline(ss, token, ';');
        movies[i].setOriginalLanguage(token.c_str());

        // Campo 'original_title'
        string original_title;
        getline(ss, token, ';');
        original_title = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                original_title += token;
            }
        }
        movies[i].setOriginalTitle(original_title.c_str());

        // Campo 'popularity'
        getline(ss, token, ';');
        movies[i].setPopularity(stod(token));

        // Campo production_companies
        string production_companies;
        getline(ss, token, ';');
        production_companies = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                production_companies += token;
            }
        }
        movies[i].setProductionCompanies(production_companies.c_str(), token.size());

        // Campo production_countries
        string production_countries;
        getline(ss, token, ';');
        production_countries = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                production_countries += token;
            }
        }
        movies[i].setProductionCountries(production_countries.c_str(), token.size());

        // Campo 'release_date'
        getline(ss, token, ';');
        movies[i].setReleaseDate(token.c_str());

        // Campo 'revenue'
        getline(ss, token, ';');
        movies[i].setRevenue(stod(token));

        // Campo 'runtime'
        getline(ss, token, ';');
        movies[i].setRuntime(stod(token));

        // Campo 'spoken_languages'
        getline(ss, token, ';');
        movies[i].setSpokenLanguages(token.c_str(), token.size());

        // Campo 'title'
        string title;
        getline(ss, token, ';');
        title = token;
        if (token[0] == '"') {
            while (token.back() != '"') {
                getline(ss, token, ';');
                title += token;
            }
        }
        movies[i].setTitle(title.c_str());

        // Campo 'vote_average'
        getline(ss, token, ';');
        movies[i].setVoteAverage(stod(token));

        // Campo 'vote_count'
        getline(ss, token, ';');
        movies[i].setVoteCount(stoi(token));

        // Campo 'overview'
        string overview = original_title + production_companies + title;
        movies[i].setOverview(overview.c_str());
    }

    file.close();
    return movies;
}

// Função para escrever os dados de um vetor de Movie em um arquivo binário
void writeBinaryFile(const string& filename) {
    ofstream outFile(filename, ios::binary | ios::out);
    if (!outFile.is_open()) {
        cout << "Erro ao abrir o arquivo " << filename << " para escrita." << endl;
        return;
    }

    string fileCsv = globalPath + "/movies_dataset2.csv";
    Movie* movies = readCSV(fileCsv);
    int numMovies = getNumMovies(fileCsv); // Contar número de filmes

    for (int i = 0; i < numMovies; i++) {
        // Escrever campo 'adult'
        bool adult = movies[i].isAdult();
        outFile.write((char*)&adult, sizeof(bool));

        // Escrever campo 'id'
        int id = movies[i].getId();
        outFile.write((char*)&id, sizeof(int));

        // Escrever campo 'imdb_id'
        outFile.write(movies[i].getImdbId(), sizeof(char) * 10);

        // Escrever campo 'original_language'
        outFile.write(movies[i].getOriginalLanguage(), sizeof(char) * 3);

        // Escrever campo 'original_title'
        outFile.write(movies[i].getOriginalTitle(), sizeof(char) * 200);

        // Escrever campo 'overview'
        outFile.write(movies[i].getOverview(), sizeof(char) * 1000);

        // Escrever campo 'popularity'
        double popularity = movies[i].getPopularity();
        outFile.write((char*)&popularity, sizeof(double));

        // Escrever campos dos gêneros
        outFile.write(movies[i].getGenres(), sizeof(char) * 200);

        // Escrever campos das empresas de produção
        outFile.write(movies[i].getProductionCompanies(), sizeof(char) * 200);

        // Escrever campos dos países de produção
        outFile.write(movies[i].getProductionCountries(), sizeof(char) * 200);

        // Escrever campo 'release_date'
        outFile.write(movies[i].getReleaseDate(), sizeof(char) * 11);

        // Escrever campo 'revenue'
        double revenue = movies[i].getRevenue();
        outFile.write((char*)&revenue, sizeof(double));

        // Escrever campo 'runtime'
        double runtime = movies[i].getRuntime();
        outFile.write((char*)&runtime, sizeof(double));

        // Escrever campos dos idiomas falados
        outFile.write(movies[i].getSpokenLanguages(), sizeof(char) * 200);

        // Escrever campo 'title'
        outFile.write(movies[i].getTitle(), sizeof(char) * 200);

        // Escrever campo 'vote_average'
        double vote_average = movies[i].getVoteAverage();
        outFile.write((char*)&vote_average, sizeof(double));

        // Escrever campo 'vote_count'
        int vote_count = movies[i].getVoteCount();
        outFile.write((char*)&vote_count, sizeof(int));
    }

    outFile.close();
    cout << "Arquivo binario gravado com sucesso!" << endl;
}

Movie* Movie::import(int n){
    ifstream bin;
    bin.open("../movies_dataset.bin", ios::binary | ios::in);

    if (!bin.is_open()) {
        string filename = "../movies_dataset.bin";
        writeBinaryFile(filename);
        bin.open(filename, ios::binary | ios::in);
    }

    Movie* vector = new Movie[n]();

    // Variáveis para leitura
    bool adult;
    char genres[200], imdb_id[10], original_language[3], original_title[200], production_countries[200],
    production_companies[200], release_date[11], spoken_languages[200], title[200], overview[1000];
    int id, vote_count;
    double popularity, revenue, runtime, vote_average;

    for (int i = 0; i < n; i++) {

        int index = rand() % 44714;
        // int i = index;
        bin.seekg(index * (sizeof(Movie) - 15), ios::beg);

        bin.read((char*)&adult, sizeof(bool));
        bin.read((char*)&id, sizeof(int));
        bin.read((char*)&imdb_id, 10*sizeof(char));
        bin.read((char*)original_language, 3*sizeof(char));
        bin.read((char*)original_title, 200*sizeof(char));
        bin.read((char*)overview, 1000*sizeof(char));
        bin.read((char*)&popularity, sizeof(double));
        bin.read((char*)genres, 200*sizeof(char));
        bin.read((char*)production_companies, 200*sizeof(char));
        bin.read((char*)production_countries, 200*sizeof(char));
        bin.read((char*)release_date, 11*sizeof(char));
        bin.read((char*)&revenue, sizeof(double));
        bin.read((char*)&runtime, sizeof(double));
        bin.read((char*)spoken_languages, 200*sizeof(char));
        bin.read((char*)title, 200*sizeof(char));
        bin.read((char*)&vote_average, sizeof(double));
        bin.read((char*)&vote_count, sizeof(int));

        vector[i].setAdult(adult);
        vector[i].setId(id);
        vector[i].setImdbId(imdb_id);
        vector[i].setOriginalLanguage(original_language);
        vector[i].setOriginalTitle(original_title);
        vector[i].setOverview(overview);
        vector[i].setPopularity(popularity);
        vector[i].setReleaseDate(release_date);
        vector[i].setRevenue(revenue);
        vector[i].setRuntime(runtime);
        vector[i].setTitle(title);
        vector[i].setVoteAverage(vote_average);
        vector[i].setVoteCount(vote_count);
        vector[i].setGenres(genres, 200);
        vector[i].setProductionCompanies(production_companies, 200);
        vector[i].setProductionCountries(production_countries, 200);
        vector[i].setSpokenLanguages(spoken_languages, 200);
        vector[i].setBinaryIndex(index);

        // Exibir os dados do filme
        // cout << "Filme " << i + 1 << ":\n";
        // cout << "Adult: " << adult << endl;
        // cout << "ID: " << id << endl;
        // cout << "IMDB ID: " << imdb_id << endl;
        // cout << "Original Language: " << original_language << endl;
        // cout << "Original Title: " << original_title << endl;
        // cout << "Overview: " << overview << endl;
        // cout << "Genres: " << genres << endl;
        // cout << "Production Companies: " << production_companies << endl;
        // cout << "Production Countries: " << production_countries << endl;
        // cout << "Release Date: " << release_date << endl;
        // cout << "Revenue: " << revenue << endl;
        // cout << "Runtime: " << runtime << endl;
        // cout << "Spoken Languages: " << spoken_languages << endl;
        // cout << "Title: " << title << endl;
        // cout << "Vote Average: " << vote_average << endl;
        // cout << "Vote Count: " << vote_count << endl;
        // cout << "---------------------------\n";
    }
    return vector;
}

