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

void breathFirstSearch(int n) {
    queue<Node> queue;
    graph[n - 1].color = GRAY;
    queue.push(graph[n - 1]);
    while (!queue.empty()) {
        Node &node = queue.front();
        for (auto it = node.Adj.begin(); it != node.Adj.end(); it++) {
            int index = *it;
            if (graph[index - 1].color == WHITE) {
                Node &nodeAdj = graph[index - 1];
                nodeAdj.pre = node.number;
                nodeAdj.color = GRAY;
                queue.push(nodeAdj);
            }
        }
        queue.pop();
        node.color = BALCK;
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
    breathFirstSearch(1);
    return 0;
}