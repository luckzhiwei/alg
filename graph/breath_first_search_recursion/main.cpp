#include <iostream>
#include <vector>
#include <queue>

#define  WHITE 0
#define  GRAY  1
#define  BALCK 2
#define  NIL -1

using namespace std;

class Node {
public:
    Node(int num) : number(num), color(WHITE), pre(NIL) {};
    vector<int> Adj;
    int pre;
    int color;
    int number;
};

vector<Node> graph;
queue<int> queueGlobal;

void init(const vector<string> &info, int nodesCount) {
    for (int i = 1; i <= nodesCount; i++) {
        graph.push_back(Node(i));
    }
    for (auto it = info.begin(); it != info.end(); it++) {
        int index = it->at(0) - 0x30;
        int vectorN = it->at(2) - 0x30;
        graph[index - 1].Adj.push_back(vectorN);
    }
}


void breathFirstSearchRecurison(int count) {
    int v = 0;
    for (int i = 0; i < count; i++) {
        int number = queueGlobal.front();
        Node &node = graph[number - 1];
        for (auto it = node.Adj.begin(); it != node.Adj.end(); it++) {
            int index = *it;
            if (graph[index - 1].color == WHITE) {
                Node &nodeAdj = graph[index - 1];
                nodeAdj.pre = node.number;
                nodeAdj.color = GRAY;
                queueGlobal.push(index);
                v++;
            }
        }
        queueGlobal.pop();
        node.color = BALCK;
    }
    if (v != 0) {
        breathFirstSearchRecurison(v);
    }
}


int main() {
    vector<string> info;

    info.push_back(string("1 2"));
    info.push_back(string("2 1"));

    info.push_back(string("1 6"));
    info.push_back(string("6 1"));

    info.push_back(string("1 5"));
    info.push_back(string("5 1"));

    info.push_back(string("2 3"));
    info.push_back(string("3 2"));

    info.push_back(string("3 4"));
    info.push_back(string("4 3"));

    info.push_back(string("5 6"));
    info.push_back(string("6 5"));

    info.push_back(string("6 7"));
    info.push_back(string("7 6"));
    init(info, 7);
    queueGlobal.push(1);
    graph[0].color = GRAY;
    breathFirstSearchRecurison(1);
    return 0;
}