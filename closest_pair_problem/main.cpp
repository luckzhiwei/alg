#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int partition(vector<int> &numbers, int p, int q) {
    int x = numbers[q];
    int i = p - 1;
    for (int j = p; j < q; j++) {
        if (numbers[j] <= x) {
            swap(numbers[++i], numbers[j]);
        }
    }
    swap(numbers[++i], numbers[q]);
    return i;
}


pair<int, int> findClosetPair(vector<int> &numbers, int p, int q) {
    if (p < q) {
        int pos = partition(numbers, p, q);
        pair<int, int> pairLeft = findClosetPair(numbers, p, pos - 1);
        pair<int, int> pairRight = findClosetPair(numbers, pos, q);

        if (pairLeft.first == pairLeft.second && pairRight.second == pairRight.first) {
            return pair<int, int>(pairLeft.first, pairRight.first);
        } else {
            int d1 = pairLeft.second - pairLeft.first;
            int d2 = pairRight.second - pairRight.first;
            int d3 = pairRight.first - pairLeft.second;

            if (d1 == 0) {
                if (d3 < d2 && d3 != 0) {
                    return pair<int, int>(pairLeft.second, pairRight.first);
                } else {
                    return pairRight;
                }
            }

            if (d2 == 0) {
                if (d3 < d1 && d3 != 0) {
                    return pair<int, int>(pairLeft.second, pairRight.first);
                } else {
                    return pairLeft;
                }
            }

            if (d3 <= d1 && d3 <= d2) {
                return pair<int, int>(pairLeft.second, pairRight.first);
            } else if (d1 <= d3 && d1 <= d2) {
                return pairLeft;
            } else {
                return pairRight;
            }
        }
    } else {
        return pair<int, int>(numbers[p], numbers[p]);
    }
}

int main() {
    vector<int> numbers;
    numbers.push_back(4);
    numbers.push_back(12);
    numbers.push_back(8);
    numbers.push_back(3);
    numbers.push_back(22);
    numbers.push_back(15);
    numbers.push_back(5);
    pair<int, int> pair = findClosetPair(numbers, 0, numbers.size() - 1);
    cout << pair.first << endl;
    cout << pair.second << endl;
    return 0;
}