#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define  NIL -1
#define  oo 65535

using namespace std;

class Node;

class Egde {
public:
    Egde(int start, int end, int w) : mWeight(w), mStart(start), mEnd(end) {};
    int mWeight;
    int mStart;
    int mEnd;
};

class Node {
public:
    Node() {};

    Node(int num) : number(num), pre(NIL) {};
    int number;
    int pre;
};


vector<Node> points;
vector<Egde> egdes;
vector<Egde> tree;

void init(const vector<string> &info, int nodesCount) {
    for (int i = 1; i <= nodesCount; i++) {
        points.push_back(Node(i));
    }
    for (auto it = info.begin(); it != info.end(); it++) {
        int start = it->at(0) - 0x30;
        int end = it->at(2) - 0x30;
        int value = -1;
        if (it->length() == 5) {
            value = it->at(4) - 0x30;
        } else {
            value = (it->at(4) - 0x30) * 10 + (it->at(5) - 0x30);
        }
        egdes.push_back(Egde(start, end, value));
    }
}

int getEnd(vector<int> &vends, int i) {
    while (vends[i] != 0) {
        i = vends[i];
    }
    return i;
}


void kruskal() {
    set<int> vSet;
    sort(egdes.begin(), egdes.end(), [](const Egde &e1, const Egde &e2) {
        return e1.mWeight < e2.mWeight;
    });
    vector<int> vends;
    vends.resize(points.size() + 1, 0);

    for (auto it = egdes.begin(); it != egdes.end(); it++) {
        int start = it->mStart;
        int end = it->mEnd;
        int m = getEnd(vends, start);
        int n = getEnd(vends, end);
        if (m != n) {
            vends[m] = n;
            tree.push_back(*it);
        }
    }
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
    kruskal();
    return 0;
}

