#include <iostream>
#include <vector>
#include <math.h>
#include <cstdio>

using namespace std;

class Node {
public:
    Node() : canVisisted(true) {};
    int w;
    bool canVisisted;
};

class Solution {
public:
    vector<Node> arr1;
    vector<Node> arr2;
    int n;

    Solution(int n) : n(n) {
        arr1.resize(n);
        arr2.resize(n);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            arr1[i].w = x;
        }
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            arr2[i].w = x;
        }

        int num1 = arr1[0].w;
        int num2 = arr2[0].w;

        if (!this->judgeNumisUnVaild(num1, num2, arr1[0].w, arr2[0].w)) {
            cout << "No solution!" << endl;
        }
    }

    bool searchPath(int i, string path) {

        int num1 = arr1[i].w + i;
        int num2 = arr2[i].w + i;

        if (!this->judgeNumisUnVaild(num1, num2, arr1[i].w, arr2[i].w)) {
            return false;
        }

        if (this->judgeNumisVaild(num1, num2, path)) {
            return true;
        }

    }

    bool judgeNumisUnVaild(int n1, int n2, int w1, int w2) {
        if (w1 == 0 && w2 == 0) {
            return false;
        }
        if ((n1 < 0 || n1 >= n) && (n2 < 0 || n2 >= n)) {
            return false;
        }

        if ((n1 < 0 || n1 >= n) && w1 == 0) {
            return false;
        }

        if ((n2 < 0 || n2 >= n) && w2 == 0) {
            return false;
        }
        return true;
    }

    bool judgeNumisVaild(int n1, int n2, string path) {
        if (n1 == n - 1) {
            path = path + 'a';
            cout << path << endl;
            return true;
        } else if (n2 == n - 1) {
            path = path + 'b';
            cout << path << endl;
            return true;
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sl(n);

}