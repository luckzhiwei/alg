#include <iostream>
#include <vector>

#define  -oo -22222222
using namespace std;

class Ret {
public:
    Ret() {};

    Ret(int l, int h, int s) : low(l), high(h), sum(s) {};
    int low;
    int high;
    int sum;
};

vector<int> init() {
    vector<int> prices;
    prices.push_back(100);
    prices.push_back(113);
    prices.push_back(110);
    prices.push_back(85);
    prices.push_back(105);
    prices.push_back(102);
    prices.push_back(86);
    prices.push_back(63);
    prices.push_back(81);
    prices.push_back(101);
    prices.push_back(94);
    prices.push_back(106);
    prices.push_back(101);
    prices.push_back(79);
    prices.push_back(94);
    prices.push_back(90);
    prices.push_back(97);
    return prices;
}

Ret findMaxSubArrCross(vector<int> &arr, int low, int mid, int high) {
    int left;
    int right;
    int sumLeftMax = - oo;
    int sumLeft = 0;
    for (int i = mid; i >= low; i--) {
        sumLeft += arr[i];
        if (sumLeft > sumLeftMax) {
            sumLeftMax = sumLeft;
            left = i;
        }
    }
    int sumRightMax = - oo;
    int sumRight = 0;
    for (int i = mid + 1; i <= high; i++) {
        sumRight += arr[i];
        if (sumRight > sumRightMax) {
            sumRightMax = sumRight;
            right = i;
        }
    }
    return Ret(left, right, sumLeftMax + sumRightMax);

}

Ret findMaxSubArr(vector<int> &arr, int low, int high) {
    if (low == high) {
        return Ret(low, high, arr[low]);
    } else {
        int mid = (low + high) / 2;
        Ret letfRet = findMaxSubArr(arr, low, mid);
        Ret rightRet = findMaxSubArr(arr, mid + 1, high);
        Ret crossRet = findMaxSubArrCross(arr, low, mid, high);
        if (letfRet.sum > rightRet.sum && letfRet.sum > crossRet.sum) {
            return letfRet;
        } else if (rightRet.sum > letfRet.sum && rightRet.sum > crossRet.sum) {
            return rightRet;
        } else {
            return crossRet;
        }
    }
}

int main() {

    vector<int> prices = init();
    vector<int> arr;
    for (int i = 0; i < prices.size() - 1; i++) {
        arr.push_back(prices[i + 1] - prices[i]);
    }
    return 0;
}