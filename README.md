# CPP-Estrutura-de-Dados
Estruturas de Dados aplicadas em C++:

1. Introdução à Análise de complexidade;
2. Recursividade;
3. Ponteiros e Alocação Dinâmica de Memória;
4. Tipos Abstratos de Dados;
5. Matrizes;
6. Listas;
7. Pilhas e Filas;
8. Árvores;
9. Heaps (fila de prioridades);
10. Grafos;
11. Algoritmo de Ordenação (Métodos Seleção, MergeSort, Quicksort e Heapsort...);
12. Tabelas Hash;
13. Trees (Árvore AVL, Árvore Vermelho-Preto, Árvores B, Árvores B+., Árvore splay, Árvore espalhamento, KD-Tree, Árvore R;
14. Estruturas de dados para web (Tries. Trie R-Way. Trie Ternária. Árvore PATRICIA);
15. Processamento de Cadeia de caracteres e Compressão (KMP, BMs e Robin-Karp, Compressão de Textos em Linguagem Natural, RLE, Codificação de Huffman, Lempel-Ziv).


# TRABALHO PRÁTICO

Introdução
Neste trabalho, utilizaremos uma base de dados do Kaggle que contem informações de contém diversas informações sobre aproximadamente 45 mil filmes, incluindo metadados detalhados. O conjunto de dados é composto por arquivos CSV que abrangem informações como:
Dados gerais de filmes (títulos, datas de lançamento, gêneros), avaliações e dados de usuários do TMDb e do IMDb, palavras-chave e empresas de produção.
Os dados estão armazenados no arquivo movies_dataset.zip no formato CSV disponibilizado junto desse documento.

Objetivos

O objetivo principal deste trabalho é dar ao aluno a oportunidade de manipular uma base de dados real de médio porte usando as estruturas de dados vistas na disciplina. Espera-se que o aluno seja capaz de: Manipular adequadamente arquivos em modo texto e binário.
Compreender, implementar corretamente algoritmos de ordenação, indexação e compressão de dados. Analisar o desempenho dos algoritmos implementados segundo o referencial teórico adquirido na disciplina; Apresentar os resultados obtidos com o trabalho de maneira formal.

Desenvolvimento 

Etapa 1: Definição de uma estrutura de dados
Nesta etapa, o aluno deve propor um tipo abstrato de dados (TAD). Considere os seguintes aspectos importantes:
Encapsulamento: Use structs ou classes para agrupar dados e funções que operam nesses dados, escondendo detalhes internos.
Interface Clara: Defina funções públicas que constituem a interface do TAD, permitindo que os usuários interajam com ele sem conhecer a implementação interna.
Modularidade: Separe a implementação da interface. Use arquivos .h para a interface e .cpp para a implementação.
Documentação: Comente o código para explicar a finalidade de cada função e membro da estrutura.
Manipulação de Memória: Garanta alocação e liberação adequadas de memória, evitando vazamento.

Etapa 2: Processamento dos dados
Nessa fase, o aluno deve analisar o arquivo CSV fornecido e desenvolver:
Uma rotina para convertê-lo em um arquivo binário. O programa deve ler o arquivo de texto, extrair cada atributo de um filme e salvar essas informações no arquivo binário. Tratamento de exceções é necessário para alguns campos, e o grupo tem liberdade para escolher como lidar com esses casos. 
Duas rotinas extrações de dados o arquivo binário:	
Extrair todos os filmes para um vetor de filmes.
Extrair N filmes aleatórios da base de dados (N < numero total de filmes) para um vetor de filmes.

Etapa 3: Análise de algoritmos de ordenação
Nesta etapa, você irá comparar o desempenho de diferentes algoritmos de ordenação quando aplicados sobre os dados pré-processados. O seu programa deverá seguir os seguintes passos:
importar conjuntos de N registros aleatórios do arquivo binário gerado pelo pré-processamento
realizar a ordenação desses registros, utilizando como chave de ordenação popularity. Durante a ordenação, deverão ser computados o total de comparações de chaves e o total de movimentações de chaves. Além disso, o tempo de execução do algoritmo deverá ser medido.
Para gerar as estatísticas de desempenho, você deverá executar os passos acima para 3 diferentes conjuntos de N registros aleatórios. Ao final, compute as médias de cada uma das métricas (comparações, movimentações e tempo).  Você deverá realizar a simulação descrita acima para os seguintes valores de N:

5000
10000
20000
40000

Para esta etapa, escreva um programa chamado compara_sort.cpp que faça essas analises de desempenho. O programa deve fazer a leitura dos valores de N (a lista acima) a partir de um arquivo chamado compara_sort.dat. Salve todos os resultados obtidos em um arquivo compara_sort.out, contendo tanto os resultados individuais quanto a média final.

Para a ordenação, você deverá utilizar no mínimo 3 algoritmos: 

Quicksort 
Heapsort 
Um terceiro algoritmo à sua escolha.


Aplicação - Gêneros mais frequentes
Aqui você deve criar um TAD Hash para auxiliar na contagem de filmes classificados por vote_average. O programa deve ler N filmes aleatórios e contar quantos filmes receberam um determinado vote_average.
Utilize uma tabela hash para armazenar os vote_average dos filmes. A função hash deve ser rápida e gerar poucas colisões, além de ocupar a tabela uniformemente. Escolha um método adequado para tratar colisões.
Para cada filme lido, insira a string de vote_average na tabela hash. No final, o programa deve imprimir o número de filmes para 5 maiores vote_average, ordenados em ordem crescente de frequência. Use o algoritmo de ordenação com melhor desempenho da Etapa 2.
Nomeie seu executável com vote_average_hash. Seu programa deve ler do arquivo de entrada vote_average.dat o valor de N. O resultado deve ser escrito no arquivo vote_average.txt.


Etapa 4 - Análise das estruturas balanceadas
Seu grupo deverá implementar duas estruturas de dados em árvore: 
Árvore Vermelho-Preto
Árvore B. 
O tipo abstrato de dados deve implementar as operações de inserção e busca (não há necessidade de implementar a remoção). Cada nó deve armazenar o id da avaliação e a sua localização no arquivo binário. A ordenação da árvore será determinada pelo id. As outras informações do registro, quando necessárias, serão recuperadas através do acesso ao disco. 

Nesta etapa, você irá comparar o desempenho das estruturas implementadas quanto às operações de inserção e busca. O seu programa deverá seguir os seguintes passos:
importar conjuntos de N registros aleatórios do arquivo binário gerado pelo pré-processamento;
realizar a inserção desses registros na estrutura. Durante a inserção, deverão ser computados o total de comparações de chaves e o tempo de execução;
realizar a busca de outros B registros aleatórios na estrutura. Durante as buscas, também deverão ser computados o total de comparações de chaves e o tempo de execução;

Para gerar as estatísticas de desempenho, você deverá executar os passos acima, minimamente, M = 3 vezes, para N = 20000. Ao final, compute as médias de cada uma das métricas (comparações e tempo) obtidas para as M execuções. 
As estruturas de dados que devem ser analisadas são as seguintes:

Árvore Vermelho-Preto
Árvore B (m = 20)
Árvore B (m = 200)

Considere que a ordem m da árvore B representa o número máximo de filhos em cada nó (exceto a raiz), conforme visto em sala de aula. Não há necessidade de se manter preso aos valores de m especificados acima, o grupo pode adotar valores diferentes (ou mais que dois valores) para os testes. Tenha o cuidado, no entanto, de escolher valores que permitam avaliar a diferença no desempenho para árvores de ordem baixa e árvores de ordem alta.
O seu programa deve se chamar compara_tree e deve salvar todos os resultados obtidos em um arquivo compara_tree.txt, contendo tanto os resultados individuais quanto a média final.

Etapa 5 -  Compressão dos Overviews
Deve-se implementar o método de compressão de Huffman para o processamento de uma cadeia de caracteres aleatória. Esta cadeia de caracteres será formada pela concatenação dos overview dos N registros aleatórios importados. Deve-se implementar as rotinas de compressão e descompressão.
O programa deve se chamar compress e possuir opções de menu para:
Comprimir um conjunto de N (definido pelo usuário) review_overview aleatórios e salvar dois arquivos: overviewOrd.txt (texto original)e overviewComp.bin (texto comprimido);
Descomprimir o arquivo overviewComp.bin e salvar o texto resultante em um arquivo overviewDecomp.bin;
