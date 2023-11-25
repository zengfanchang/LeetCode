#include <iostream>
#include <queue>
using namespace std;

// Huffman树节点
struct Node {
    int weight;
    Node* left;
    Node* right;

    Node(int w) : weight(w), left(nullptr), right(nullptr) {}
};

// 比较函数用于优先队列排序
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->weight > b->weight;
    }
};

// 生成Huffman树
Node* generateHuffmanTree(priority_queue<Node*, vector<Node*>, Compare>& pq) {
    while (pq.size() > 1) {
        Node* leftChild = pq.top();
        pq.pop();
        Node* rightChild = pq.top();
        pq.pop();

        Node* parent = new Node(leftChild->weight + rightChild->weight);
        parent->left = leftChild;
        parent->right = rightChild;

        pq.push(parent);
    }

    return pq.top();
}

// 打印Huffman树的结构
void printHuffmanTree(Node* root, string prefix = "") {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        cout << prefix << " - " << root->weight << endl;
        return;
    }

    cout << prefix << " - " << root->weight << endl;
    printHuffmanTree(root->left, prefix + "0");
    printHuffmanTree(root->right, prefix + "1");
}

int main() {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // 依次插入节点
    pq.push(new Node(8));
    printHuffmanTree(pq.top());
    cout << endl;

    pq.push(new Node(9));
    printHuffmanTree(pq.top());
    cout << endl;

    pq.push(new Node(5));
    printHuffmanTree(pq.top());
    cout << endl;

    pq.push(new Node(2));
    printHuffmanTree(pq.top());
    cout << endl;

    pq.push(new Node(10));
    printHuffmanTree(pq.top());
    cout << endl;

    // 生成Huffman树
    Node* root = generateHuffmanTree(pq);

    // 打印Huffman树的结构
    cout << "Huffman Tree:" << endl;
    printHuffmanTree(root);

    return 0;
}
