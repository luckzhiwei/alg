#include <iostream>
#include <vector>
#include <ctime>

#define  MAX 3
#define  MAX_VALUE 20
#define  MIN_VALUE -10
using namespace std;

class Node {
public:
    Node() {};

    Node(int index, int value) : bestIndex(index), maxValue(value) {};
    int bestIndex;
    int maxValue;
};


int getMaxValue(const vector<Node> &line, int index, int &bestIndex) {
    int size = line.size();
    int max = line[index].maxValue;
    bestIndex = index;
    if (index < size - 1 && index > 0) {
        int num1 = line[index + 1].maxValue;
        if (max < num1) {
            max = num1;
            bestIndex = index + 1;
        }
        int num2 = line[index - 1].maxValue;
        if (max < num2) {
            max = num2;
            bestIndex = index - 1;
        }
    } else if (index == size - 1) {
        if (max < line[index - 1].maxValue) {
            max = line[index - 1].maxValue;
            bestIndex = index - 1;
        }
    } else if (index == 0) {
        if (max < line[index + 1].maxValue) {
            max = line[index + 1].maxValue;
            bestIndex = index + 1;
        }
    }
    return max;
}


const vector<vector<Node>> findTheMaxValuePath(const vector<vector<int >> &chessborad) {
    vector<vector<Node>> table;
    table.resize(MAX - 1);
    for (int i = 0; i < MAX - 1; i++) {
        table[i].resize(MAX);
    }
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == 0) {
                // 从棋盘的第二层开始自顶向上的求解问题
                table[i][j] = Node(j, chessborad[i + 1][j]);
            } else {
                int bestIndex = j;
                Node node;
                node.maxValue = getMaxValue(table[i - 1], j, bestIndex) + chessborad[i + 1][j];
                node.bestIndex = bestIndex;
                table[i][j] = node;
            }
        }
    }
    return table;
}

int main() {
    srand((unsigned) time(0));
    vector<vector<int>> chessborad;
    chessborad.resize(MAX);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int randomNum = MIN_VALUE + rand() % MAX_VALUE;
            chessborad[i].push_back(randomNum);
        }
    }
    const vector<vector<Node>> ret = findTheMaxValuePath(chessborad);
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << i + 2 << " row" << endl;
            cout << j << " line" << endl;
            cout << ret[i][j].bestIndex << " choose" << endl;
        }
    }
    return 0;
}