#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int minCost(vector<vector<int> > &costs) {
    vector<vector<int> > dp(costs.size());
    int N = costs.size();
    int K = costs[0].size();
    for (int i = 0; i < N; i++) {
        dp[i].resize(costs[0].size());
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (i == 0) {
                dp[i][j] = costs[i][j];
            } else {
                int lasti = i - 1;
                int m_cost = 99999999;
                for (int k = 0; k < K; k++) {
                    if (j == k) continue;
                    int thiscost = dp[lasti][k] + costs[i][j];
                    m_cost = min(m_cost, thiscost);
                }
                dp[i][j] = m_cost;
            }
        }
    }
    int m_cost = 99999999;
    for (int k = 0; k < N; k++) {
        m_cost = min(m_cost, dp[N - 1][k]);
    }
    return m_cost;
}


int main() {
    int N, K;
    int cost;
    vector<vector<int> > costs;
    string s;
    istringstream is;

    getline(cin, s);
    is.str(s);
    is >> N >> K;
    for (int i = 0; i < N; i++) {
        vector<int> t;
        getline(cin, s);
        is.clear();
        is.str(s);
        for (int j = 0; j < K; j++) {
            is >> cost;
            t.push_back(cost);
        }
        costs.push_back(t);
    }
    cout << minCost(costs) << endl;
    return 0;
}

