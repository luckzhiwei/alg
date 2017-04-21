#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int getMax(int a, int b) {
    return a > b ? a : b;
}

int main() {

    string str1 = "ABCBDAB";
    string str2 = "BDCABA";
    vector<vector<int>> table;
    stack<char> tmp;

    int size1 = str1.size();
    int size2 = str2.size();
    table.resize(size1 + 1);

    for (int i = 0; i < size1 + 1; i++) {
        table[i].resize(size2 + 1, 0);
    }

    for (int i = 1; i < size1 + 1; i++) {
        char b = str1[i - 1];
        for (int j = 1; j < size2 + 1; j++) {
            char a = str2[j - 1];
            if (a == b) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = getMax(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    int indexStr1 = size1;
    int indexStr2 = size2;

    for (; indexStr1 > 0 && indexStr2 > 0;) {
        char a = str1[indexStr1 - 1];
        char b = str2[indexStr2 - 1];
        if (a == b) {
            indexStr1--;
            indexStr2--;
            tmp.push(a);
        } else {
            int len0 = table[indexStr1 - 1][indexStr2];
            int len1 = table[indexStr1][indexStr2 - 1];
            if (len0 >= len1) {
                indexStr1--;
            } else {
                indexStr2--;
            }
        }

    }

    while (!tmp.empty()) {
        cout << tmp.top();
        tmp.pop();
    }
    cout << "\n";
    return 0;
}