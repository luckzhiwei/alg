#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int getMax(int a, int b) {
    return a > b ? a : b;
}

int main() {
    string str1 = "abfddfba";
    vector<vector<int>> tables;

    set<int> posSet;

    int size = str1.size();
    tables.resize(size);
    for (int i = 0; i < size; i++) {
        tables[i].resize(size, 0);
    }
    for (int i = 0; i < size; i++) {
        tables[i][i] = 1;
    }
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            char start = str1[j];
            char end = str1[j + i];
            if (start == end) {
                tables[j][j + i] = tables[j + 1][j + i - 1] + 2;
            } else {
                tables[j][j + i] = getMax(tables[j + 1][j + i], tables[j][j + i - 1]);
            }
        }
    }

    int posX = 0;
    int posY = size - 1;
    for (; posX != posY && tables[posX][posY] != 0;) {
        if (str1[posX] == str1[posY]) {
            posSet.insert(posX++);
            posSet.insert(posY--);
        } else {
            if (tables[posX + 1][posY] >= tables[posX][posY - 1]) {
                posX++;
            } else {
                posY--;
            }
        }
    }
    posSet.insert(posY);
    for (set<int>::iterator it = posSet.begin(); it != posSet.end(); it++) {
        cout << str1[*it];
    }
    cout << "\n";
    return 0;
}