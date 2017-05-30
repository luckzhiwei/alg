#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define  NIL -1
#define  oo 65535

using namespace std;

class Node;

class Link {
public:
    Link(int w, int number, Node *node) : mWeight(w), mNum(number), mNode(node) {};
    Node *mNode;
    int mWeight;
    int mNum;
};

class Node {
public:
    Node() {};

    Node(int num) : number(num), key(oo), pre(NIL) {};
    vector<Link> Adj;
    int number;
    int key;
    int pre;
};


vector<Node *> graph;


void init(const vector<string> &info, int nodesCount) {
    for (int i = 1; i <= nodesCount; i++) {
        Node *node = new Node(i);
        graph.push_back(node);
    }
    for (auto it = info.begin(); it != info.end(); it++) {
        int index = it->at(0) - 0x30;
        int vectorN = it->at(2) - 0x30;
        int value = -1;
        if (it->length() == 5) {
            value = it->at(4) - 0x30;
        } else {
            value = (it->at(4) - 0x30) * 10 + (it->at(5) - 0x30);
        }
        graph[index - 1]->Adj.push_back(Link(value, vectorN, graph[vectorN - 1]));
    }
}

void prim(int startNum) {
    graph[startNum - 1]->key = 0;
    set<int> vectorSet;
    vectorSet.insert(startNum);
    vector<Node *> graphCopy = graph;
    make_heap(graphCopy.begin(), graphCopy.end(), [](const Node *node1, const Node *node2) {
        return node1->key > node2->key;
    });

    while (!graphCopy.empty()) {
        int index = graphCopy.front()->number;
        for (auto it = graph[index - 1]->Adj.begin(); it != graph[index - 1]->Adj.end(); it++) {
            if (vectorSet.find(it->mNum) == vectorSet.end() && it->mWeight < it->mNode->key) {
                it->mNode->key = it->mWeight;
                it->mNode->pre = index;
            }
        }

        pop_heap(graphCopy.begin(), graphCopy.end(), [](const Node *node1, const Node *node2) {
            return node1->key > node2->key;
        });
        graphCopy.pop_back();
        make_heap(graphCopy.begin(), graphCopy.end(), [](const Node *node1, const Node *node2) {
            return node1->key > node2->key;
        });
        vectorSet.insert(index);
    }
    return;
}

int main() {
    vector<string> info;

    info.push_back(string("2 3 11"));
    info.push_back(string("3 2 11"));

    info.push_back(string("1 2 4"));
    info.push_back(string("2 1 4"));

    info.push_back(string("1 3 8"));
    info.push_back(string("3 1 8"));

    info.push_back(string("2 5 8"));
    info.push_back(string("5 2 8"));

    info.push_back(string("4 5 2"));
    info.push_back(string("5 4 2"));

    info.push_back(string("4 6 6"));
    info.push_back(string("6 4 6"));

    info.push_back(string("6 8 2"));
    info.push_back(string("8 6 2"));

    info.push_back(string("7 8 14"));
    info.push_back(string("8 7 14"));

    info.push_back(string("7 9 9"));
    info.push_back(string("9 7 9"));

    info.push_back(string("8 9 10"));
    info.push_back(string("9 8 10"));

    info.push_back(string("5 7 7"));
    info.push_back(string("7 5 7"));

    info.push_back(string("3 4 7"));
    info.push_back(string("4 3 7"));

    info.push_back(string("3 6 1"));
    info.push_back(string("6 3 1"));

    info.push_back(string("5 8 4"));
    info.push_back(string("8 5 4"));

    init(info, 9);
    prim(1);

    return 0;
}

