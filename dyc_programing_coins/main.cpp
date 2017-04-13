#include <iostream>
#include <vector>

using namespace std;

int min(int num0, int num1) {
    if (num0 != 0 && num1 != 0) {
        return num0 < num1 ? num0 : num1;
    } else {
        return num0 == 0 ? num1 : num0;
    }
}

int findBestNumberOfCoins(const vector<int> &coins, int money) {
    vector<vector<int>> tables;
    tables.resize(money + 1);
    int size = coins.size();
    for (int j = 0; j <= money; j++) {
        tables[j].resize(size + 1, 0);
    }
    for (int i = 1; i <= money; i++) {
        for (int j = 1; j <= size; j++) {
            if (coins[j - 1] > i) {
                tables[i][j] = tables[i][j - 1];
            } else {
                tables[i][j] = min(tables[i][j - 1], tables[i - coins[j - 1]][j] + 1);
            }
        }
    }
    int num = tables[money][1];
    for (int i = 2; i <= size; i++) {
        if (tables[money][i] < num && tables[money][i] != 0) {
            num = tables[money][i];
        }
    }
    return num;

}

int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(5);
    coins.push_back(10);
    int num = findBestNumberOfCoins(coins, 15);
    cout << "the best number of coins is" << endl;
    cout << num << endl;
    
    return 0;
}