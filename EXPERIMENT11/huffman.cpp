//NAME = SUHEL CHOUDHARY
//ROLL NO. = 25/DA/059

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << ": " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = sizeof(chars) / sizeof(chars[0]);

    huffman(chars, freq, n);

    return 0;
}