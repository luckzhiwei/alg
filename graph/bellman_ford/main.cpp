#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define  NIL -1
#define  oo 65535

using namespace std;

class Node;


class Edge {
public:
    Edge() {};

    Edge(int s, int e, int w) : start(s), end(e), weight(w) {};
    int weight;
    int start;
    int end;
};

class Node {
public:
    Node() {};

    Node(int num) : number(num), dis(oo) {};
    vector<int> disTable;
    int number;
    int dis;
};


vector<Node> points;

vector<Edge> edges;

void init(vector<string> &info, int nodesCount) {
    for (int i = 1; i <= nodesCount; i++) {
        points.push_back(Node(i));
    }
    for (auto it = info.begin(); it != info.end(); it++) {
        int start = it->at(0) - 0x30;
        int end = it->at(2) - 0x30;
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
        edges.push_back(Edge(start, end, weight));
    }
}

void doReleax(vector<int> &disTable, int u, int v, int w) {
    int tmp = disTable[v - 1] + w;
    if (disTable[u - 1] > tmp) {
        disTable[u - 1] = tmp;
    }
}

/*
 *
 * bellman-ford 是 v*e 的复杂度，为什么呢？
 * 只要没有负向环，那么，bellman-ford 在经过v*e次的松弛之后，
 * 确实可以求解。（因为bellman-ford在v*e次之后，保证了先前松弛过的点，在后续松弛过程后，能再次进一步的松弛）
 */


void bellmanFord(int num) {
    int nodeNum = points.size();
    points[num - 1].disTable.resize(nodeNum, oo);
    points[num - 1].disTable[num - 1] = 0;
    int edgeNum = edges.size();
    for (int i = 0; i < nodeNum; i++) {
        for (int j = 0; j < edgeNum; j++) {
            doReleax(points[num - 1].disTable, edges[j].end, edges[j].start, edges[j].weight);
        }
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
    bellmanFord(1);
    return 0;
}