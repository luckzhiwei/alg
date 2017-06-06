#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define  oo 65535
using namespace std;

class Node;

class Link {
public:
    Link() {};

    Link(int w, int number, Node *node) : mWeight(w), mNum(number), mNode(node) {};
    Node *mNode;
    int mWeight;
    int mNum;
};


class Node {
public:
    Node() {};

    Node(int num) : mNum(num), isInQueue(false) {};
    int mNum;
    vector<Link> Adj;
    vector<int> disTable;
    bool isInQueue;
};

vector<Node *> graph;

void init(vector<string> &info, int nodesCount) {
    for (int i = 1; i <= nodesCount; i++) {
        graph.push_back(new Node(i));
    }
    for (auto it = info.begin(); it != info.end(); it++) {
        int index = it->at(0) - 0x30;
        int vectorN = it->at(2) - 0x30;
        int weight = -1;
        if (it->length() == 5) {
            weight = it->at(4) - 0x30;
        } else {
            if (it->at(4) == '-') {
                weight = (-1) * (it->at(5) - 0x30);
            } else {
                weight = (it->at(4) - 0x30) * 10 + (it->at(5) - 0x30);
            }
        }
        graph[index - 1]->Adj.push_back(Link(weight, vectorN, graph[vectorN - 1]));
    }
}

bool doReleax(vector<int> &disTable, int u, int v, int w) {
    int tmp = disTable[v - 1] + w;
    if (disTable[u - 1] > tmp) {
        disTable[u - 1] = tmp;
        return true;
    }
    return false;
}

void spfa(int num) {
    graph[num - 1]->disTable.resize(graph.size(), oo);
    graph[num - 1]->disTable[num - 1] = 0;
    graph[num - 1]->isInQueue = true;
    queue<Node *> nodeQueue;
    nodeQueue.push(graph[num - 1]);
    while (!nodeQueue.empty()) {
        Node *node = nodeQueue.front();
        int v = node->mNum;
        for (auto it = node->Adj.begin(); it != node->Adj.end(); it++) {
            int u = it->mNum;
            if (doReleax(graph[num - 1]->disTable, u, v, it->mWeight)) {
                if (!it->mNode->isInQueue) {
                    it->mNode->isInQueue = true;
                    nodeQueue.push(it->mNode);
                }
            }
        }
        nodeQueue.pop();
        node->isInQueue = false;
    }
}

int main() {
    vector<string> info;
    info.push_back(string("1 2 6"));
    info.push_back(string("1 3 7"));
    info.push_back(string("2 3 8"));
    info.push_back(string("3 5 9"));
    info.push_back(string("5 1 2"));
    info.push_back(string("5 4 7"));
    info.push_back(string("2 5 -4"));
    info.push_back(string("2 4 5"));
    info.push_back(string("4 2 -2"));
    info.push_back(string("3 4 -3"));
    init(info, 5);
    spfa(1);
    return 0;
}