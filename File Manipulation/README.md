# Exercício 1 - Manipulação de Arquivos em C++
 
A manipulação de arquivos em C++ é uma parte fundamental da programação, permitindo que os programas interajam com dados persistentes armazenados em arquivos 
no sistema de arquivos do computador. 

Nesta atividade deve-se usar as bibliotecas de entrada (ifstream) e saída (ofstream) de arquivos (fstream) para a escrita e leitura de arquivos binários. 

 ## Problema Proposto

Neste exercícios desejamos converter uma base de dados em formato texto para um arquivo binário.
Para tanto, utilizaremos a base de dados que está disponível no arquivo Top50Imdb.csv. Essa base de dados armazena informações dos 50 filmes melhores avaliado no IMDb.

- O IMDb (Internet Move Database) é uma das maiores base de dados online sobre cinema e tudo o que envolve a indústria do entretenimento. Além de reunir informações sobre artistas e produções, o site também permite que usuários criem listas e avaliem seus filmes favoritos.

Para cada filme registrado, temos as seguintes informações:

 - **Movie Name**: o título de cada filme, representando obras-primas icônicas que deixaram uma marca indelével na indústria cinematográfica e no público em todo o mundo.
 - **Year of Release**: o ano em que cada filme foi lançado
 - **Watch Time**: duração do filme
 - **Movie Rating**: avaliações de usuários da IMDb, servindo como referência para avaliar a recepção e apreciação do público.
 - **Metascore of Movie**: metascores de críticos renomados, oferecendo insights sobre a aclamação e o reconhecimento da crítica dos filmes.
 - **Gross Earnings**: os ganhos de bilheteria em todo o mundo, refletindo o sucesso comercial e a popularidade de cada filme.

Neste exercícios, dois programas precisam ser implementados. 

### Programa 1

O primeiro programa deve ler o arquivo texto Top50Imdb.csv e exporta-lo para o arquivo Top50Imdb.dat em formato binário.

O programa principal deve estar no [exporta.cpp](exporta.cpp). Já há um código no arquivo que pega argumentos por linha de comando. Dessa forma, 
para executar o programa, faça:
```bash

./exporta Top50Imdb.csv Top50Imdb.dat

```
Você pode criar arquivos fontes auxlilares desde que mantenha a função main no exporta.cpp


### Programa 2

O segundo programa deve ler o arquivo binário, receber como entrada uma valor entre 0 e 49 e imprimir as informações do filme na tela.
O programa principal deve ser implementado em [testa.cpp](testa.cpp).  Novamente, a implementação já disponível obtém os dados necessários para a execução
via argumento passado na linha de comando, conforme o exemplo abaixo.

```bash

./testa Top50Imdb.dat 8

```

**Atenção**

Para a execução do exemplo acima, a saida deve seguir rigorosamente a formatação abaixo:

```bash
Movie Name: Pulp Fiction
Year of Release: 1994
Watch Time: 154
Movie Rating: 8.9
Metascore of Movie: 95
Gross Earnings: 107.93
```

## Compilação

Já foi disponibilizado um [CMakeLists.txt](CMakeLists.txt) padrão que gera os scripts de compilação dos dois programas. 

**Importante**: Caso novos arquivos-fontes (cpp  e/ou h) forem includidos a linha com o comando add_executable do CMakeLists.txt precisa ser atualizada.

Para compilar, execute os seguintes comandos:

```bash

mkdir build
cd build
cmake ..

```
Os comandos acima deve ser executados no diretório raiz do projeto. 
O comano *mkdir* cria um diretorio chamado build. O comando *cd* faz com que você entre no diretório build.
No comando *cmake ..* , o *..* indica que o script CMakeLists.txt está no diretório pai do atual.

Para compilar, basta fazer:
```bash
make
```
Observe que os executáveis estarão no diretório.

Para executar o código dentro do diretório build, basta fazer:
```bash
./exporta ../Top50Imdb.csv Top50Imdb.dat
```
Observe que o prefixo '../' no top1000imdb.csv indica que arquivo não está em build mas no diretório pai. Por outro lado, 
Top50Imdb.dat será escrito dentro do diretório build.

** Atenção ** 
Se seu sistema não tem cmake, geralmente a instalação em ambiente baseados no Ubuntu (incluindo o WSL/Windows) é realizada na seguinte forma:

```bash
sudo apt install cmake
```
