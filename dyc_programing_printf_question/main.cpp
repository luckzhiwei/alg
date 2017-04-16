#include <iostream>
#include <vector>

#define UNREACHABLE -1
using namespace std;

class Node {
public:
    Node() {};

    Node(int m, int n) : sumOfBlankNumber(m), subCapOfLastLine(n) {};
    int sumOfBlankNumber;  // 现在的空格数目
    int subCapOfLastLine; // 最后一行的剩余空格数目
};


int findBestNumberOfBlank(const vector<int> &verbs, int cap) {
    vector<vector<Node>> table;
    int size = verbs.size();
    table.resize(cap + 1);
    for (int i = 0; i < cap + 1; i++) {
        table[i].resize(size + 1, Node(UNREACHABLE, UNREACHABLE));
    }

    for (int i = 1; i < cap + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            if (i < verbs[j - 1]) {
                break;
            }
            if (j == 1) {
                table[i][j].sumOfBlankNumber = 0;
                table[i][j].subCapOfLastLine = i - verbs[j - 1];
            } else {
                // if can not put the verb into this line,new line ,number of blank is sum of before
                if (table[i][j - 1].subCapOfLastLine - 1 < verbs[j - 1]) {
                    table[i][j].sumOfBlankNumber = table[i][j - 1].sumOfBlankNumber + table[i][j - 1].subCapOfLastLine;
                    table[i][j].subCapOfLastLine = i - verbs[j - 1];
                }
                    // if can put the verb in the last line，do not update the data
                else {
                    table[i][j].sumOfBlankNumber = table[i][j - 1].sumOfBlankNumber;
                    table[i][j].subCapOfLastLine = table[i][j - 1].subCapOfLastLine - verbs[j - 1] - 1;
                }
            }
        }
    }
    return table[cap][size].sumOfBlankNumber;
}

int main() {
    vector<int> verbs;
    verbs.push_back(3);
    verbs.push_back(4);
    verbs.push_back(2);
    int cap = 8;
    int numberOfBlank = findBestNumberOfBlank(verbs, cap);
    cout << numberOfBlank << " is the result" << endl;
    return 0;
}