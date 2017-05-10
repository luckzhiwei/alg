#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combines;

    void combine(vector<int> oneCombine, int n, int number, int k) {
        if (k == 1) {
            for (int i = n; i <= number; i++) {
                vector<int> tmp(oneCombine);
                tmp.push_back(i);
                combines.push_back(tmp);
            }
            return;
        }
        for (int i = n; i < number; i++) {
            vector<int> tmp(oneCombine);
            tmp.push_back(i);
            combine(tmp, i + 1, number, k - 1);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        for (int i = 1; i + k <= n + 1; i++) {
            vector<int> tmp;
            tmp.push_back(i);
            if (k == 1) {
                combines.push_back(tmp);
            } else {
                combine(tmp, i + 1, n, k - 1);
            }
        }
        return this->combines;
    }
};

int main() {
    Solution sl;
    vector<vector<int>> combines = sl.combine(5, 3);
    for (int i = 0; i < combines.size(); i++) {
        for (int j = 0; j < combines[i].size(); j++) {
            cout << combines[i][j];
        }
        cout << "\n";
    }
    return 0;
}