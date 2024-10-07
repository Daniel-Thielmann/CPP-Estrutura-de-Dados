#ifndef COMPRESS_H
#define COMPRESS_H

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(char d, unsigned f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

class Huffman {
public:
    void compress(const std::string& inputFile, const std::string& outputFile);
    void decompress(const std::string& inputFile, const std::string& outputFile);

private:
    HuffmanNode* buildHuffmanTree(const std::string& data);

    void generateCodes(HuffmanNode* root, const std::string& str,
                       std::unordered_map<char, std::string>& huffmanCodes);

    void saveHuffmanTree(HuffmanNode* root, std::ofstream& outFile);

    HuffmanNode* loadHuffmanTree(std::ifstream& inFile);

    void freeTree(HuffmanNode* root);
};

#endif // COMPRESS_H
