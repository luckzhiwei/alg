#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define  NIL -1
#define  oo 65535

using namespace std;

class Node;

class Path {
public:
    Path() : dis(oo) {}

    int dis;
    int pre;
};

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

    Node(int num) : number(num), dis(oo) {};
    vector<Link> Adj;
    vector<Path> disTable;
    int number;
    int dis;
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

void cleanDis() {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        Node *node = *it;
        node->dis = oo;
    }
}

void doReleax(vector<Node *> &queue, Node *node, int u, int v, int w) {
    int tmp = node->disTable[u - 1].dis + w;
    if (node->disTable[v - 1].dis > tmp) {
        node->disTable[v - 1].dis = tmp;
        graph[v - 1]->dis = tmp;
        node->disTable[v - 1].pre = u;
    }
}

void dijkstra(int num) {
    cleanDis();
    vector<Node *> queue = graph;
    graph[num - 1]->dis = 0;
    graph[num - 1]->disTable.resize(graph.size());
    graph[num - 1]->disTable[num - 1].dis = 0;
    graph[num - 1]->disTable[num - 1].pre = num;
    make_heap(queue.begin(), queue.end(), [](const Node *node1, const Node *node2) {
        return node1->dis > node2->dis;
    });
    while (!queue.empty()) {
        Node *node = queue.front();
        int u = node->number;
        for (auto it = node->Adj.begin(); it != node->Adj.end(); it++) {
            doReleax(queue, graph[num - 1], u, it->mNum, it->mWeight);
        }
        pop_heap(queue.begin(), queue.end(), [](const Node *node1, const Node *node2) {
            return node1->dis > node2->dis;
        });
        queue.pop_back();
        make_heap(queue.begin(), queue.end(), [](const Node *node1, const Node *node2) {
            return node1->dis > node2->dis;
        });
    }
    return;
}


int main() {
    vector<string> info;
    info.push_back(string("1 2 10"));
    info.push_back(string("1 3 5"));
    info.push_back(string("2 3 2"));
    info.push_back(string("3 2 3"));
    info.push_back(string("3 4 2"));
    info.push_back(string("2 5 1"));
    info.push_back(string("5 4 4"));
    info.push_back(string("4 5 6"));
    info.push_back(string("4 1 7"));
    info.push_back(string("3 5 9"));
    init(info, 5);
    dijkstra(1);

    for (auto it = graph[0]->disTable.begin(); it != graph[0]->disTable.end(); it++) {
        int dis = distance(graph[0]->disTable.begin(), it);
        if (dis == 0) {
            continue;
        }
        cout << "the num th is  " << dis+1 << endl;
        cout << "the dis is " << it->dis << endl;
        int pre = it->pre;
        cout << "path is";
        do {
            cout << "-->" << pre;
            pre = graph[0]->disTable[pre - 1].pre;
        } while (pre != 1);
        cout << "-->" << pre;
        cout << "\n";

    }
    return 0;
}