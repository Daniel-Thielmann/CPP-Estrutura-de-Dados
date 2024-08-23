[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/xEFNJSjM)
# Exercício 1 - Métodos de Ordenação
 
Os métodos de ordenação são algoritmos essenciais em ciência da computação usados para organizar conjuntos de dados em uma determinada ordem, como crescente ou decrescente, de acordo com critérios específicos. 
Existem diversas técnicas de ordenação, cada uma com suas características e eficiências distintas. Alguns exemplos incluem o algoritmo de ordenação por bolha, que compara pares de elementos adjacentes e os troca se estiverem na ordem errada; 
o algoritmo de ordenação por seleção, que seleciona repetidamente o menor (ou maior) elemento e o move para sua posição final; 
o algoritmo de ordenação por inserção, que constrói a solução ordenada um elemento de cada vez; Além desses, existem métodos mais sofisticados, como o mergesort e o quicksort, que são eficientes para grandes conjuntos de dados. 
A escolha do método de ordenação adequado depende do contexto específico, como o tamanho do conjunto de dados, a distribuição dos valores e os recursos computacionais disponíveis.

 ## Problema Proposto

Neste exercícios desejamos implementar três métodos de ordenação:
 - Um dos métodos mais simples: bolha ou seleção ou inserção.
 - Mergesort
 - Quicksort

Para tanto, iremos reutilizar a base de dados que está disponível no arquivo Top50Imdb.csv. 
Vocês devem reaproveitar a estrutura de dados e o código de exporta.cpp;


Neste exercícios, implementaremos uma biblioteca de ordenação e um programa que utiliza a biblioteca. 

### Biblioteca sort


O código da biblioteca deve estar no arquivo [sort.cpp](sort.cpp) e o cabeçalhos das funções devem ser definidos no arquivo [sort.h](sort.h).
Veja os comentários que estão nesses arquivos. 

Observe que foi incluido no [CMakeLists.txt](CMakeLists.txt) uma linha que indica a criação da biblioteca sort no projeto. 

```
add_library(<name> [<type>] [EXCLUDE_FROM_ALL] <sources>...)
```

Cria uma biblioteca chamada *name* para ser construída a partir dos arquivos listados na invocação do comando (*sources*).
O opcional *type* especifica o tipo de biblioteca a ser criado:
- STATIC: Um arquivo de objeto para uso ao vincular outros alvos. 
- SHARED: Uma biblioteca dinâmica que pode ser vinculada por outros alvos e carregada em tempo de execução.

### Programa Ordena

O programa ordena deve ler o arquivo binário colocando os registros em um vetor, receber como entrada um valor entre 1 e 3 indicando o método de ordenação, ordenar os filmes pelo nome e salvar as informações em um arquivo 
texto. O programa principal deve ser implementado em [ordena.cpp](ordena.cpp).  Veja os comentários indicados no arquivo.

**Atenção**

Para a execução do exemplo acima, o arquivo texto resultande deve seguir rigorosamente a formatação abaixo:

```bash
NOME                                              Year    Metascore 
Pulp Fiction                                      1924    95        

```

 - Espaço reservado para o nome: 50 caracteres
 - Espaço reservad para ano: 8 caracteres
 - Espaço reservado para metascore: 10 caracteres

## Compilação

Já foi disponibilizado um [CMakeLists.txt](CMakeLists.txt) padrão que gera os scripts de compilação dos dois programas. 

**Importante**: 
- Caso novos arquivos-fontes (cpp  e/ou h) forem includidos a linha com o comando add_executable e/ou add_library do CMakeLists.txt precisa(m) ser atualizada(s).
- Note que o código [ordena.cpp](ordena.cpp) depende da biblioteca sort (faz uso de funções definida na bibluoteca). Essa dependencia é resolvida no CMake incluindo a linha abaixo no CMakeLists.txt.
```
target_link_libraries(ordena sort)
```

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
Observe que os executáveis estarão no diretório. Será gerada uma biblioteca libsort.a. 

Para executar o código dentro do diretório build: 
1. Preprocessar os dados (realizado para gerar .dat caso ainda não exista):
```bash
./exporta ../Top50Imdb.csv Top50Imdb.dat
```
Observe que o prefixo '../' no top1000imdb.csv indica que arquivo não está em build mas no diretório pai. Por outro lado, 
Top50Imdb.dat será escrito dentro do diretório build.

2. Executar o ordena:
```bash
./exporta Top50Imdb.dat 1
```

