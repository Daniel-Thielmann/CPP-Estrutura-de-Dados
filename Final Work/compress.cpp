#include "compress.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

void Huffman::compress(const std::string& inputFile, const std::string& outputFile) {
    ifstream inFile(inputFile, ios::in);
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return;
    }

    string data((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));
    cout << data << endl;
    inFile.close();

    HuffmanNode* root = buildHuffmanTree(data);

    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    string compressedData;
    for (char ch : data) {
        compressedData += huffmanCodes[ch];
    }

    ofstream outFile(outputFile, ios::binary);
    if (!outFile) {
        cerr << "Erro ao abrir o arquivo de saída!" << endl;
        return;
    }

    saveHuffmanTree(root, outFile);

    size_t originalSize = data.size();
    outFile.write(reinterpret_cast<const char*>(&originalSize), sizeof(originalSize));

    size_t numBits = compressedData.size();
    outFile.write(reinterpret_cast<const char*>(&numBits), sizeof(numBits));

    for (size_t i = 0; i < compressedData.size(); i += 8) {
        bitset<8> bits(compressedData.substr(i, 8));
        outFile.put(static_cast<unsigned char>(bits.to_ulong()));
    }
    outFile.close();

    freeTree(root);
}

void Huffman::decompress(const std::string& inputFile, const std::string& outputFile) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return;
    }

    HuffmanNode* root = loadHuffmanTree(inFile);

    size_t originalSize;
    inFile.read(reinterpret_cast<char*>(&originalSize), sizeof(originalSize));

    size_t numBits;
    inFile.read(reinterpret_cast<char*>(&numBits), sizeof(numBits));

    string compressedData;
    while (inFile) {
        unsigned char byte;
        inFile.read(reinterpret_cast<char*>(&byte), sizeof(byte));
        compressedData += bitset<8>(byte).to_string();
    }
    inFile.close();

    string decompressedData;
    HuffmanNode* current = root;
    for (size_t i = 0; i < numBits; ++i) {
        if (compressedData[i] == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right) {
            decompressedData += current->data;
            current = root;
        }
    }

    ofstream outFile(outputFile, ios::out);
    outFile << decompressedData.substr(0, originalSize);
    outFile.close();

    freeTree(root);
}

HuffmanNode* Huffman::buildHuffmanTree(const string& data) {
    unordered_map<char, unsigned> freq;
    for (char ch : data) {
        freq[ch]++;
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* node = new HuffmanNode('\0', left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    }

    return pq.top();
}

void Huffman::generateCodes(HuffmanNode* root, const string& str,
                            unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->data] = str;
    }

    generateCodes(root->left, str + "0", huffmanCodes);
    generateCodes(root->right, str + "1", huffmanCodes);
}

void Huffman::saveHuffmanTree(HuffmanNode* root, ofstream& outFile) {
    if (!root) return;

    if (!root->left && !root->right) {
        outFile.put(1);
        outFile.put(root->data);
    } else {
        outFile.put(0);
    }

    saveHuffmanTree(root->left, outFile);
    saveHuffmanTree(root->right, outFile);
}

HuffmanNode* Huffman::loadHuffmanTree(ifstream& inFile) {
    char bit;
    inFile.get(bit);

    if (bit == 1) {
        char data;
        inFile.get(data);
        return new HuffmanNode(data, 0);
    }

    HuffmanNode* node = new HuffmanNode('\0', 0);
    node->left = loadHuffmanTree(inFile);
    node->right = loadHuffmanTree(inFile);

    return node;
}

void Huffman::freeTree(HuffmanNode* root) {
    if (!root) return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
