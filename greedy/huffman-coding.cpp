#include <iostream>
#include <queue>
#include <unordered_map>

// Structure to represent a node in the Huffman tree
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue to arrange nodes in ascending order of frequency
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Function to build the Huffman tree and return the root node
HuffmanNode* buildHuffmanTree(std::unordered_map<char, int>& freqMap) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('#', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

// Function to generate Huffman codes for each character in the tree
void generateHuffmanCodes(HuffmanNode* root, std::string code, std::unordered_map<char, std::string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '#') {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode the input string using Huffman codes
std::string huffmanEncode(std::string input, std::unordered_map<char, std::string>& huffmanCodes) {
    std::string encoded = "";
    for (char ch : input) {
        encoded += huffmanCodes[ch];
    }
    return encoded;
}

// Function to decode the encoded string using Huffman tree
std::string huffmanDecode(std::string encoded, HuffmanNode* root) {
    std::string decoded = "";
    HuffmanNode* curr = root;
    for (char bit : encoded) {
        if (bit == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

        if (curr->data != '#') {
            decoded += curr->data;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    std::string input = "This is an example for huffman encoding developed by Himanshu Shukla. We need to be updated in the constant changing world. Here everyday is challenge and an opportunity to take out the best from you";
    
    // Calculate character frequencies in the input
    std::unordered_map<char, int> freqMap;
    for (char ch : input) {
        freqMap[ch]++;
    }

    // Build the Huffman tree
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // Generate Huffman codes for each character in the tree
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Encode the input string using Huffman codes
    std::string encoded = huffmanEncode(input, huffmanCodes);

    // Decode the encoded string using the Huffman tree
    std::string decoded = huffmanDecode(encoded, root);

    // Print the results
    std::cout << "Input string: " << input << std::endl;
    std::cout << "Encoded string: " << encoded << std::endl;
    std::cout << "Decoded string: " << decoded << std::endl;

    return 0;
}
