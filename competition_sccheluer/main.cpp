#include <iostream>
#include <vector>

#define NUM 16
using namespace std;

void competitionScheuler(vector<vector<int>> &table, int p, int q) {
    if (p + 1 < q) {
        int mid = (p + q) / 2;
        //分解
        competitionScheuler(table, p, mid);
        competitionScheuler(table, mid + 1, q);

        //合并
        int t = (q - p) / 2;
        for (int i = 0; i < t; i++) {
            for (int j = p; j <= mid; j++) {
                table[j][i + t] = table[t + j + 1][i];
                table[t + j + 1][i + t] = table[j][i];
            }
        }
        for (int i = p; i <= q; i = i + 2) {
            table[i][t * 2] = table[i + 1][t];
            table[i + 1][t * 2] = table[i][t];
        }

    } else if (p + 1 == q) {
        table[p][0] = q;
        table[q][0] = p;
    }
}

int main() {
    vector<vector<int>> table;
    table.resize(NUM);
    for (int i = 0; i < NUM; i++) {
        table[i].resize(NUM - 1);
    }
    competitionScheuler(table, 0, NUM - 1);
    for (int i = 0; i < NUM; i++) {
        cout << "the " << i << "th" << endl;
        for (int j = 0; j < NUM - 1; j++) {
            cout << table[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}