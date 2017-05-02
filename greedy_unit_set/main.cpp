#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Node {
public:
    Node *leftChild;
    Node *rightChild;
    int weight;

    Node(int w) : weight(w), leftChild(NULL), rightChild(NULL) {};
};


Node *huffManEncode(vector<Node *> &nodes) {
    int size = nodes.size();
    for (int i = 0; i < size - 1; i++) {
        sort(nodes.begin(), nodes.end(), [](const Node *node1, const Node *node2) {
            return node1->weight < node2->weight;
        });
        Node *parent = new Node(nodes[0]->weight + nodes[1]->weight);
        parent->leftChild = nodes[0];
        parent->rightChild = nodes[1];
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
        nodes.push_back(parent);
    }
    return nodes[0];
}

int main() {
    vector<Node *> nodes;
    nodes.push_back(new Node(12));
    nodes.push_back(new Node(9));
    nodes.push_back(new Node(5));
    nodes.push_back(new Node(13));
    nodes.push_back(new Node(45));
    nodes.push_back(new Node(16));
    Node *root = huffManEncode(nodes);
    return 0;
}